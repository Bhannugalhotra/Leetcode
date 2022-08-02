
typedef pair<int,pair<int,int>> ipair;

class Solution {
public:
    
    int check(vector<vector<int>> &a,int target)
    {
        int n = a.size();
    
        int count = 0;
        
        for(int r = n-1, c= 0; r >= 0 && c < n;)
        {
            if(a[r][c] > target)
                r--;
            
            else
            {
                count += r + 1;
                c++;
            }
        }
        
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& mat, int k)
    {
        int n = mat.size();
        
        // solution 1 , using binary search
        
//         int l = mat[0][0];   
//         int r = mat[n-1][n-1];
        
//         while(l <= r)
//         {
//             int mid = l + (r - l)/2;
            
//             if(check(mat,mid) < k)
//                 l = mid + 1;
            
//             else
//                 r = mid-1;
//         }
        
//         return l;
        
        // solution 2,  using heap
        
        priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
        
        for(int i = 0; i < n; i++)
            pq.push({mat[0][i],{0,i}});
        
        while(k > 1)
        {
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            if(row != n-1)
                pq.push({mat[row+1][col],{row+1,col}});
            
            k--;
        }
        
        return pq.top().first;
    }
};