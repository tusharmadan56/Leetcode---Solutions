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
    void dfs(TreeNode* root){
        if(!root) return ;
        TreeNode* temp = root->right;
         TreeNode* ok = root->left;
        if(root->left){
            
            root->right = root->left; ;
            root->left = NULL;
            
             while(ok->right) {
            ok=ok->right;
        }
        ok->right = temp;
            
        }
       
       
        dfs(root->right);



    }
    void flatten(TreeNode* root) {
        dfs(root);
    }
};