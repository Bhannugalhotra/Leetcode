class Solution {
public:
    int uniquePaths(int m, int n) {
        
        // ans = (n + m - 2)! / (n-1)! * (m-1)!
        
        double ans = 1;
        
        for(double i = 0; i <= n-2; i++)
        {
            ans *= (double(m) + i);
            
            ans /= (i+1);
        }
        
        return ans;
    }
};