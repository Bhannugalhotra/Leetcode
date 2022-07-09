class Solution {
public:
    int jump(vector<int>& a) {
        
        int n = a.size();
        
        if(n == 1)
            return 0;
        
        int jumps = 1;
        int points = a[0];
        int max_reachable_idx = a[0];
        
        for(int i = 1; i < n-1; i++){
            
            points--;
            max_reachable_idx = max(max_reachable_idx,i + a[i]);
            
            if(points == 0){
                points = max_reachable_idx - i;
                jumps++;
            }
        }
        
        return jumps;
    }
};