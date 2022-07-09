class Solution 
{
    int count = 0;
public:
    
    vector<int>  postorder(TreeNode *root, int target){
        
        if(!root)
            return {};
        
        if(!root -> left and !root -> right){
            
            if(root -> val == target)
                count++;
            
            return {root -> val};
            
        }
        vector<int>  left = postorder(root -> left, target);
        
        vector<int>  right = postorder(root -> right, target);
        
        vector<int>  ans;
        
        for(int i : left){
            if(root -> val + i == target)
                count++;
            
            ans.push_back(root -> val + i);
        }
        
        
        for(int i : right){
            if(root -> val + i == target)
               count++;
            
            ans.push_back(root -> val + i);
        }
        
        if(root -> val == target)
            count++;
        
        ans.push_back(root -> val);
        
       
        return ans;
        
        
    }
    
    void preorder(TreeNode *root, int target, unordered_map<long,int> &prefix_sum, long sum){
        
        if(!root)
            return ;
        
        sum += root -> val;
       
        
        if(sum == target)
            count++;
        
        count += prefix_sum[sum - target];
        
        prefix_sum[sum]++;
        
        preorder(root -> left, target, prefix_sum, sum);
        preorder(root -> right, target, prefix_sum, sum);
        
        prefix_sum[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        //postorder(root, targetSum);
        
        unordered_map<long,int> prefix_sum;
        
      //  prefix_sum[0] = 1;
        preorder(root, targetSum, prefix_sum, 0);
        return count;
    }
};