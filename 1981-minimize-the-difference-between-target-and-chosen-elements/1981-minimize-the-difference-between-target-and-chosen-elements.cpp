

class Solution 
{
    int dp[70][5000];
    
public:
    
    int backtrack(vector<vector<int>> &mat, int idx, int sum, int target){
        
        if(idx == mat.size())
            return abs(target - sum);
        
        //pruning
        // if(sum > target)
        //     return abs(target - sum);

        if(dp[idx][sum] != -1)
            return dp[idx][sum];
        
        int minDiff = INT_MAX;
        
        for(int j = 0; j < mat[idx].size(); j++){
            
            minDiff = min(minDiff, backtrack(mat, idx + 1, sum + mat[idx][j], target));
        }
        
        return dp[idx][sum] = minDiff;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        
        memset(dp, -1, sizeof(dp));
        
        // for pruning
        for(vector<int> &v : mat)
            sort(begin(v), end(v));
        
        return backtrack(mat,0,0, target );
    }
};