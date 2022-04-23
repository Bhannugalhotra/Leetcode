class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int smallerCount = 0;
        int sameCount = 0;
        
        for(int num : nums){
            
            if(num < pivot)
                smallerCount++;
            
            else if(num == pivot)
                sameCount++;
        }
        
        int smallIdx = 0;
        int sameIdx = smallerCount;
        int highIdx = sameIdx + sameCount;
        
        vector<int> ans(nums.size());
        
        for(int num : nums){
            
            if(num < pivot)
                ans[smallIdx++] = num;
            
            else if(num == pivot)
                ans[sameIdx++] = num;
            
            else ans[highIdx++] = num;
        }
        
        return ans;
        
       
    }
};