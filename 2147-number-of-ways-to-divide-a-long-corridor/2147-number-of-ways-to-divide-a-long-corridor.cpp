class Solution {
public:
    int numberOfWays(string corridor) {
        
        int seatsCount = std::count(begin(corridor), end(corridor), 'S');
        
        if(seatsCount % 2 != 0)
            return 0;
        
        if(seatsCount == 0)
            return 0;
        
        int mod = 1e9 + 7;
        long long ans = 1;
        
        int prevSeats = 0;
        int currPlants = 0;
        
        for(char c : corridor){
    
            if(c == 'S')
                prevSeats++;
            
            else if(prevSeats == 2)
                currPlants++;
            
            if(prevSeats > 2){
                
                ans = (ans * (currPlants + 1)) % mod;
                
                currPlants = 0;
                prevSeats = 1;
            }
        }
        
        return ans;
    }
};