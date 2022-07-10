class Solution {
public:
    int calculate(string s)
    {
        unordered_map<char,int> map {{'+',0},{'-',1},{'*',2},{'/',3}};
        
        vector<long> a;
        
        int write_idx = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
                continue;
            
            s[write_idx++] = s[i];
        }
        
        int n = write_idx;
        for(int i = 0; i < n;)
        {
            int num = 0;
    
            while(i < n and s[i] >= '0' and s[i] <= '9')
            {
                num = num*10 + long(s[i] - '0');
                i++;
            }
            
            
            a.push_back(num);
            
            if(i != n)
                a.push_back(s[i++]);
        }
        
        write_idx = 0;
        
        for(int i = 1; i < a.size(); i += 2)
        {
            if(a[i] == '*')
                a[write_idx] *= a[i+1];
            
            else if(a[i] == '/')
                a[write_idx] /= a[i+1];
            
            else a[++write_idx] = a[i], a[++write_idx] = a[i+1];
        }
        
        n = write_idx + 1;
        
        for(int i = 1; i < n; i += 2)
        {
            if(a[i] == '+')
                a[0] += a[i+1];
            
            else if(a[i] == '-')
                a[0] -= a[i+1];
        }
        
        
        return a[0];
    }
};