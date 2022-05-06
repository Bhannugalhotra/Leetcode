class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack< pair<char,int> > Stack;
        
        int count = 1;
        char prev = s[0];
        
        for(int i = 1; i < s.size(); i++){
            
            if(s[i] == prev)
                count++;
            
            else{
                Stack.push({prev, count});
                count = 1, prev = s[i];
            }
            
            if(count == k){
                
                if(!Stack.empty()){
                    prev = Stack.top().first;
                    count = Stack.top().second;
                    Stack.pop();
                }
                
                else count = 0, prev = s[i];
            }
        }
        
        if(count > 0)
            Stack.push({prev, count});
        
        string ans;
        
        while(!Stack.empty()){
            
            char curr = Stack.top().first;
            int count = Stack.top().second;
            Stack.pop();
            
            while(count--)
                ans += curr;
        }
        
        reverse(begin(ans), end(ans));
        
        return ans;
    }
};