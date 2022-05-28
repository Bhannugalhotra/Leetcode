class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int xor_ = 0;
        
        for(int num : nums)
            xor_ ^= num;
        
        for(int i = 1; i <= nums.size(); i++)
            xor_ ^= i;
        
        return xor_;
        
    }
};