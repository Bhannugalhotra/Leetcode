class Solution {
public:
    
  
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,int> map;
        
        int ans = 0;
        for(int num : nums){
            
            if(map[num] > 0)
                continue;
            
            int left_count = map[num-1];
            
            int right_count = map[num+1];
           
            int total_count = left_count + right_count + 1;
            
            map[num - left_count] = total_count;
            map[num + right_count] = total_count;
            map[num] = total_count;
            
            ans = max(ans, total_count);
            
        }
        
        return ans;
    }
};