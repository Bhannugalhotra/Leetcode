class Solution
{
    vector<bool> visited;
    vector<bool> colour;
public:
    
    bool bfs(int u, vector<vector<int>> &adj)
    {
        queue<int> q;
        
        q.push(u);
        colour[u] = 1;
        
        while(!q.empty())
        {
            u = q.front(); q.pop();
            
            for(int v : adj[u])
            {
                if(!visited[v])
                {
                    visited[v] = true;
                    colour[v] = 1 - colour[u];
                    
                    q.push(v);
                }
                
                else if(colour[u] == colour[v])
                    return false;
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph)
    {
        int V = graph.size();
        
        if(V == 0) return true;
        
        colour = vector<bool>(V);
        visited = vector<bool>(V);
        
        bool ans = true;
        
        for(int i = 0; i < V; i++)
            if(!visited[i])
                ans = ans and bfs(i, graph);
        
        return ans; 
    }
};