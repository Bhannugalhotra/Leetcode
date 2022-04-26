
class Node{
    
    public:
    
    vector<Node*> child;
    bool isEndOfWord = false;
    
    Node() : child(26, nullptr) {};
};


class Trie{
    
    public:
    
    Node *root;
    
    Trie(){
        root = new Node();
    }
    
    void Insert(const string &s){
        
        Node *itr = root;
        
        for(char c : s){
            
            if(!itr -> child[c - 'a'])
                itr -> child[c - 'a'] = new Node();
            
            itr = itr -> child[c - 'a'];
        }
        
        itr -> isEndOfWord = true;
    }
    
    bool Search(const string &s){
        
        Node *itr = root;
        
        for(char c : s){
            
            if(!itr -> child[c - 'a'])
                return false;
            
            itr = itr -> child[c - 'a'];
        }
        
        return itr -> isEndOfWord == true;
    }
};

class Solution 
{
    vector<string> ans;
public:
    
    void Backtrack(string &s,int idx,Trie &trie, vector<string> &curr){
        
        if(idx >= s.size()){
            string x = curr[0];
            
            for(int i = 1; i < curr.size(); i++)
                x += " " + curr[i];
            
            ans.emplace_back(x);
           
            return;
        }
        
        string x;
        
        for(int i = idx; i < s.size(); i++){
            
            x += s[i];
            
            if(!trie.Search(x))
                continue;
            
            curr.push_back(x);
            
            Backtrack(s, i + 1, trie, curr);
            
            curr.pop_back();
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        Trie trie;
        
        for(string &x : wordDict){
            
            trie.Insert(x);
        }
        
        vector<string> curr;
        Backtrack(s, 0, trie, curr);
        
        return ans;
    }
};