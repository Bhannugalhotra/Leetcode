class Solution {
public:
    int countVowelPermutation(int n) {
        
        if(n == 1)
            return 5;
        
        int mod = 1e9 + 7;
        vector<vector<long long>> dp(2, vector<long long>(5,0));
        
        for(int i = 0; i < 5; i++)
            dp[1][i] = 1;
        
        int a = 0;
        int e = 1;
        int i = 2;
        int o = 3;
        int u = 4;
        
        for(int len = 2; len <= n; len++){
            
            int curr = len % 2;
            int prev = 1 - curr;
            
            dp[curr][a] = (dp[prev][e] + dp[prev][i] + dp[prev][u]) % mod;
                
            dp[curr][e] = (dp[prev][a] + dp[prev][i]) % mod;
                
            dp[curr][i] = (dp[prev][e] + dp[prev][o]) % mod;
                
            dp[curr][o] = (dp[prev][i]) % mod;
                
            dp[curr][u] = (dp[prev][i] + dp[prev][o]) % mod;
        }
        
        long long ans = 0;
        
        for(int j = 0; j < 5; j++)
            ans += dp[n%2][j];
        
        return ans % mod;
    }
};