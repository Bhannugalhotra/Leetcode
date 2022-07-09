class Solution {
public:
    bool canJump(vector<int>& a) {
       
        int n = a.size();
        
        if(n <= 1) return true;
        
//         int jumps = 1;
//         int points = a[0], max_reachable = a[0];
        
//         for(int i = 1; i < n and points > 0; i++){
            
//             max_reachable = max(max_reachable, i + a[i]);
            
//             points--;
            
//             if(points == 0){
//                 points = max_reachable - i;
//             }
//         }
        
//         return max_reachable >= n-1;
        
        int max_reachable = a[0];
        
        for(int i = 1; i < n and max_reachable >= i ; i++){
            
            max_reachable = max(max_reachable, i + a[i]);
        }
        
        return max_reachable >= n-1;
    }
};