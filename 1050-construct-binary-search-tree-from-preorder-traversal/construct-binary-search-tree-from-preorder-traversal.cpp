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
vector<int> preorder;
vector<int> inorder;
int n;
map<int,int> mp;

int i=0;

    TreeNode* dfs(int l,int r){
        if(l>r || i>=n){
            return NULL;
        }
        int val = preorder[i];
        int ok = mp[preorder[i]];
        //cout<<ok<<" "<<val<<endl;
        i++;
        TreeNode* root = new TreeNode(val);

        root->left = dfs(l,ok-1);
        root->right = dfs(ok+1 , r);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        this->preorder = preorder;
        this->inorder = preorder;

        sort(inorder.begin(),inorder.end());

        this->n = preorder.size();

        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }

        return dfs(0,n-1);
    }
};