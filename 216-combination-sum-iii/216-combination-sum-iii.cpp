class Solution 
{
    vector<vector<int>> ans;
public:
    
    void backtrack(int k,vector<int> a,int sum)
    {
        if(k == 0)
        {
            if(sum == 0)
                ans.push_back(a);
            
            return;
        }
        
        int start = (a.empty()) ? 0 : a.back();
        for(int i = start+1; i <= 9; i++)
        {
            if(sum < i)
                break;
            
            a.push_back(i);
            
            backtrack(k-1,a,sum-i);
            
            a.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        backtrack(k,{},n);
        
        return ans;
    }
};