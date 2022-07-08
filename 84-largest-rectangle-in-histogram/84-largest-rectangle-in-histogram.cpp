class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        
        if(n == 0) return 0;
        
        stack<int> s;
        int max_area = 0;
        for(int i = 0; i <= n; i++)
        {
            while(!s.empty() and (i == n or heights[s.top()] > heights[i]))
            {
                int curr_height = heights[s.top()]; s.pop();
                
                int right_end = i;
                
                int left_end = (s.empty()) ? -1 : s.top();
                
                int curr_area = curr_height * (right_end - left_end - 1);
                
                max_area = max(max_area, curr_area);
            }
            
            s.push(i);
        }
        
        return max_area;
    }
};