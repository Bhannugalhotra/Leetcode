typedef pair<int,int> data_type;
typedef priority_queue<data_type,vector<data_type>,greater<data_type>> min_pq;
class Solution
{
public:

    int networkDelayTime(vector<vector<int>>& times, int V, int k)
    {
        vector<pair<int,int>> adj[V+1];
        
        for(vector<int> &v : times)
            adj[v[0]].push_back({v[1],v[2]});
        
        vector<bool> visited(V+1);
        vector<int> distance(V+1, INT_MAX);
        
        distance[k] = 0;
        
        min_pq pq;
        
        pq.push({0,k});
        
        while(!pq.empty())
        {
            int u = pq.top().second;  pq.pop();
            
            if(visited[u]) continue;
            
            visited[u] = true;
            
            for(pair<int,int> &v : adj[u])
                if(!visited[v.first] && distance[v.first] > distance[u] + v.second)
                {
                    distance[v.first] = distance[u] + v.second;
                    
                    pq.push({distance[v.first], v.first});
                }
        }
    
        if(any_of(++begin(distance),end(distance),[](int x){return x == INT_MAX;}))
            return -1;
        
        return *max_element(++begin(distance), end(distance));
    }
};