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
    
    bool IsValidBST(long long mn, long long mx,TreeNode* root){
        if(root == NULL)
            return true;
        int nodeValue =root->val;
        if(nodeValue<= mn || nodeValue >= mx)
        {
            return false;
        }
        return IsValidBST(mn,nodeValue , root->left) && IsValidBST(nodeValue,mx, root->right);
    }
    
    
public:
    bool isValidBST(TreeNode* root) {
        return IsValidBST(-1e10,1e10,root);
    }
};