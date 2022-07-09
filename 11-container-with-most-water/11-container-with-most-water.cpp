class Solution {
public:
    int maxArea(vector<int>& a)
    {
        int max_area = 0;
        
        for(int l = 0,r = a.size()-1; l < r;)
        {
            int curr_area = min(a[l],a[r]) * (r - l);
           
            max_area = max(max_area, curr_area);
            
            if(a[l] < a[r])
                l++;
            
            else r--;
        }
        
        return max_area;
    }
};