
class node
{
    public:
    vector<node*> arr;
    int data;
    int count;
    bool end_of_word;
    
    node() : count(0), end_of_word(false), data(-1) 
    {
        arr = vector<node*>(26, nullptr);
    }
};

class trie
{
	public:
	node *root;
	
	trie()
	{
		root = new node;
	}

	
	node* insert(node *root,string &s,int data,int i = 0)
	{
		if(!root)
		root = new node;
		
		if(i == s.length())
		root -> end_of_word = true, root -> data = data;
		
		else
		root -> arr[s[i] - 'a'] = insert(root -> arr[s[i] - 'a'],s,data,i+1);
		
		return root;
	}

	int search(node *root,string &suffix,string buffer)
	{

		if(root -> end_of_word){
        
            int l = suffix.size() - 1;
            int r = buffer.size() - 1;
            
            while(l >= 0 and r >= 0 and suffix[l] == buffer[r])
                l--, r--;
            
            if(l < 0)
                return root -> data;
            
            return -1;
        }
		
        int ans = -1;
        
        for(int i = 0; i < 26; i++)
        {
            if(!root -> arr[i])
                continue;
            
            char c = i + 'a';
            ans = max(ans, search(root -> arr[i], suffix, buffer + c));
        }
        
        return ans;
	}
	int process(string &prefix, string &suffix)
	{
        node *rt = root;
        string buffer;
        for(char c : prefix){
            
            if(!rt -> arr[c - 'a'])
                return -1;
            
            buffer += c;
            rt = rt -> arr[c - 'a'];
        }
        
        return search(rt,suffix, buffer);
	}
	
};



class WordFilter 
{
    trie tri;
public:
    WordFilter(vector<string>& words) {
        
        for(int i = 0; i < words.size(); i++)
            tri.insert(tri.root, words[i], i);
    }
    
    int f(string prefix, string suffix) {
        
        return tri.process(prefix, suffix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */