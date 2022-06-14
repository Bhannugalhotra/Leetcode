class Solution 
{
    vector<vector<int>> memo;
    
public:
    
    int backtrack(string s1, int n1, string s2, int n2){
        
        if(n1 == 0 and n2 == 0)
            return 0;
        
        if(n1 == 0 or n2 == 0)
            return max(n1, n2);
        
        if(memo[n1][n2] != -1)
            return memo[n1][n2];
        
        if(s1[n1-1] == s2[n2-1])
            return memo[n1][n2] = backtrack(s1, n1-1, s2, n2-1);
        
        int case1 = backtrack(s1, n1-1, s2, n2) + 1;
        int case2 = backtrack(s1, n1, s2, n2 - 1) + 1;
        
        return memo[n1][n2]= min(case1, case2);
        
    }
    
    int bottom_up(string s1, string s2){
        
        int n = s1.size(), m = s2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        
        for(int j = 1; j <= m; j++)
            dp[0][j] = j;
        
        for(int i = 1; i <= n; i++)
            dp[i][0] = i;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                
                else
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
            }
        }
        
        return dp[n][m];
        
    }
    int minDistance(string word1, string word2) {
        
        
        return bottom_up(word1, word2);
        
//         memo = vector<vector<int>> (word1.size()+1, vector<int>(word2.size()+1, -1));
        
//         return backtrack(word1, word1.size(), word2, word2.size());
        
    }
};