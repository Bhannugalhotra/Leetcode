vector<string> table = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
       unordered_set<string> set;
        
        for(string &s : words)
        {
            string temp;
            
            for(char c : s)
                temp += table[c - 'a'];
            
            set.insert(temp);
        }
        
        return set.size();
    }
};