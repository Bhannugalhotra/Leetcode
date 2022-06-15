class Solution {
public:
    
    bool is_successor(string &s1, string &s2)
    {
        if(s1.size() != s2.size() + 1)
            return false;
        
        int l = 0, r = 0;
        int count = 0;
        while(l < s1.size() and r < s2.size())
        {
            if(s1[l] == s2[r])
            {
                l++;
                r++;
            }
            
            else
            {
                count++;
                l++;
            }
        }
        
        return count <= 1;
    }
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();
        vector<int> dp(n+1,1);
        dp[0] = 0;
        sort(begin(words), end(words),[](const string &s1, const string &s2){return s1.size() < s2.size();});
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j < i; j++)
            {
                if(is_successor(words[i-1], words[j-1]))
                    dp[i] = max(dp[i], dp[j]+ 1);
            }
        }
        
        return *max_element(begin(dp), end(dp));
    }
};