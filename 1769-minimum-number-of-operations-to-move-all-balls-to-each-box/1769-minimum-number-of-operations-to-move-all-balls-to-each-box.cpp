class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int n = boxes.size();
        
        vector<int> ans(n);
        
        // O(n*n) solution
//         for(int i = 0; i < n; i++){
            
//             int count = 0;
            
//             for(int j = 0; j < i; j++){
//                 count += (boxes[j] - '0') * (i - j);
//             }
            
//             for(int j = i+1; j < n; j++){
//                 count += (boxes[j] - '0') * (j - i);
//             }
            
//             ans[i] = count;
//         }
        
        //put balls first from left to right
        
        int sum = 0;
        int balls = 0;
        
        for(int i = 0 ; i < n; i++){
            
            sum += balls;
            ans[i] += sum;
            
            if(boxes[i] == '1'){
                balls++;
            }
        }
        
        //now put balls from right from left
        
        sum = 0;
        balls = 0;
        for(int i = n-1; i >= 0; i--){
            
            sum += balls;
            ans[i] += sum;
            
            if(boxes[i] == '1'){
                balls++;
            }
        }
        
        return ans;
    }
};