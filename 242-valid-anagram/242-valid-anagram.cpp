class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if(s.size() != t.size())
            return false;
        
        vector<int> freq(26);
        
        for(char c : s)
            freq[c-'a']++;
        
        for(char c : t)
            freq[c-'a']--;
        
        return all_of(begin(freq), end(freq), [](int x) {return x == 0;});   
    }
};