class Solution
{
public:
    
    int max_sum_in_1d_array(vector<int> &a,int k)
    {
        int n = a.size();
        int max_sum = INT_MIN;
        int sum = 0;
        
        set<int> st;
        st.insert(0);
        
        for(int i : a)
        {
            sum += i;
            
            auto it = st.lower_bound(sum - k);
            
            if(it != st.end())
                max_sum = max(max_sum,sum - *it);
            
            st.insert(sum);
        }
        
        return max_sum;
    }
    int maxSumSubmatrix(vector<vector<int>>& mat, int k)
    {
        int n = mat.size();
        
        if(n == 0)
            return 0;
        
        int m = mat[0].size();
        
        if(m == 0)
            return 0;
    
        int max_sum = INT_MIN;
        
        for(int left = 0; left < m; left++)
        {
            vector<int> a(n);
            for(int right = left; right < m; right++)
            {
                for(int row = 0; row < n; row++)
                    a[row] += mat[row][right];
                
                max_sum = max(max_sum,max_sum_in_1d_array(a,k));
            }
        }
        
        return max_sum;
    }
};