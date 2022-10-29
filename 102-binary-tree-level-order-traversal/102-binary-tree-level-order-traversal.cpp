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
    vector<vector<int>> ans;
    void solve(TreeNode* node, int depth){
        if(node== NULL)
            return;
        if(ans.size()==depth){
            ans.push_back(vector<int>());
        }
        ans[depth].push_back(node->val);
        solve(node->left,depth+1);
        solve(node->right,depth+1);
        
    }
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};