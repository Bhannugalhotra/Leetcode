class Solution {
public:
    int minRefuelStops(int target, int start_fuel, vector<vector<int>>& stations) 
    {
        
        sort(begin(stations), end(stations));
        
        int n = stations.size();
        priority_queue<int> pq;
        
        if(target <= start_fuel)
            return 0;
        
        int ans = 0;
        int dist = 0;
        int prev = 0;
        for(int i = 0; i < n; i++){
        
            start_fuel -= (stations[i][0] - prev);
            dist += stations[i][0] - prev;
            prev = stations[i][0];
            
            while(start_fuel < 0 and !pq.empty()){
                
                start_fuel += pq.top();
                pq.pop();
                ans++;
            }
            
            if(start_fuel < 0)
                return -1;
            
            if(dist + start_fuel >= target)
                return ans;
            
            pq.push(stations[i][1]);
        }
        
        int pending_dist = target - dist - start_fuel;
        while(pending_dist > 0 and !pq.empty()){
            
            pending_dist -= pq.top(); pq.pop();
            ans++;
        }
        
        if(pending_dist > 0)
            return -1;
        
        return ans;
        
    }
};