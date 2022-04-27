class Solution {
public:
    
    void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &a){
        
        visited[u] = true;
        a.push_back(u);
        
        for(int v : adj[u]){
            
            if(!visited[v]){
                
                dfs(v, adj, visited, a);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n = s.size();
        
        vector<vector<int>> adj(n);
        
        for(vector<int> &v : pairs){
            
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        
        vector<bool> visited(n, false);
        
        for(int i = 0; i < n; i++){
            
            if(visited[i] or adj[i].size() == 0)
                continue;
            
            vector<int> a;
            dfs(i, adj, visited, a);
            
            vector<char> set;
            
            for(int idx : a)
                set.push_back(s[idx]);
            
            sort(begin(set), end(set));
            sort(begin(a), end(a));
            
    
            int j = 0;
            for(int idx : a)
                s[idx] = set[j++];
            
        }
        
        return s;
    }
};