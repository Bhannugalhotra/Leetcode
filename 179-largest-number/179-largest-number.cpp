class Solution {
public:
    string largestNumber(vector<int>& nums)
    {
        if(nums.size() == 0)
            return "";
        
        vector<string> s;
        
        int zeros = 0;
        for(int i : nums)
        {
            if(i == 0)
                zeros++;
            
            else s.push_back(to_string(i));
        }
        
        if(zeros == nums.size())
            return "0";
        
        auto comp = [](const string &s1, const string &s2)
        {
            string x = s1 + s2;
            string y = s2 + s1;
            
            return x > y; 
        };
        
        sort(begin(s),end(s), comp);
        
        string ans;
        
        for(string& i : s)
            ans += i;
        
        for(int i = 0; i < zeros; i++)
            ans += '0';
        
        return ans;
    }
};