class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
    
        int steps = 0;
        int currCapacity = capacity;
        
        for(int i = 0 ; i < plants.size(); i++){
            
            if(plants[i] <= currCapacity){
                currCapacity -= plants[i];
                steps++;
            }
            
            else{
                steps += i + i + 1;
                currCapacity = capacity - plants[i];
            }
        }
        
        return steps;
    }
};