class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<vector<int>> adj(n+1);
        
        for(vector<int> &v : relations){
            
            adj[v[0]].push_back(v[1]);
        }
        
        vector<int> indegree(n+1);
        
        for(int i = 1; i <= n; i++){
            
            for(int v : adj[i])
                indegree[v]++;
        }
        
        queue<int> q;
        
        for(int i = 1; i <= n; i++){
            
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<vector<int>> preCoursesTime(n+1);
        
        int ans = 0;
        
     
        while(!q.empty()){
            
            int u = q.front(); q.pop();
             
            int currTime = time[u-1];
         
            int prevMaxTime = 0;
            
            for(int num : preCoursesTime[u]){
                prevMaxTime = max(prevMaxTime, num);
            }
            currTime += prevMaxTime;
            
            ans = max(ans, currTime);
            
            for(int v : adj[u]){
                
                preCoursesTime[v].push_back(currTime);
                
                if(--indegree[v] == 0)
                    q.push(v);
            }
        }
        
        return ans;
    }
};