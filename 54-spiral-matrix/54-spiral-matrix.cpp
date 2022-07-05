class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> ans;
        
        
        int top_row = 0, bottom_row = n-1;
        int left_col = 0, right_col = m-1;
        
        while(true){
            
            for(int c = left_col; c <= right_col; c++)
                ans.push_back(mat[top_row][c]);
            
            top_row++;
            
            if(top_row > bottom_row)
                break;
            
            for(int r = top_row; r <= bottom_row; r++)
                ans.push_back(mat[r][right_col]);
            
            right_col--;
            
            if(left_col > right_col)
                break;
            
            for(int c = right_col; c >= left_col; c--)
                ans.push_back(mat[bottom_row][c]);
            
            bottom_row--;
            
            if(top_row > bottom_row)
                break;
            
            
            for(int r = bottom_row; r >= top_row; r--)
                ans.push_back(mat[r][left_col]);
            
            left_col++;
            
            if(left_col > right_col)
                break;
        }
        
        return ans;
    }
};