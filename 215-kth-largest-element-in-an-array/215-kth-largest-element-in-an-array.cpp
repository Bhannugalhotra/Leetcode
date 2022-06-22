class Solution {
public:
    
    
    int kthSmallest(vector<int> &a, int l, int r, int k) {
        
         if(l >= r)
            return a[r];
    
        int i = l-1;
        int j = r;
        
        int rnd_idx = rand() % (r - l + 1);
        
        swap(a[l + rnd_idx], a[r]);
        
        int v = a[r];
        
        
        while(true){
            
            while(i < r and a[++i] < v);
            
            while(j > l and a[--j] > v);
            
            if(i >= j)
                break;
            
            swap(a[i], a[j]);
        }
        
        swap(a[i], a[r]);
        
        if(i == k)
            return a[k];
        
        else if(i > k)
            return kthSmallest(a, l, i-1, k);
    
        return kthSmallest(a, i+1, r, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        int idx = nums.size() - k;
        
        return  kthSmallest(nums, 0, nums.size()-1, idx);
     
    }
};