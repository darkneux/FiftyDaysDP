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
    int ans = 0;
    pair<int,int> fun(TreeNode *root){
        if(!root)return {0,0};
        pair<int,int> l = fun(root->left);
        pair<int,int> r = fun(root->right);
        int ml=0,mr=0;
        if(root->left)ml = l.second+1;
        if(root->right)mr = r.first+1;
        pair<int,int > m = {ml,mr};
        // cout<<root->val<<": "<<ml<<"  "<<mr<<endl;
        ans = max({ans,ml,mr});
        return m;
    }
    int longestZigZag(TreeNode* root) {
        fun(root);
        return ans;
   }
};
