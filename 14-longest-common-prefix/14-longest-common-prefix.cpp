class Solution {
public:
    
    string LCP(string &a, string &b){
        
        string s = "";
        
        for(int i = 0; i < a.size() and i < b.size() and a[i] == b[i]; i++){
            s += a[i];
        }
        
        return s;
    }
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = strs[0];
        
        for(int i = 1; i < strs.size(); i++){
            
            ans = LCP(ans, strs[i]);
            
            if(ans == "")
                break;
        }
        
        return ans;
    }
};