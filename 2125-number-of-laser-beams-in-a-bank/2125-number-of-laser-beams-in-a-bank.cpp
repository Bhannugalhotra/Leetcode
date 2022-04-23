class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int prev = 0;
        int ans = 0;
        
        for(int i = 0; i < bank.size(); i++){
            
            int count = std:: count(begin(bank[i]), end(bank[i]), '1');
            
            cout << count<<endl;
            if(count == 0)
                continue;
            
            ans += prev * count;
            prev = count;
        }
        
        return ans;
    }
};