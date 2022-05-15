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
    int deepestLeavesSum(TreeNode* root) {
        
        if(!root)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        int sum = 0;
        int ans = sum;
        while(!q.empty())
        {
            root = q.front();  q.pop();
            
            if(!root)
            {
                if(!q.empty())
                    q.push(nullptr);
                
                ans = sum;
                sum = 0;
                
                continue;
            }
            
            sum += root -> val;
            
            if(root -> left)
                q.push(root -> left);
            
            if(root -> right)
                q.push(root -> right);
        }
        
        return ans;
    }
};