class Solution {
public:
    int combinationSum4(vector<int>& a, int target) {
        
        int mod = (1L << 31) - 1;
        
        vector<long long> dp(target + 1);
        dp[0] = 1;
        
        for(int t = 1; t <= target; t++){
            
            for(int i = 0; i < a.size(); i++){
                if(a[i] <= t and dp[t - a[i]] > 0)
                    dp[t] = (dp[t] + dp[t - a[i]]) % mod;
            }
        }
        
        return dp[target];
    }
};