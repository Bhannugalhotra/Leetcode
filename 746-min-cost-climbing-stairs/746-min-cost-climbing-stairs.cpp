class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        if(n <= 1)
            return 0;
        
        if(n == 2)
            return min(cost[0], cost[1]);
        
        vector<int> dp(n+1);
        
        dp[0] = 0;
        dp[1] = 0;
        
        for(int i = 2; i <= n; i++){
            
            int a = dp[i-1] + cost[i-1];
            int b = dp[i-2] + cost[i-2];
            
            dp[i] = min(a,b);
        }
        
        return dp[n];
        
    }
};