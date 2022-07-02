class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(begin(horizontalCuts), end(horizontalCuts));
        sort(begin(verticalCuts), end(verticalCuts));
        
        long max_horz = 0, max_vert = 0;
        long prev = 0;
        
        for(int num : horizontalCuts){
        
            max_horz = max(max_horz, long(num) - prev);
            prev = num;
        }
        
        max_horz = max(max_horz, long(h - horizontalCuts.back()));
        
        prev = 0;
        
        for(int num : verticalCuts){
        
            max_vert = max(max_vert, long(num) - prev);
            prev = num;
        }
        
        max_vert = max(max_vert, long(w - verticalCuts.back()));
        
        int mod = (1e9 + 7);
        
        return (max_horz * max_vert) % mod;
        
        
    }
};