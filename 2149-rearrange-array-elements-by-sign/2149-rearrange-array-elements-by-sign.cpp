class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> ans(nums.size());
        
        int posIdx = 0;
        int negIdx = 1;
        
        for(int num : nums){
            
            if(num > 0){
                ans[posIdx] = num;
                posIdx += 2;
            }
            
            else{
                ans[negIdx] = num;
                negIdx += 2;
            }
        }
        
        return ans;
    }
};