class Solution {
public:
    
    vector<int> solve(string s, unordered_map<string,int> &map_word,int word_len,int k)
    {
        int window_len = k * word_len;
        unordered_map<string,int> map_s;
        vector<int> ans;
        int count = 0;
        
        for(int i = 0; i < window_len; i += word_len)
        {
            string ss = s.substr(i,word_len);
            if(++map_s[ss] <= map_word[ss])
                count++;
        }
        
        if(count == k)
            ans.push_back(0);
        
        for(int i = window_len ; i < s.size(); i += word_len)
        {
            string next = s.substr(i,word_len);
            string prev = s.substr(i-window_len,word_len);
            
            if(++map_s[next] <= map_word[next])
                count++;
            
            if(map_word.count(prev) && --map_s[prev] < map_word[prev])
                count--;
            
            if(count == k)
                ans.push_back(i - window_len + word_len);
        }
        
        return ans;
    }
    vector<int> findSubstring(string s, vector<string>& word)
    {
        int k = word.size();
        if(k == 0)
            return {};
        int word_len = word[0].size(); 
        
        if(word_len == 0 || s.size() == 0 || s.size() < k * word_len)
            return {};
        
        unordered_map<string,int> map_word;
        for(string s : word)
            map_word[s]++;
        
        vector<int> ans;
        
        for(int i = 0; i < word_len; i++)
        {
            vector<int> aux = solve(s.substr(i),map_word,word_len,k);
            
            for(int j : aux)
                ans.push_back(j + i);
        }
        
        return ans;
        
    }
};