class Solution {
public:
    
    string write_in_editor(string s)
    {
        int write_idx = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '#')
                write_idx = max(write_idx-1,0);
            
            else
                s[write_idx++] = s[i];
        }
        
        s.resize(write_idx);
        s.shrink_to_fit();
        
        return s;
    }
    bool backspaceCompare(string S, string T)
    {
        return write_in_editor(S) == write_in_editor(T);
    }
};