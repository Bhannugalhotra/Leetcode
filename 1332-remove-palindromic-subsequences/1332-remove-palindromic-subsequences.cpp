class Solution {
public:
    bool is_palindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        
        while(l < r and s[l] == s[r])
            l++, r--;
        
        return l >= r;
    }
    int removePalindromeSub(string s) {
        
        if(s.size() == 0)
            return 0;
       vector<int> count(2);
        
        for(char c : s)
            count[c - 'a']++;
        
        if(count[0] > 0 and count[1] > 0 and !is_palindrome(s))
            return 2;
        
        return 1;
    }
};