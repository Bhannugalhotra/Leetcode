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
public:
    
    void Inorder(TreeNode *root, vector<int> &a){
        
        if(!root)
            return ;
        
        Inorder(root -> left, a);
        
        a.push_back(root -> val);
        
        Inorder(root -> right , a);
    }
    
    TreeNode* BuildTree(int l, int r, vector<int> &a){
        
        if(l > r)
            return nullptr;
        
        int mid = l + ((r - l) >> 1);
        
        TreeNode *root = new TreeNode(a[mid]);
        
        if(l == r)
            return root;
        
        root -> left = BuildTree(l , mid - 1, a);
        
        root -> right = BuildTree(mid + 1, r, a);
        
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> a;
        
        Inorder(root, a);
        
        return BuildTree(0, a.size()-1, a);
    }
};