class Solution 
{
    vector<int> memo;
public:
    
    string reformat(string &s){
        
        if(s.size() == 0 or s[0] == '0')
            return "-1";
        
        string x;
        
        int n = s.size();
        for(int i = 0; i < n; i++){
            
            if(s[i] == '0')
                return "-1";
            
            if(i < n-1 and s[i+1] == '0'){
                
                if(s[i] >= '3')
                    return "-1";
                
                x += '#';
                i++;
            }
            
            else
                x += s[i];
        }
        
        return x;
    }
    
//     int backtrack(string &s, int i){
        
//         if(i == s.size())
//             return 1;
        
//         if(memo[i] != -1)
//             return memo[i];
        
//         int ans = backtrack(s,i+1);
        
//         if(s[i] == '1' and i < s.size()-1 and s[i+1] != '#')
//             ans += backtrack(s, i+2);
          
//         else if(s[i] == '2' and i < s.size()-1 and s[i+1] != '#' and s[i+1] <= '6')
//             ans += backtrack(s, i+2);
        
//        return memo[i] = ans;
//     }
    
    // without formatting
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
    
    
    
    int bottom_up(string &s)
    {
        int n = s.size();
        vector<int> dp(n+1);
        
        dp[0] = dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            
            int idx = i-1;
            
            if(s[idx] == '#' or s[idx-1] >= '3' or s[idx-1] == '#')
                dp[i] = dp[i-1];
            
            else if(s[idx-1] == '1')
                dp[i] = dp[i-1] + dp[i-2];
            
            else if(s[idx-1] == '2'){
                
                if(s[idx] <= '6')
                    dp[i] = dp[i-1] + dp[i-2];
                
                else
                    dp[i] = dp[i-1];
            }            
            
        }
        
        return dp[n];
    }
    int numDecodings(string s) {
        
        memo = vector<int> (s.size(),-1);
        
        return backtrack(s,0);
        
//         s = reformat(s);
        
//         if(s == "-1")
//             return 0;
        
//         return bottom_up(s);
        
//         memo = vector<int> (s.size(),-1);
        
//         return backtrack(s,0);
    }
};