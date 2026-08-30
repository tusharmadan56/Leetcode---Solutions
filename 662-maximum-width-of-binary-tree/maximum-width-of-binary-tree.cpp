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

    #define ll long long

    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0LL});

        ll ans = 0;

        while(!q.empty()){
            int s = q.size();

            ll base = q.front().second;

            for(int i=0;i<s;i++){
                auto [x,y] = q.front();
                q.pop();

                y-= base;

                if(x->left){
                    q.push({x->left,2LL*y});
                }
                if(x->right){
                    q.push({x->right,2LL*y+1});
                }

                ans = max(ans , y+1);


            }
        }

        return ans;
    }
};