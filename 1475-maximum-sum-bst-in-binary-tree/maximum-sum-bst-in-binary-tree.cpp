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
    //bool f=true;

    #define ll long long 

    map<TreeNode*,bool> mp;

    pair<ll,ll> dfs(TreeNode* root){
        if(!root) return {1e12,-1e12};

        auto [l1,l2] = dfs(root->left);
        auto [r1,r2] = dfs(root->right);

        if(root->val <= l2 || root->val >= r1 ){
            mp[root]=false;
            return {-1e12,1e12};
        }
        else{
            mp[root] = true;
        }




        return {min({l1,r1,1LL*root->val}),max({l2,r2,1LL*root->val})};




    }
    int fans=0;
    int dfs1(TreeNode* root){
        if(!root) return 0;

        int left = dfs1(root->left);
        int right = dfs1(root->right);


        int ans = left+right+root->val;

        if(mp[root]){
            fans = max(ans,fans);
        }


        return ans;
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        dfs1(root);
        return fans;
    }
};