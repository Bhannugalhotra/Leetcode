class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(n == 0)
            return 0;
        
        int m = grid[0].size();
        if(m == 0)
            return 0;
        
        if(grid[0][0] == 1 or grid[n-1][m-1] == 1)
            return 0;
        
        grid[0][0] = 1;
        
        for(int i = 1; i < n; i++){
            if(grid[i][0] == 1)
                grid[i][0] = -1;
            
            else
                grid[i][0] = grid[i-1][0];
        }
        
        for(int j = 1; j < m; j++){
            if(grid[0][j] == 1)
                grid[0][j] = -1;
            
            else
                grid[0][j] = grid[0][j-1];
        }
        
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++)
            {
                if(grid[i][j] == 1){
                    grid[i][j] = -1;
                    continue;
                }
                
                if(grid[i-1][j] != -1)
                    grid[i][j] += grid[i-1][j];
                
                if(grid[i][j-1] != -1)
                    grid[i][j] += grid[i][j-1];
            }
        
        return grid[n-1][m-1];
    }
};