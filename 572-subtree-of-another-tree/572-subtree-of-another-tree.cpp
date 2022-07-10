/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    string hash;
    bool ans = false;
public:
    
    string build_hash(TreeNode *root){
        
        if(!root){
            return "#";
        }
        
        return  build_hash(root -> left) + ',' + build_hash(root -> right) + ',' + to_string(root -> val);
    }
    
    string postorder(TreeNode *root){
        
        if(!root)
            return "#";
        
        string s = postorder(root -> left) + ',' + postorder(root -> right) + ',' + to_string(root -> val);
        
        if(s == hash){
            ans = true;
        }
        
       
        return s;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        hash = build_hash(subRoot);
        
        postorder(root);
        
        
        return ans;
    }
};