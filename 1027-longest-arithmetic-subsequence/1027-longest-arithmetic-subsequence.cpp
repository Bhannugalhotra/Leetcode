class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        int offset = 500;
        vector<vector<int>> dp(n+1,vector<int>(1001));
        int ans = 1;
        for(int i = 1;i < n; i++){
            
            for(int j = i-1; j >= 0; j--){
                
                int diff = nums[i] - nums[j];
                
                if(dp[j][diff + offset] > 0){
                    dp[i][diff + offset] = max(dp[i][diff + offset], dp[j][diff + offset] + 1);
                }
                
                else{
                    dp[i][diff + offset] = max(dp[i][diff + offset],2);
                }
                
                ans = max(dp[i][diff + offset], ans);
            }
        }
        
        return ans;
        
    }
};