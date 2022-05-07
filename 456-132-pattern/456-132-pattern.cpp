class Solution {
public:
    
    
    bool find132pattern(vector<int>& a)
    {
        int n = a.size();
        
        if(n < 3)
            return false;
        
        vector<int> prefix(n);
        
        prefix[0] = a[0];
        
        for(int i = 1; i < n; i++)
            prefix[i] = min(prefix[i-1],a[i]);
        
        stack<int> s;
        
        for(int j = n-1; j > 0; j--)
        {
            if(a[j] <= prefix[j])
                continue;
            
            while(!s.empty() && s.top() <= prefix[j])
                s.pop();
            
            if(!s.empty() && s.top() < a[j])
                return true;
            
            s.push(a[j]);
        }
        
        return false;
    }
};