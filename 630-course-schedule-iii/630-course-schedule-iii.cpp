class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        auto compare = [](vector<int> &a, vector<int> &b) -> bool
                        {
                            return a[1] < b[1];
                        };
        
        sort(begin(courses), end(courses), compare);
        
        
        int time = 0;
        
        priority_queue<int> pq;
        
        for(vector<int> &v : courses){
            
            if(v[0] > v[1])
                continue;
            
            pq.push(v[0]);
            
            time += v[0];
            
            if(time > v[1])
                time -= pq.top(),  pq.pop();
        }
        
        return pq.size();
    }
};