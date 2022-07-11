/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
    unordered_map<Node*,Node*> seen;
public:
    
    Node* dfs(Node *root)
    {
        if(seen.count(root))
            return seen[root];
        
        Node *newnode = new Node(root -> val);
        
        seen[root] = newnode;
        for(Node* v : root -> neighbors)
            newnode -> neighbors.push_back(dfs(v));
        
        return newnode;
    }
    Node* cloneGraph(Node* node)
    {
        if(!node)
            return NULL;
        
        return dfs(node);
        
    }
};