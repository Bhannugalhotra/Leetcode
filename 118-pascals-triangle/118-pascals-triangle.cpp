class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        if(numRows == 0)
            return {};
        vector<vector<int>> ans;
        
        ans.push_back({1});
        int row = 1;
        while(row < numRows)
        {
            ans.push_back({1});
            for(int i = 1; i < ans[row-1].size(); i++)
                ans[row].push_back(ans[row-1][i] + ans[row-1][i-1]);
            
            ans[row].push_back(1);
            row++;
        }
        
        return ans;
    }
};