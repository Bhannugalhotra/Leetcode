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
    
    int Postorder(TreeNode *root, int &maxSum){
        
        if(!root)
            return 0;
        
        int left = Postorder(root -> left, maxSum);
        int right = Postorder(root -> right, maxSum);
        
        maxSum = max(maxSum , left + right + root -> val);
        
        int currSum = max(left + root -> val, right + root -> val);
        currSum = max(currSum, root -> val);
        
        maxSum = max(maxSum, currSum);
        
        return currSum;
    }
    int maxPathSum(TreeNode* root) {
        
        int maxSum = INT_MIN;
        
        Postorder(root, maxSum);
        
        return maxSum;
    }
};