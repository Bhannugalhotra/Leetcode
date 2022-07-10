class Solution 
{
    vector<int> memo;
public:

    int backtrack(string &s, int i){
        
        if(i == s.size())
            return 1;
        
        if(s[i] == '0')
            return 0;
        
        if(memo[i] != -1)
            return memo[i];
        
        int ans = backtrack(s,i+1);
        
        if(i == s.size() - 1)
            return memo[i] = ans;
        
        int num = stoi(s.substr(i,2));
        
        if(num > 26)
            return memo[i] = ans;
        
        ans += backtrack(s, i + 2);
        
        return memo[i] = ans;
    }
    
    
    int numDecodings(string s) {
        
        memo = vector<int> (s.size(),-1);
        
        return backtrack(s,0);
        
    }
};