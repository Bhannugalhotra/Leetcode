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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      
        if(!root)
            return {};
        
        vector<vector<int>> ans;
        
        vector<int> currentLevel;
        bool leftToRight = true;
        queue<TreeNode*> q;
        
        q.push(root);
        q.push(nullptr);
        
        while(!q.empty()){
            
            root = q.front();  q.pop();
            
            if(!root){
                
                if(!q.empty())
                    q.push(nullptr);
                
                if(leftToRight){
                    ans.push_back(currentLevel);
                }
                
                else{
                    reverse(currentLevel.begin(), currentLevel.end());
                    ans.push_back(currentLevel);
                }
                
                currentLevel.clear();
                leftToRight = !leftToRight;
                
                continue;
            }
            
            currentLevel.push_back(root -> val);
            
            if(root -> left)
                q.push(root -> left);
            
            if(root -> right)
                q.push(root -> right);
        }
        
        return ans;
    }
};