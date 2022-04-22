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
    
    
    TreeNode* BuildInPreorder(vector<int> &nums, int l, int r){
        
        if(l > r)
            return nullptr;
        
        int idx = max_element(nums.begin()+l, nums.begin()+r+1) - nums.begin();
        
        TreeNode *root = new TreeNode(nums[idx]);
        
        if(l == r)
            return root;
        
        root -> left = BuildInPreorder(nums, l , idx - 1);
        
        root -> right = BuildInPreorder(nums, idx + 1, r);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return BuildInPreorder(nums, 0, nums.size() - 1);
    }
};