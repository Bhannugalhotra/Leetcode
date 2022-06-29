class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        list<vector<int> > l;
        
        auto compare =[](vector<int> &a,vector<int> &b){return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];};
        
        sort(begin(people),end(people),compare);
        
        for(auto& i : people)
        {
             int count = i[1];
    
             auto it = begin(l);
             advance(it,count);
                
             l.insert(it,i);  
        }
        
        vector<vector<int> > ans;
        
        copy(make_move_iterator(begin(l)),make_move_iterator(end(l)),back_inserter(ans));
        
        return ans;
    }
};