class Solution 
{
    unordered_map<string, vector<pair<string, double>>> adj;
public:
    
    double dfs(string &curr, string &dest, unordered_set<string> &isVisited){
        
        if(curr == dest){
            return 1.0;
        }
        
        isVisited.insert(curr);
        
        for(pair<string,double> &p : adj[curr]){
            
            string &v = p.first;
            double weight = p.second;
            
            if(isVisited.count(v))
                continue;
            
            double ans = dfs(v, dest, isVisited);
            
            if(ans != -1)
                return ans * weight;
        }
        
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
       
        for(int i = 0; i < equations.size(); i++){
            
            vector<string> &v = equations[i];
            
            adj[v[0]].push_back({v[1], values[i]});
            adj[v[1]].push_back({v[0], 1.0/values[i]});
        }
        
        vector<double> ans;
       
        for(vector<string> &v : queries){
            
             if(adj.count(v[0]) == 0 or adj.count(v[1]) == 0){
                ans.push_back(-1);
            }
            
             else if(v[0] == v[1]){
                ans.push_back(1);
            }
            
            else{
                unordered_set<string> isVisited;
                ans.push_back(dfs(v[0], v[1], isVisited));
            }
        }
        
        return ans;
        
    }
};