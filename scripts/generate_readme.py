#!/usr/bin/env python3
"""
Scans every problem folder in the repo root, reads the LeetHub-generated
README.md inside each one (title / difficulty / link) plus whatever solution
file sits next to it, and rebuilds the top-level README.md + shields.io
badge JSON files from scratch.

Runs as a GitHub Action on every push, so the README always reflects
exactly what's in the repo -- nobody has to edit counts by hand.
"""

import json
import os
import re
from datetime import datetime, timezone

# ---- configure these two for your setup -----------------------------------
LEETCODE_USERNAME = "Abhishek101006"
GITHUB_USERNAME = "Abhishek1010006"
REPO_NAME = "DSA"
# -----------------------------------------------------------------------------

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
IGNORE_DIRS = {".git", ".github", "scripts", "node_modules", ".vscode"}

LANG_MAP = {
    "cpp": "C++", "cc": "C++", "cxx": "C++",
    "py": "Python", "java": "Java", "js": "JavaScript",
    "ts": "TypeScript", "go": "Go", "rs": "Rust", "c": "C",
    "cs": "C#", "rb": "Ruby", "kt": "Kotlin", "swift": "Swift",
}

DIFF_ORDER = {"Easy": 0, "Medium": 1, "Hard": 2}
DIFF_COLOR = {"Easy": "2ea44f", "Medium": "e2a33a", "Hard": "e2494a"}
DIFF_BADGE_COLOR = {"Easy": "brightgreen", "Medium": "orange", "Hard": "red"}


def parse_folder(name):
    """'1056-capacity-to-ship-packages-within-d-days' -> (1056, 'capacity-...')"""
    m = re.match(r"^(\d+)-(.+)$", name)
    if not m:
        return None
    return int(m.group(1)), m.group(2)


def parse_problem_readme(path):
    with open(path, encoding="utf-8", errors="ignore") as f:
        content = f.read()
    title_m = re.search(r'<h2><a href="([^"]+)">([^<]+)</a></h2>', content)
    diff_m = re.search(r"Difficulty-([A-Za-z]+)-", content)
    if not title_m:
        return None
    return {
        "link": title_m.group(1),
        "title": title_m.group(2),
        "difficulty": diff_m.group(1) if diff_m else "Unknown",
    }


def collect_problems():
    problems = []
    for entry in sorted(os.listdir(ROOT)):
        full = os.path.join(ROOT, entry)
        if not os.path.isdir(full) or entry in IGNORE_DIRS or entry.startswith("."):
            continue
        parsed = parse_folder(entry)
        if not parsed:
            continue
        num, slug = parsed

        readme_path = os.path.join(full, "README.md")
        meta = parse_problem_readme(readme_path) if os.path.exists(readme_path) else None
        if not meta:
            meta = {
                "link": f"https://leetcode.com/problems/{slug}",
                "title": slug.replace("-", " ").title(),
                "difficulty": "Unknown",
            }

        # find the solution file (anything that isn't README.md)
        sol_file, lang = None, "Unknown"
        for f in sorted(os.listdir(full)):
            if f == "README.md":
                continue
            sol_file = f
            ext = f.rsplit(".", 1)[-1].lower() if "." in f else ""
            lang = LANG_MAP.get(ext, ext.upper() or "Unknown")
            break

        problems.append({
            "num": num,
            "folder": entry,
            "title": meta["title"],
            "difficulty": meta["difficulty"],
            "link": meta["link"],
            "language": lang,
            "sol_file": sol_file,
        })

    problems.sort(key=lambda p: p["num"])
    return problems


def build_badges_json(problems):
    counts = {"Easy": 0, "Medium": 0, "Hard": 0}
    for p in problems:
        if p["difficulty"] in counts:
            counts[p["difficulty"]] += 1
    total = len(problems)

    os.makedirs(os.path.join(ROOT, ".github", "badges"), exist_ok=True)
    badge_defs = {
        "total.json": {"label": "Solved", "message": str(total), "color": "2f81f7"},
        "easy.json": {"label": "Easy", "message": str(counts["Easy"]), "color": DIFF_COLOR["Easy"]},
        "medium.json": {"label": "Medium", "message": str(counts["Medium"]), "color": DIFF_COLOR["Medium"]},
        "hard.json": {"label": "Hard", "message": str(counts["Hard"]), "color": DIFF_COLOR["Hard"]},
    }
    for filename, payload in badge_defs.items():
        payload["schemaVersion"] = 1
        with open(os.path.join(ROOT, ".github", "badges", filename), "w") as f:
            json.dump(payload, f, indent=2)
    return total, counts


