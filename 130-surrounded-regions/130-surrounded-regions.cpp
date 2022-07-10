
vector<pair<int,int>> dir = {{-1,0}, {0,-1}, {1,0}, {0,1}};

class Solution {
public:
    
    
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        queue<pair<int,int>> q;
        
        for(int i = 0; i < n; i++){
            
            if(board[i][0] == 'O')
                q.push({i,0}), visited[i][0] = true;
            
            if(board[i][m-1] == 'O')
                q.push({i, m-1}),  visited[i][m-1] = true;
        }
        
        for(int j = 1; j < m-1; j++){
            
            if(board[0][j] == 'O')
                q.push({0,j}),  visited[0][j] = true;
            
            if(board[n-1][j] == 'O')
                q.push({n-1,j}),  visited[n-1][j] = true;
        }
        
        
        
        while(!q.empty()){
            
            pair<int,int> curr = q.front(); q.pop();
            
            for(pair<int,int> _dir : dir){
                
                pair<int,int> p;
                p.first = _dir.first + curr.first;
                p.second = _dir.second + curr.second;
                
                if(p.first >= n or p.first < 0 or p.second >= m or p.second < 0)
                    continue;
                
                if(!visited[p.first][p.second] and board[p.first][p.second] == 'O'){
                    
                    q.push({p.first, p.second});
                    visited[p.first][p.second] = true;
                }
            }
        }
        

        for(int i = 0 ; i < n ; i++){
            
            for(int j = 0 ; j < m; j++){
                
                if(!visited[i][j])
                    board[i][j] = 'X';
            }
        }
        
        
    }
};