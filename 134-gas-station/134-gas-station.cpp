class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int defecit = 0;
        int curr_fuel = 0;
        int start_idx = 0;
        for(int i = 0; i < gas.size(); i++){
    
            curr_fuel += gas[i];
            
            curr_fuel -= cost[i];
            
            if(curr_fuel < 0){
                start_idx = i + 1;
                defecit += abs(curr_fuel);
                curr_fuel = 0;
            }
        }
        
        if(curr_fuel < defecit)
            return -1;
        
        return start_idx;
    }
};