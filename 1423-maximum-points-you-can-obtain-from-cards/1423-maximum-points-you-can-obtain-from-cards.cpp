class Solution {
public:
    int maxScore(vector<int>& a, int k)
    {
        int n = a.size();
        
        if(k == n)
             return accumulate(begin(a), end(a),0);
        
        vector<int> prefix(n);
        vector<int> suffix(n);
        
        prefix[0] = a[0];
        for(int i = 1; i < k ; i++)
        prefix[i] = prefix[i-1] + a[i];
        
        suffix[n-1] = a[n-1];
        
        for(int i = n-2; i >= n - k; i--)
        suffix[i] = suffix[i+1] + a[i];
        
        int max_sum = max(prefix[k-1],suffix[n-k]);
        
        for(int i = 0, j = n-k+1; i < k-1; i++,j++)
            max_sum = max(max_sum, prefix[i]+suffix[j]);
        
        return max_sum;
        
        // solution 2, by space optimizing solution 1
        
        // solution 3
        // problem translation,
        // find min-sum subarray of length n - k;
        // final ans = total_sum - min_sum
        
        int min_sum = INT_MAX;
        int window_len = n - k;
        int sum = 0;
        for(int i = 0; i < window_len; i++)
            sum += a[i];
        
        min_sum = sum;
        
        for(int i = window_len; i < n; i++)
        {
            sum += a[i];
            sum -= a[i - window_len];
            
            min_sum = min(min_sum, sum);
        }
        
        return accumulate(begin(a),end(a),0) - min_sum;
    }
};