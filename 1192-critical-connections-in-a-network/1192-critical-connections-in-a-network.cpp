class Solution 
{
    vector<int> dfs_num;
    int time = 0;
    
    vector<vector<int>> adj;
    vector<vector<int>> ans;
    
public:
    
    int dfs(int root, int parent)
    {
        dfs_num[root] = time++;
        
        int back_num = dfs_num[root];
        
        for(int v : adj[root]){
            
            if(dfs_num[v] == -1){
                
                back_num = min(back_num, dfs(v, root));
            }
            
            else if(v != parent){
                back_num = min(back_num, dfs_num[v]);
            }
        }
        
        if(parent != -1 and back_num == dfs_num[root]){
            
            ans.push_back(vector<int>{parent, root});
        }
        
        return back_num;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        adj = vector<vector<int>>(n);
        dfs_num = vector<int>(n, -1);
        
        for(vector<int> &v : connections){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        // for(int i = 0; i < n; i++)
        //     if(dfs_num[i] == -1)
        //         dfs(i, -1);
        
        // graph is connected so 
        dfs(0,-1);
        
        return ans;
    }
};