class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        int n = envelopes.size();
        if(n <= 1)
            return n;
        
        // sort acording to width
        auto comp = [](const vector<int> &a,const vector<int> &b) -> bool
                        {
                            // very important step
                            if(a[0] == b[0])
                                return a[1] > b[1];
            
                            return a[0] < b[0];
                        };
        
        sort(begin(envelopes),end(envelopes),comp);
        
//         vector<int> dp(n,1);
//         int ans = 1;
//         for(int i = 1; i < n; i++)
//         {
//             for(int j = 0; j < i; j++)
//                 if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
//                     dp[i] = max(dp[i], dp[j] + 1);
            
//             ans = max(ans,dp[i]);
//         }
        
//         return ans;
        
        vector<int> tail;
        
        for(vector<int>& v : envelopes)
        {
            auto upper = lower_bound(begin(tail),end(tail),v[1]);
            
            if(upper == tail.end())
                tail.push_back(v[1]);
            
            else
                *upper = v[1];
            
        }
        
        return tail.size();
    }
};