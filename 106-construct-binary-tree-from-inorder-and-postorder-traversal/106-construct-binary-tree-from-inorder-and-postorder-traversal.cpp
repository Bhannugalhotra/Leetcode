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
    
    int find(vector<int> &v, int val, int left, int right){
        
        for(int i = left; i <= right;i++){
            if(v[i] == val)
                return i;
        }
        
        return -1;
    }
    TreeNode* build(int &idx, int left, int right,vector<int> &inorder , vector<int> &postorder)
    {
        if(left > right or idx < 0){
            return nullptr;
        }
        
        TreeNode *root = new TreeNode(postorder[idx]);
            idx--;
        
        int m = find(inorder, root -> val, left, right);
        
        root -> right = build(idx, m+1, right, inorder, postorder);
        
        root -> left = build(idx, left , m-1, inorder, postorder);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int idx = postorder.size()-1;
        
        return build(idx, 0, inorder.size()-1, inorder, postorder);
        
    }
};