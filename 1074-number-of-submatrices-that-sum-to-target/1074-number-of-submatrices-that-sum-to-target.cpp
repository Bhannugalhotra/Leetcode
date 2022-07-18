class Solution
{
public:
    
    int count_target(vector<int> &a,int target)
    {
        unordered_map<int,int> map;
        
        int sum = 0;
        int count = 0;
        
        for(int i = 0; i < a.size(); i++)
        {
            sum += a[i];
            
            if(sum == target)
                count++;
            
            if(map.count(sum - target))
                count += map[sum - target];
            
            map[sum]++;
        }
        
        return count;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) 
    {
        int n = mat.size();
        int m = mat[0].size();
        
        int count = 0;
        
        for(int up = 0; up < n; up++)
        {
            vector<int> a(m);
            for(int down = up; down < n; down++)
            {
                for(int col = 0; col < m; col++)
                    a[col] += mat[down][col];
                
                count += count_target(a,target);
            }
        }
        
        return count;
    }
};