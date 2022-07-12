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
class Solution 
{
    unordered_map<int,int> freq;
    
public:
    
    int postorder(TreeNode *root){
        
        if(!root)
            return 0;
        
        int left = postorder(root -> left);
        
        int right = postorder(root -> right);
        
        int sum = left + right + root -> val;
        
        freq[sum]++;
        
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        postorder(root);
        
        int max_freq = 0;
        
        for(auto &it : freq)
            max_freq = max(max_freq , it.second);
        
        vector<int> ans;
        
        for(auto &it : freq){
            
            if(it.second == max_freq)
                ans.push_back(it.first);
        }
        
        return ans;
    }
};