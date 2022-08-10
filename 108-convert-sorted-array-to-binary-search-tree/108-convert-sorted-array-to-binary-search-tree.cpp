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
    
    TreeNode* create_tree(vector<int> &a, int l, int r)
    {
        if(l > r)
            return nullptr;
        
        int mid = l + ((r - l) >> 1);
        
        TreeNode *root = new TreeNode(a[mid]);
        
        if(l == r)
            return root;
        
        root -> left = create_tree(a, l, mid-1);
        
        root -> right = create_tree(a, mid+1, r);
        
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
     
        return create_tree(nums, 0, nums.size()-1);
    }
};