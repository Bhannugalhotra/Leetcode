class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> maxInRow(n);
        vector<int> maxInCol(m);
        
        for(int i = 0; i < n;i++){
            maxInRow[i] = *max_element(begin(grid[i]), end(grid[i]));
        }
        
        for(int j = 0; j < m; j++){
            
            int maxElem = 0;
            
            for(int i = 0;i < n; i++){
                maxElem = max(maxElem, grid[i][j]);
            }
            
            maxInCol[j] = maxElem;
        }
        
        int ans = 0;
        
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                
                ans += max(0, min(maxInRow[i], maxInCol[j]) - grid[i][j]);
            }
        }
        
        return ans;
    }
};