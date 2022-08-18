class Solution {
public:
    int minSetSize(vector<int>& a) {
        
        int n = a.size();
        
        unordered_map<int,int> map;
        
        for(int i : a)
            map[i]++;
        
        vector<int> freq;
        
        for(auto &it : map)
            freq.push_back(it.second);
        
        sort(rbegin(freq), rend(freq));
        int count = 0;
        int ans = 0;
        
        int idx = 0;
        
        while(count < n/2 and idx < freq.size()){
        
            count += freq[idx];
            
            idx++;
            
            ans++;
        }
        
        return ans;
    }
};