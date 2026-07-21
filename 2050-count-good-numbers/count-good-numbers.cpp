class Solution {
private:
    long long power(long long x, long long n) {
        const long long MOD = 1e9 + 7;
        long long ans = 1;
        while (n > 0) {
            if (n & 1)
                ans = (ans * x) % MOD;
                x = (x * x) % MOD;
                n >>= 1;
            }

            return ans;
        }

public:
    int countGoodNumbers(long long n) {
        const long long MOD = 1e9 + 7;

        long long int even=(n + 1)/2;
        long int odd=n/2;

        long long ans=(power(4,odd) *power(5,even) )%MOD;

        return ans;
    }
};