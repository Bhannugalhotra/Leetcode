class Solution 
{
    vector<vector<string>> ans;
    
    
public:
    
    bool check_col(int col, int row,  vector<vector<bool>> &mat){
        
        for(int i = 0; i < row; i++)
            if(mat[i][col])
                return false;
        
        return true;
    }
    
    bool check_dia(int col, int row,  vector<vector<bool>> &mat){
        
        for(int i = row, j = col; i >= 0 and j >= 0; i--, j--){
            if(mat[i][j])
                return false;
        }
        
        for(int i = row, j = col; i >= 0 and j < mat[0].size(); i--, j++){
            if(mat[i][j])
                return false;
        }
        
        return true;
    }
    vector<int> construct_candidates(int n, int row, vector<vector<bool>> &mat){
        
        vector<int> candidates;
        
        for(int i = 0; i < n; i++){
            
            if(check_col(i, row, mat) and check_dia(i, row, mat))
                candidates.push_back(i);
        }
        
        return candidates;
    }
    void backtrack(int n, int row,vector<vector<bool>> &mat){
        
        if(row == n){
            
            vector<string> curr;
            
            for(vector<bool> &v : mat){
                string s;
                
                for(bool b : v){
                    if(b)
                        s += 'Q';
                    
                    else s += '.';
                }
                
                curr.push_back(s);
            }
            
            ans.push_back(curr);
            
            return;
        }
        
        vector<int> candidates = construct_candidates(n, row, mat);
        
        for(int col : candidates){
            
            mat[row][col] = true;
            
            backtrack(n, row+1, mat);
            
            mat[row][col] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        if(n == 1)
            return {{"Q"}};
        
        if(n <= 3)
            return {};
        
        vector<vector<bool>> mat(n, vector<bool>(n));
        
        backtrack(n, 0, mat);
        
        return ans;
    }
};