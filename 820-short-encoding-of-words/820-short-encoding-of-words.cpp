class Solution {
public:
    
    bool is_suffix(string &s1, string &s2){
        
        int l = s1.size()-1, r = s2.size()-1;
        
        while(r >= 0 and s1[l] == s2[r])
            l--, r--;
        
        return r < 0;
    }
    int minimumLengthEncoding(vector<string>& words) {
        
        int n = words.size();
        
        sort(begin(words), end(words),[](string &s1, string &s2){return s1.size() > s2.size();});
        
        vector<bool> a(n, true);
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(is_suffix(words[j], words[i]))
                {
                    a[i] = false;
                    break;
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(a[i])
                ans += words[i].size() + 1;
        }
        
        return ans;
    }
};