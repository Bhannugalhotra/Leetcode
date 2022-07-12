

class Solution 
{
    int dp[70][5000];
    
public:
    
    int backtrack(vector<vector<int>> &mat, int idx, int sum, int target){
        
        if(idx == mat.size())
            return abs(target - sum);
       
        if(dp[idx][sum] != -1)
            return dp[idx][sum];
        
        int minDiff = INT_MAX;
        
        for(int j = 0; j < mat[idx].size(); j++){
            
            minDiff = min(minDiff, backtrack(mat, idx + 1, sum + mat[idx][j], target));
            
            if(minDiff == 0)
                break;
        }
        
        return dp[idx][sum] = minDiff;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        
        memset(dp, -1, sizeof(dp));
        
     
        
        return backtrack(mat,0,0, target );
    }
};