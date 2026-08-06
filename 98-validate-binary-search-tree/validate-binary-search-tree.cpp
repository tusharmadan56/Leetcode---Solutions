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
    bool f=true;

    #define ll long long 

    pair<ll,ll> dfs(TreeNode* root){
        if(!root) return {1e12,-1e12};

        auto [l1,l2] = dfs(root->left);
        auto [r1,r2] = dfs(root->right);

        if(root->val <= l2 || root->val >= r1 ){
            f=false;
            return {-1,-1};
        }




        return {min({l1,r1,1LL*root->val}),max({l2,r2,1LL*root->val})};




    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        dfs(root);
        return f;

    }
};