/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* p1;
    TreeNode* p2;
    TreeNode* ans;

    
    int solve(TreeNode* root){
        if(root== NULL)
            return 0;
        int res= solve(root->left)| solve(root->right);
        if(root==p1)
            res |= 1;
        else if(root==p2)
            res |= 2;
        if(res==3 && ans==NULL)
            ans = root;
        return res;
        
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        p1=p,p2=q,ans=NULL;
        solve(root);
        return ans;
        
    }
};