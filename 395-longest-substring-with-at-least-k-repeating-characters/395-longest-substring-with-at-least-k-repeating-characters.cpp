class Solution {
public:
    int longestSubstring(string s, int k) {
        
        if(s.size() == 0)
            return 0;
        
        unordered_map<char, int> map;
        
        for(char c : s){
            map[c]++;
        }
        
        unordered_set<char> lower_freq_elem;
        
        for(auto it : map){
            if(it.second < k)
                lower_freq_elem.insert(it.first);
        }
        
        if(lower_freq_elem.size() == 0)
            return s.size();
        
        string x;
        int ans = 0;
        for(char c : s){
            
            if(lower_freq_elem.count(c)){
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