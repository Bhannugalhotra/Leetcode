class Solution {
public:
    int minSteps(string s, string t) {
        
        unordered_map<char,int> map;
        
        for(char c : s){
            map[c]++;
        }
        
        for(char c : t){
            map[c]--;
        }
        
        int ans = 0;
        
        for(auto itr : map){
            
            if(itr.second > 0)
                ans += itr.second;
        }
        
        return ans;
    }
};