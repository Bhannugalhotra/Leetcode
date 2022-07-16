class union_find
{
	vector<int> set;

public:

	union_find(int n) : set(n,-1) {};

	int find(int x)
	{
		if(set[x] < 0)
			return x;

		return set[x] = find(set[x]);
	}

	bool _union(int a, int b)
	{
		a = find(a);
		b = find(b);

		if(a == b)
			return false;

		if(set[a] < set[b])
			set[b] = a;

		else
		{
			if(set[a] == set[b])
				set[b]--;

			set[a] = b;
		}

		return true;
	}
};




class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        
        union_find unionFind(accounts.size());
        
        unordered_map<string,int> map;
        
        for(int i = 0; i < accounts.size(); i++){
            
            for(int j = 1; j < accounts[i].size(); j++){
                
                string &s = accounts[i][j];
                
                if(map.count(s)){
                    unionFind._union(map[s], i);
                }
                
                else
                    map[s] = i;
            }
        }
        
        unordered_map<int,vector<string>> finalMap;
        
        for(auto &it : map){
            
            int idx = unionFind.find(it.second);
            
            finalMap[idx].push_back(it.first);
        }
        
        vector<vector<string>> ans;
        
        for(auto &it : finalMap){
            sort(begin(it.second), end(it.second));
            
            it.second.insert(it.second.begin(),accounts[it.first][0]);
            
            ans.push_back(it.second);
        }
        
        return ans;
        
    }
};