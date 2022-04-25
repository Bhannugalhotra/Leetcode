
class Point{
    
    public:
    
    int x,y;
    
    Point(int a = -1, int b = -1) : x(a), y(b) {};
    
    bool is_valid(int n, int m){
        return x >= 0 and y >= 0 and x < n and y < m;
    }

    Point operator+(const Point that){
        
        Point p (this -> x + that.x, this -> y + that.y);
        
        return p;
    }
};

vector<Point> dir = {{1,0}, {-1,0}, {0,-1}, {0,1}};



class Solution 
{
    int n, m;
public:
    
    void dfs(vector<vector<char>> &grid, Point curr){
        
        // visit curr position
        grid[curr.x][curr.y] = 'v';
        
        for(Point _dir : dir){
            
            Point p = curr + _dir;
            
            if(p.is_valid(n,m) and grid[p.x][p.y] == '1'){
                dfs(grid,p);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            
            for(int j = 0; j < m; j++){
                
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid,Point(i,j));
                }
            }
        }
        
        return ans;
    }
};