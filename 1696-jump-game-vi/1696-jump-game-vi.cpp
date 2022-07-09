class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
//         int n = nums.size();
//         deque<int> dq;
//         vector<int> sum(n);
//         sum[0] = nums[0];
        
//         dq.push_back(0);
        
//         for(int i = 1; i < nums.size(); i++){
            
//             while(!dq.empty() and dq.front() < i - k)
//                 dq.pop_front();
            
//             sum[i] = sum[dq.front()] + nums[i];
            
//             while(!dq.empty() and sum[dq.back()] <= sum[i])
//                 dq.pop_back();
            
//             dq.push_back(i);
//         }
        
//         return sum.back();
        
        // solution 2 
        
        
        int n = nums.size();
        multiset<int> mp;
        vector<int> dp(n);
        
        dp[0] = nums[0];
        mp.insert(dp[0]);
        
        for(int i = 1; i < n; i++){
            
            dp[i] = nums[i] + *mp.rbegin();
            
            if(i >= k)
                mp.erase(mp.find(dp[i-k]));
            
            mp.insert(dp[i]);
        }
        
        
        return dp[n-1];
    }
};