class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n)
    {
        // in place merge
        
        while(m > 0 && n > 0)
        {
            if(a[m-1] > b[n-1])
            {
                a[m+n-1] = a[m-1];
                m--;
            }
            
            else
            {
                a[m+n-1] = b[n-1];
                n--;
            }
        }
        
        while(n > 0)
        {
            a[n-1] = b[n-1];
            n--;
        }
    }
};