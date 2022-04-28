vector<pair<int,int>> point = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};

class Solution
{
    int n, m;
    
public:
    
    bool dfs(int x, int y, vector<vector<int>>& H, int k, vector<vector<bool>> &visited)
    {
        if(x == n-1 and y == m-1)
            return true;
        
        int ans = false;
        for(int i = 0; i < 4; i++)
        {
            int r = x + point[i].first;
            int c = y + point[i].second;
            
            if(r<n and r>=0 and c<m and c>=0 and !visited[r][c] and abs(H[r][c] - H[x][y]) <= k)
            {
                visited[r][c] = true;
                
                ans = ans or dfs(r, c, H, k, visited);
            }
        }
        
        return ans;
    }
    bool is_possible(vector<vector<int>>& H,int k)
    {
        vector<vector<bool>> visited(n, vector<bool>(m));
        
        return dfs(0,0, H, k, visited);
    }
    int minimumEffortPath(vector<vector<int>>& H)
    {
        n = H.size();
        if(n == 0) return 0;
        
        m = H[0].size();
        if(m == 0) return 0;
        
        int l = 0, r = 1e6;
        
        while(l < r)
        {
            int mid = l + ((r - l) / 2);
            
            if(is_possible(H,mid))
                r = mid;
            
            else l = mid + 1;
        }
        
        return l;
    }
};