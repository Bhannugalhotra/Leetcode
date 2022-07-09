class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        int n = nums.size();
        deque<int> dq;
        vector<int> sum(n);
        sum[0] = nums[0];
        
        dq.push_back(0);
        
        for(int i = 1; i < nums.size(); i++){
            
            while(!dq.empty() and dq.front() < i - k)
                dq.pop_front();
            
            sum[i] = sum[dq.front()] + nums[i];
            
            while(!dq.empty() and sum[dq.back()] <= sum[i])
                dq.pop_back();
            
            dq.push_back(i);
        }
        
        return sum.back();
    }
};