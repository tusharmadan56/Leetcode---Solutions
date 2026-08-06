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
    int fans = -1e9 ;

    int dfs(TreeNode* root){
        if(!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right );

        fans = max(fans , root->val + max(0,left) + max(0,right));

        return root->val+max(0,max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return fans;
    }
};