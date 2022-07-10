class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        if(nums.size() <= 1)
            return ;
        
        vector<int> aux(nums);
        
        sort(begin(aux), end(aux));
        
        int l = aux.size()/2;
        
        if(aux.size() % 2 == 0)
            l--;
        
        int r = aux.size() - 1;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(i & 1){
                nums[i] = aux[r--];
            }
            
            else nums[i] = aux[l--];
        }
        
    }
};