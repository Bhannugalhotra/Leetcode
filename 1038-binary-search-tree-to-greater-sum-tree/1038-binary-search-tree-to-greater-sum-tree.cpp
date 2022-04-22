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
    
    void InvertedInorder(TreeNode *root,int &sum){
        
        if(!root)
            return ;
        
        InvertedInorder(root -> right,sum);
        
        
        root -> val += sum;
        sum = root -> val;
        
        InvertedInorder(root -> left, sum);
        
    }
    TreeNode* bstToGst(TreeNode* root) {
        
        int sum = 0;
        InvertedInorder(root, sum);
        
        return root;
    }
};