class Solution {
public:

    pair<int,int> fun(TreeNode *root){
        if(!root) return {0,0};
        pair<int,int> mans;
        pair<int,int> lma = fun(root->left);
        pair<int,int> rma = fun(root->right);
        mans.first = lma.second+rma.second+root->val;
        mans.second = max(lma.first,lma.second)+max(rma.first,rma.second);
        return mans;
    }
    int rob(TreeNode* root) {
        pair<int,int> ansf = fun(root);
        return max(ansf.first,ansf.second);
    }
};
