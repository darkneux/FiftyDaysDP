/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode *sptr = NULL;
    TreeNode *pptr = NULL;
    int height = 0;
    int calh(TreeNode *root){
        if(!root)return -1;
        return max(calh(root->left),calh(root->right))+1;
    }

    TreeNode* fn(TreeNode *root,int start){
        if(!root)return root;
        if(root->val==start){
            // height = calh(root);
            sptr=root;pptr=root;
            return root;
        }
        
        TreeNode *l = fn(root->left,start);
        if(l){
            if(!pptr->left)
            pptr->left = root;
            else pptr->right =root;
            
            pptr = root ;
            root->left = NULL;
            return root;
        }
        TreeNode *r = fn(root->right,start);
        if(r){
            if(!pptr->right)
            pptr->right =root;
            else pptr->left = root;
            pptr= root;
            root->right = NULL;
             return root;
        }
        return NULL;
    } 


    void fun(TreeNode *root,unordered_set<int>&ans,int plevel,int k){
        if(!root)return ;
      if(plevel==k){
          ans.insert(root->val);
         return;
      }
      fun(root->left,ans,plevel+1,k);
      fun(root->right,ans,plevel+1,k);

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int start = target->val;
        unordered_set<int> ans;
        fun(target,ans,0,k);
        fn(root,start);
        fun(target,ans,0,k);
        vector<int> rans;
        for(int val:ans)rans.push_back(val);
        return rans;
    }
};
