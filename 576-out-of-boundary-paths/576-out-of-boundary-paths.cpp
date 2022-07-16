
vector<pair<int,int>> dir {{-1,0}, {0,-1}, {1,0}, {0,1}};

class Solution 
{
    int mod = 1e9 + 7;
    
    vector<vector<vector<int>>> memo;
    
public:
    
    bool isOutOfBoundary(int x, int y,int m, int n){
        
        return x < 0 or x >= m or y < 0 or y >= n;
    }
    
    int dfs(int x, int y, int m, int n, int maxMove){
        
        if(isOutOfBoundary(x,y,m,n))
            return 1;
        
        if(maxMove <= 0)
            return 0;
        
        if(memo[x][y][maxMove] != -1)
            return memo[x][y][maxMove];
        
        
        int ans = 0;
        
        for(pair<int,int> _dir : dir){
            
            pair<int,int> p;
            
            p.first = x + _dir.first;
            p.second = y + _dir.second;
            
            ans += dfs(p.first, p.second, m, n, maxMove - 1);
            ans = ans % mod;
        }
        
        return memo[x][y][maxMove] = ans;
        
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memo = vector<vector<vector<int>>>(m , vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        
        
        return dfs(startRow, startColumn, m, n, maxMove);
        
        
    }
};