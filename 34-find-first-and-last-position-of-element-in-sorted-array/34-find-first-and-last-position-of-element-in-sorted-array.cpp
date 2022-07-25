class Solution {
public:
    
    int lower_bound(vector<int> &a, int key){
        
        int l = 0;
        int r = a.size() - 1;
        
        while(l < r){
            
            int mid = l + ((r - l) >> 1);
            
            if(a[mid] >= key){
                r = mid;
            }
            
            else l = mid + 1;
        }
        
        return l;
    }
    
    int upper_bound(vector<int> &a , int key){
        
        int l = 0;
        int r = a.size() - 1;
        
        while(l < r){
            
            int mid = l + (( r - l + 1) >> 1);
            
            if(a[mid] <= key){
                l = mid;
            }
            
            else r = mid - 1;
        }
        
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(nums.size() == 0)
            return {-1, -1};
        
        vector<int> ans (2);
        ans[0] = lower_bound(nums, target);
        
        if(nums[ans[0]] != target)
            return {-1, -1};
        
        ans[1] = upper_bound(nums, target);
        
        return ans;
    }
};