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
    
    // parents[0] = grandparent
    // parents[1] = parent
    
    void preorder(TreeNode *root, vector<int> parents ,int &sum){
        
        if(!root)
            return ;
        
        if(parents[0] == 0)
            sum += root -> val;
        
        parents[0] = parents[1];
        
        parents[1] = root -> val % 2;
        
        preorder(root -> left, parents, sum);
        
        preorder(root -> right, parents, sum);
        
    }
    int sumEvenGrandparent(TreeNode* root) {
        
        vector<int> parents{1,1};
        
        int sum = 0;
        
        preorder(root, parents, sum);
        
        return sum;
    }
};