class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        int ans = 0;
        
        unordered_map<int,int> map;
        
        for(int num : nums){
            
            if(map[k - num] > 0){
                ans++;
                map[k - num]--;
            }
            
            else if(num < k){
                map[num]++;
            }
        }
        
        return ans;
    }
};