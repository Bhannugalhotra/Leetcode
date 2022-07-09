class Solution {

    vector<string> ans;
    
    
public:
    
 
    void backtrack(int idx, string &s, int open){
        
        if(idx == s.size()){
            ans.push_back(s);
            
            return ;
        }
        
        int left = s.size() - idx;
        
        if(open == 0 or open < left){
            s[idx] = '(';
                
                backtrack(idx+1, s, open + 1);
            
            s[idx] = ' ';
        }
        
        if(open > 0){
            
            s[idx] = ')';
            
            backtrack(idx + 1, s, open-1);
            
            s[idx] = ' ';
        }
    }
    vector<string> generateParenthesis(int n) {
        
        string s(n*2, ' ');
        
        backtrack(0,s,0);
        
        return ans;
    }
};