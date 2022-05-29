class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        vector<pair<int,unordered_set<char>>> words_set;
        for(string &s : words){
            
            unordered_set<char> set {begin(s), end(s)};
            
            words_set.push_back({s.size(),set});
        }
        
        auto compare = [](pair<int,unordered_set<char>> &s1, pair<int,unordered_set<char>> &s2){
                            return s1.first > s2.first;
                        };
        
        sort(begin(words_set), end(words_set), compare);
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            
            
            
            for(int j = i + 1; j < n; j++){
                
                if(ans > words_set[i].first * words_set[j].first)
                break;
                
                bool common = false;
                for(char c : words_set[j].second){
                    if(words_set[i].second.count(c)){
                        common = true;
                        break;
                    }
                }
                
                if(!common){
                    ans = max(ans, int(words_set[i].first * words_set[j].first));
                        break;
                }
            }
        }
        
        return ans;
    }
};