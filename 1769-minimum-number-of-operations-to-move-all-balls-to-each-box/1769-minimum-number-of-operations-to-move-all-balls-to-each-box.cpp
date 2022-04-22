class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int n = boxes.size();
        
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++){
            
            int count = 0;
            
            for(int j = 0; j < i; j++){
                count += (boxes[j] - '0') * (i - j);
            }
            
            for(int j = i+1; j < n; j++){
                count += (boxes[j] - '0') * (j - i);
            }
            
            ans[i] = count;
        }
        
        return ans;
    }
};