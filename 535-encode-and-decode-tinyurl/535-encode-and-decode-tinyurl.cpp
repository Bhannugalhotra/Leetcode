class Solution 
{
    const int LEN = 5;
    vector<char> set;
    unordered_map<string, string> hash_map;
    unordered_map<string,string> urls;
    
public:
    
    Solution(){
        
        for(int i = 'a'; i <= 'z'; i++){
            set.push_back(i);
        }
        
        for(int i = 'A'; i <= 'Z'; i++){
            set.push_back(i);
        }
        
        for(int i = '0'; i <= '9'; i++){
            set.push_back(i);
        }
    }
    
    string generate_key(){
        
        string key;
        
        for(int i = 0; i < LEN; i++){
            
            int idx = rand() % set.size();
            
            key += set[idx];
        }
        
        return key;
        
    }
    string encode(string longUrl) {
        
        if(urls.count(longUrl))
            return "http://tinyurl.com/" + urls[longUrl];
        
        string key;
        
        do{
            key = generate_key();
            
        }while(hash_map.count(key));  // for handling collision
        
        hash_map[key] = longUrl;
        urls[longUrl] = key;
        return "http://tinyurl.com/" + key;
    }

    
    string decode(string shortUrl) {
        
        string key = shortUrl.substr(shortUrl.size()-LEN, LEN);
        
        return hash_map[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));