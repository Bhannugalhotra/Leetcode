
class UnionFind{
    
    vector<int> a;
    int groupsCount;
    public:
    
    UnionFind(int n) : a(n,-1) , groupsCount(n) {};
    
    int Find(int x){
        
        if(a[x] < 0)
            return x;
        
        return a[x] = Find(a[x]);
    }
    
    bool Union(int x, int y){
        
        x = Find(x);
        y = Find(y);
        
        if(x == y)
            return false;
        
        // deciding by size
        
        if(a[x] <= a[y]){
            a[x] += a[y];
            a[y] = x;
        }
        
        else{
            a[y] += a[x];
            a[x] = y;
        }
        
        groupsCount--;
        return true;
    }
    
    bool IsAllConnected(){
        return groupsCount == 1;
    }
};

class Solution {
public:
    
    int ManhattanDistance(vector<int> &a , vector<int> &b){
        
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        
        vector<vector<int>> edges;
        
        for(int i = 0; i < n; i++){
            
            for(int j = i + 1; j < n; j++){
                
                int dist = ManhattanDistance(points[i], points[j]);
                
                edges.push_back({dist,i,j});
            }
        }
        
        // Krushkal Algorithm
        
        sort(edges.begin(), edges.end());
        int ans = 0;
        UnionFind unionFind(n);
        
        for(vector<int> &v : edges){
            
            if(unionFind.Union(v[1],v[2])){
                ans += v[0];
            }
            
            if(unionFind.IsAllConnected())
                break;
        }
        
        return ans;
    }
};