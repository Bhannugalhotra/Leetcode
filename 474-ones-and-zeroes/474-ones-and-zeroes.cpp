class Solution {
public:
    int findMaxForm(vector<string>& strs, int M, int N) {
        
        vector<vector<int>> a;
        
        for(string &s : strs){
            
            int one = 0, zero = 0;
            
            for(char c : s)
            {
                if(c == '0')
                    zero++;
                
                else one++;
            }
            
            a.push_back(vector<int>{zero,one});
        }
        
//         vector<vector<vector<int>>> dp (2,vector<vector<int>>(M+1, vector<int>(N+1)));
        
//         for(int i = 1 ; i <= a.size(); i++)
//         {
//             for(int m = 0; m <= M ; m++)
//             {
//                 for(int n = 0; n <= N; n++)
//                 {

//                     if(m == 0 and n == 0)
//                         continue;

//                     int curr_idx = i % 2;
//                     int prev_idx = (i-1) % 2;
                    
//                     dp[curr_idx][m][n] = dp[prev_idx][m][n];
                    
//                     if( a[i-1][0] <= m and a[i-1][1] <= n)
//                     {
//                         dp[curr_idx][m][n] = max( dp[curr_idx][m][n],
//                                                   dp[prev_idx][m-a[i-1][0]][n-a[i-1][1]] + 1);
//                     }

//                 }
//             }
//         }
        
//         return dp[a.size() % 2][M][N];
        
        // more optimized version
        
        vector<vector<int>> dp(M+1, vector<int>(N+1));
        
        for(int i = 0; i < a.size(); i++){
            
            for(int m = M; m >= a[i][0]; m--){
                
                for(int n = N ;n >= a[i][1]; n--){
                    
                    dp[m][n] = max(dp[m][n], dp[m - a[i][0]][n- a[i][1]] + 1);
                }
            }
        }
        
        return dp[M][N];
    }
};