class Solution {
public:
    int minPartitions(string n) {
        
        char max_num = *max_element(begin(n), end(n));
        
        return max_num - '0';
    }
};