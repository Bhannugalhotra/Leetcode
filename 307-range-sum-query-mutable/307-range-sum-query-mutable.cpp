class NumArray {
    vector<int> b;
    int len;
    vector<int> nums;
    
public:
    NumArray(vector<int>& nums) {
        
        this -> nums = nums;
        
        int x = sqrt(nums.size());
        
        len = ceil(nums.size() / x);
        
        b = vector<int>(len+1);
        
        for(int i = 0; i < nums.size(); i++){
            b[i/len] += nums[i];
        }
    }
    
    void update(int index, int val) {
        
        int blockNum = index / len;
        
        b[blockNum] = b[blockNum] - nums[index] + val;
        
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        
        int startBlock = left / len;
        int endBlock = right / len;
        
        int sum = 0;
        
        if(startBlock == endBlock){
            
            for(int i = left; i <= right; i++)
                sum += nums[i];
            
            return sum;
        }
        for(int k = left ; k <= (startBlock+1)*len - 1; k++)
            sum += nums[k];
        
        for(int k = startBlock+1; k < endBlock; k++)
            sum += b[k];
        
        for(int k = endBlock*len; k <= right; k++)
            sum += nums[k];
        
        return sum;
            
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */