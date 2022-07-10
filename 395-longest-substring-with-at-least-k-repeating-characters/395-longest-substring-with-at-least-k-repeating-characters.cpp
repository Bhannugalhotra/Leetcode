class Solution {
public:
    int longestSubstring(string s, int k) {
        
      
        if(s.size() == 0)
            return 0;
        
        unordered_map<char, int> map;
        
        for(char c : s){
            map[c]++;
        }
        
        unordered_set<char> set;
        
        for(auto it : map){
            if(it.second < k)
                set.insert(it.first);
        }
        
        if(set.size() == 0)
            return s.size();
        
        string x;
        int ans = 0;
        for(char c : s){
            
            if(set.count(c)){
                ans = max(ans, longestSubstring(x, k));
                x = "";
            }
            
            else{
                x += c;
            }
        }
        ans = max(ans, longestSubstring(x, k));
       
        return ans;
    }
};