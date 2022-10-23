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
    int ans=0;
    void solve(TreeNode* root, long sum){
        if(root == NULL)
            return;
        if(root->val==sum)
            ans++;
        solve(root->left,sum-root->val);
        solve(root->right,sum-root->val);
    }
public:
    int pathSum(TreeNode* root, long targetSum) {
        if(root!=NULL){
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
            solve(root,targetSum);
        }
        return ans;
    }
};