def progress_bar(easy, medium, hard, total, width=30):
    if total == 0:
        return "`" + ("░" * width) + "`"
    e = round(width * easy / total)
    m = round(width * medium / total)
    h = max(width - e - m, 0)
    return "🟩" * e + "🟨" * m + "🟥" * h


def language_breakdown(problems):
    langs = {}
    for p in problems:
        langs[p["language"]] = langs.get(p["language"], 0) + 1
    return sorted(langs.items(), key=lambda x: -x[1])


def build_table(problems):
    rows = [
        "| # | Problem | Difficulty | Language | Solution |",
        "|---|---------|:----------:|:--------:|:--------:|",
    ]
    for p in problems:
        diff_badge = f"![](https://img.shields.io/badge/-{p['difficulty']}-{DIFF_BADGE_COLOR.get(p['difficulty'], 'lightgrey')})"
        sol_link = f"[`{p['sol_file']}`](./{p['folder']}/{p['sol_file']})" if p["sol_file"] else "—"
        rows.append(
            f"| {p['num']} | [{p['title']}]({p['link']}) | {diff_badge} | {p['language']} | {sol_link} |"
        )
    return "\n".join(rows)


def build_readme(problems):
    total, counts = build_badges_json(problems)
    bar = progress_bar(counts["Easy"], counts["Medium"], counts["Hard"], total)
    langs = language_breakdown(problems)
    lang_line = " · ".join(f"**{n}** {lang}" for lang, n in langs) if langs else "—"
    now = datetime.now(timezone.utc).strftime("%d %b %Y, %H:%M UTC")

    badge_base = f"https://raw.githubusercontent.com/{GITHUB_USERNAME}/{REPO_NAME}/main/.github/badges"
    endpoint_base = "https://img.shields.io/endpoint"

    readme = f"""<div align="center">

# 🧩 {GITHUB_USERNAME}'s DSA & LeetCode Vault

Structured, dynamically-tracked solutions to Data Structures & Algorithms problems.
Every push auto-rebuilds the stats and table below — nothing here is typed in by hand.

![Solved](https://img.shields.io/endpoint?url={badge_base}/total.json)
![Easy](https://img.shields.io/endpoint?url={badge_base}/easy.json)
![Medium](https://img.shields.io/endpoint?url={badge_base}/medium.json)
![Hard](https://img.shields.io/endpoint?url={badge_base}/hard.json)
[![LeetCode](https://img.shields.io/badge/LeetCode-{LEETCODE_USERNAME}-FFA116?logo=leetcode&logoColor=white)](https://leetcode.com/{LEETCODE_USERNAME}/)

</div>

<br>

<div align="center">

### 📊 Live LeetCode Stats

<img src="https://leetcard.jacoblin.cool/{LEETCODE_USERNAME}?theme=dark&font=Inter&ext=heatmap" alt="{LEETCODE_USERNAME}'s LeetCode stats" />

*(pulled live from LeetCode's public API — always current, no manual updates)*

</div>

<br>

## 📈 Progress

**{total} problems solved** · {counts['Easy']} Easy · {counts['Medium']} Medium · {counts['Hard']} Hard

{bar}

**Languages used:** {lang_line}

<br>

## 🗂️ Solutions

{build_table(problems)}

<br>

## ⚙️ How this README stays up to date

This repo follows a simple pattern:

1. Each solved problem lives in its own folder: `NNNN-problem-slug/` (this matches LeetHub's auto-sync format, so if you use the [LeetHub](https://github.com/arunbhardwaj/LeetHub-2.0) browser extension, new solves land here automatically).
2. `scripts/generate_readme.py` walks every folder, reads the problem's `README.md` for its title/difficulty/link, detects the solution file's language from its extension, and rebuilds **this** README plus the badge JSON files in `.github/badges/`.
3. `.github/workflows/update-readme.yml` runs that script automatically on every push to `main`, commits the regenerated README, and that's it — the counts, table, and progress bar above always match what's actually in the repo.

To trigger a manual refresh: `python scripts/generate_readme.py` from the repo root, then commit.

<br>

<div align="center">

*Last auto-generated: {now}*

</div>
"""
    return readme


def main():
    problems = collect_problems()
    readme = build_readme(problems)
    with open(os.path.join(ROOT, "README.md"), "w", encoding="utf-8") as f:
        f.write(readme)
    print(f"README.md regenerated with {len(problems)} problems.")


if __name__ == "__main__":
    main()
