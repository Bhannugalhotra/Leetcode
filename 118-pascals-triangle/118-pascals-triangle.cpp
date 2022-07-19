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
            vector<int> temp{1};
            
            for(int i = 1; i < ans.back().size(); i++)
                temp.push_back(ans.back()[i] + ans.back()[i-1]);
            
            temp.push_back(1);
            ans.push_back(temp);
            row++;
        }
        
        return ans;
    }
};