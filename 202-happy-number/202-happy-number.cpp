class Solution {
public:
    
    int getNext(int n){
        
        int sum = 0;
        
        while(n > 0){
            
            int r = n % 10;
            n = n / 10;
            
            sum += r * r;
        }
        
        return sum;
    }
    
    
    bool isHappy(int n) {
        
        int slow = n;
        int fast = getNext(n);
        
        while(fast != 1){
            
            slow = getNext(slow);
            
            fast = getNext(getNext(fast));
            
            if(fast == slow)
                return false;
        }
        
        return true;
    }
};