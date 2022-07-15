class Point
{
public:
	int x, y;
	Point(int a = -1, int b = -1) : x(a), y(b) {};

	bool is_valid(int n, int m, int a = 0, int b = 0)
	{
		return x >= a and x < n and y >= b and y < m; 
	}

	bool is_leveler()
	{
	    return x == -1 and y == -1; 
	}

    Point operator+ (const Point &p1){
        
        Point p;
        p.x = this -> x + p1.x;
        p.y = this -> y + p1.y;
        return p;
    }
};

vector<Point> _dir = {{0,1},{1,0},{-1,0},{0,-1}};

class Solution {
public:
    
    int dfs(Point curr, vector<vector<int>> &grid, int n, int m, vector<vector<bool>> &visited){
    
        int ans = 1;
        
        for(Point dir : _dir){
            Point p = dir + curr;

            if(p.is_valid(n,m) and grid[p.x][p.y] == 1 and !visited[p.x][p.y]){
                visited[p.x][p.y] = true;
                ans += dfs(p, grid, n,m,visited);
            }
        }
        
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(n == 0)
            return 0;
        
        int m = grid[0].size();
        if(m == 0)
            return 0;
        
        vector<vector<bool>> visited(n, vector<bool>(m));
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(grid[i][j] == 1 and !visited[i][j]){
                    
                    visited[i][j] = true;
                    
                    ans = max(ans,dfs(Point(i,j), grid, n, m, visited));
                }
            }
        }
        
        return ans;
    }
};