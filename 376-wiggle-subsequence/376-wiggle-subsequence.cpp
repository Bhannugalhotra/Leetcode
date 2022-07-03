class Solution {
public:
    
    int wiggleMaxLength(vector<int>& a) {
        
        int n = a.size();
        
        // o(n*n) solution
        
//         vector<int> inc(n,1), dec(n,1);
//         int ans = 1;
//         for(int i = 1; i < n; i++){
//             for(int j = 0; j < i; j++){
                
//                 if(a[i] > a[j]){
//                     inc[i] = max(inc[i], dec[j]+1);
//                 }
                
//                 else if(a[i] < a[j]){
//                     dec[i] = max(dec[i], inc[j] + 1);
//                 }
                
//                 ans = max(ans, max(dec[i], inc[i]));
//             }
//         }
        
//         return ans;
        
//         // o(n) solution
        
        int upper = -1, lower = INT_MAX;
        int count1 = 0, count2 = 0;
        bool inc_upper = true, inc_lower = false;
        
        for(int num : a){
            
            if(inc_upper){
                
                if(num > upper)
                    count1++, inc_upper = false;
                
                upper = num;
                
            }
            
            else{
                
                if(num < upper)
                    count1++, inc_upper = true;
                
                upper = num;
            }
            
            if(inc_lower){
                
                if(num > lower)
                    count2++, inc_lower = false;
                
                lower = num;
                
            }
            
            else{
                
                if(num < lower)
                    count2++, inc_lower = true;
                
                lower = num;
                
            }
        
        }
        
        
        return max(count1, count2);
        
        
    }
};