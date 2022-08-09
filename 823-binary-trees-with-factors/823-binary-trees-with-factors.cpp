class Solution 
{
    int mod = 1e9 + 7;
    unordered_set<int> set;
    unordered_map<int,long> dp;
public:
    
    long backtrack(int num, vector<int> &a)
    {
        if(dp.count(num))
            return dp[num];
        
        long ans = 1;
        
        for(int i = 0; i < a.size() and a[i] < num ; i++){
            
            int root = a[i];
            if(num % root == 0 and set.count(num / root))
                ans = (ans + backtrack(root, a) * backtrack(num/root,a) % mod) % mod;
        }
        
        return dp[num] = ans ;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        sort(begin(arr),end(arr));
        
        for(int num : arr)
            set.insert(num);
        
        long ans = 0;
        
        for(int num : arr)
            ans += backtrack(num,arr);
        
        return ans % mod;
        
    }
};