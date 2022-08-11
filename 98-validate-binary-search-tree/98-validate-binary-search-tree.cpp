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
    
    bool is_valid(TreeNode *root, long &prev)
    {
        if(!root) return true;
        
        bool left = is_valid(root -> left, prev);
        
        if(!left || root -> val <= prev)
            return false;
        
        prev = root -> val;
        
        return is_valid(root -> right, prev);
    }
    bool isValidBST(TreeNode* root)
    {
        long prev = -1e10;
        
        return is_valid(root , prev);
    }
};