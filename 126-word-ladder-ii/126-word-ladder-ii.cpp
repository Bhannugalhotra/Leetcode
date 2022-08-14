class Solution 
{
    
     vector<vector<string>> ans;
public:
    
    bool check(string &s1, string &s2){
        
        int count = 0;
        
        for(int i = 0 ;i < s1.size(); i++){
            if(s1[i] != s2[i])
                count++;
            
            if(count > 1)
                return false;
        }
        
        return count == 1;
    }
    
    vector<int> bfs(int end, int v,vector<vector<int>> &adj){
        
        vector<bool> visited(v , false);
        vector<int> distance(v,-1);
        
        queue<int> q;
        q.push(end);
        q.push(-1);
        
        distance[end] = 1;
        visited[end] = true;
        
        int len = 2;
        while(!q.empty()){
            
            int curr = q.front();  q.pop();
            
            if(curr == -1){
                
                if(!q.empty())
                    q.push(-1);
                
                len++;
                
                continue;
            }
            
            for(int i : adj[curr]){
                
                if(!visited[i]){
                    
                    visited[i] = true;
                    distance[i] = len;
                    q.push(i);
                }
            }
        }
        
        return distance;
    }
    
    void backtrack(int len, int start, int end, vector<string> &curr, vector<vector<int>> &adj,vector<bool> &visited, vector<string> &wordlist, vector<int> &distance){
      

        curr.push_back(wordlist[start]);
        visited[start] = true;
        
        if(len == 1){
            
            if(start == end){
                
                ans.push_back(curr);
            }
            
            
            visited[start] = false;      
            curr.pop_back();
            return;
        }
        
      
        for(int u : adj[start]){
            
            if(!visited[u] and distance[u] == len - 1){
                backtrack(len-1,u, end, curr, adj,visited, wordlist, distance);   
            }
                
        }
        
          visited[start] = false;      
          curr.pop_back();
    }
    vector<vector<string>> findLadders(string begin_word,string end_word,vector<string>& wordlist) {
        
        wordlist.push_back(begin_word);
        int n = wordlist.size();
        
        vector<vector<int>> adj(n);
        
        int idx = -1;
        for(int i = 0; i < wordlist.size(); i++){
            
            for(int j = i+1; j < wordlist.size(); j++){
                
                if(check(wordlist[i], wordlist[j])){
                    
                    adj[i].push_back(j);
                    
                    adj[j].push_back(i);
                }
            }
            
            if(wordlist[i] == end_word)
                idx = i;
        }
        
        if(idx == -1)
            return {};
        
        vector<int> distance = bfs(idx, n,adj);
        
        if(distance[n-1] == -1)
            return {};

        vector<string> curr;
        vector<bool> visited(n);
        
        backtrack(distance[n-1],n-1, idx, curr, adj, visited,wordlist, distance);
        
        return ans;
        
        
    }
};