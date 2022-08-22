class Solution {
public:
    
    
    int idxOfSetBit(int n){
        
        for(int i = 31 ; i >= 0; i--){
            if(n & (1 << i))
                return i;
        }
        
        return -1;
    }
    bool isPowerOfFour(int n) {
        
//         while(n > 1 and n % 4 == 0){
//             n /= 4;
//         }
        
//         return n == 1;
        
        return n > 0 and (( n & (n-1) ) == 0) and idxOfSetBit(n) % 2 == 0;
    }
};