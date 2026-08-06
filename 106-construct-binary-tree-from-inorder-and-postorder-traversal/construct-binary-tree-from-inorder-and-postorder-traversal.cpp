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
    vector<int> inorder;
     vector<int> postorder;
     int n;
     map<int,int> in;
     int i;;
    TreeNode* dfs(int l,int r){
        //cout<<l<<" "<<r<<endl;
        if(l>r || i<0) return NULL;
        //cout<<l<<" "<<r<<endl;

        int ok = in[postorder[i]];
        int val = postorder[i];
        i--;

       // cout<<ok<<" "<<val<<endl;

        TreeNode* root = new TreeNode(val);
    root->right = dfs(ok+1 , r);
        root->left = dfs(l,ok-1);
        
        

        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n=inorder.size();
        this->i = n-1;
        for(int i=0;i<n;i++){
            in[inorder[i]]=i;
        }

        this->postorder=postorder;
        this->inorder=inorder;

        return dfs(0,n-1);
    }
};