class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target)
    {
        int n = mat.size();
        if(n == 0) return 0;
        int m = mat[0].size();
        if(m == 0) return 0;
        
        for(int r = n-1, c = 0; r >= 0 && c < m;)
        {
            if(mat[r][c] == target)
                return true;
            
            if(mat[r][c] > target)
                r--;
            
            else c++;
        }
        
        return false;
    }
};