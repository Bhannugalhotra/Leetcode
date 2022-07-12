class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
//         vector<pair<int,int>> zip;
        
//         for(int i = 0; i < capacity.size() ;i++){
//             zip.push_back({rocks[i], capacity[i]});
//         }
        
//         sort(begin(zip), end(zip) ,[] (pair<int,int> a, pair<int,int> b){
                                        
//                                         return (a.second - a.first) < (b.second - b.first);
//                                         });
        
//         int ans = 0;
        
//         for(pair<int,int> &it : zip){
            
//             int diff = it.second - it.first;
            
//             additionalRocks -= diff;
            
//             if(additionalRocks < 0)
//                 break;
            
//             ans++;
//         }
        
//         return ans;
        
        
        // solution 2
        
        vector<int> diff;
        
        for(int i = 0; i < capacity.size(); i++)
            diff.push_back(capacity[i] - rocks[i]);
        
        sort(begin(diff), end(diff));
        
        int ans = 0;
        
        for(int it : diff){
            
            additionalRocks -= it;
            
            if(additionalRocks < 0)
                break;
            
            ans++;
        }
        
        return ans;
    }
};