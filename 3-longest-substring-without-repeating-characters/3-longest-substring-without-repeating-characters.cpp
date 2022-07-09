class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
//         int n = s.size();
//         if(n == 0) return 0;
//         vector<int> freq(128);
        
//         int ans = 1; 
        
//         for(int left = 0, right = 0; right < n; right++)
//         {
//             freq[s[right]]++;
            
//             while(any_of(begin(freq), end(freq),[](int x) {return x > 1;} ))
//             {
//                 freq[s[left]]--;
//                 left++;
//             }
            
//             ans = max(ans, right - left + 1);
//         }
        
//         return ans;
        
            // solution 2
        
        int n = s.size();
        if(n == 0) return 0;
        vector<int> freq(128);
        
        int ans = 1; 
        
        for(int left = 0, right = 0; right < n; right++)
        {
            freq[s[right]]++;
            
            while(freq[s[right]] > 1)
            {
                freq[s[left]]--;
                left++;
            }
            
            ans = max(ans, right - left + 1);
        }
        
        
        
        return ans;
    }
};