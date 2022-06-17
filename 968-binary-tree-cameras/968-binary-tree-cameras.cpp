/**
 * Definition for a binary tree node::
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
    int ans = 0;
    enum class camera_state {HAS_CAMERA, COVERED, PLEASE_COVER}  ;
    
public:
    
    camera_state postorder(TreeNode *root){
        
        if(!root)
            return camera_state::COVERED;
        
        camera_state l = postorder(root -> left);
        camera_state r = postorder(root -> right);
        
        if(l == camera_state::PLEASE_COVER or r == camera_state::PLEASE_COVER){
            ans++;
            return camera_state::HAS_CAMERA;
        }
        
        if(l == camera_state::HAS_CAMERA or r == camera_state::HAS_CAMERA){
            return camera_state::COVERED;
        }
        
        return camera_state::PLEASE_COVER;
    }
    int minCameraCover(TreeNode* root) {
        
        camera_state x = postorder(root);
        
        if(x == camera_state::PLEASE_COVER)
            ans++;
        
        return ans;
    }
};