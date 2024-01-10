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
            height = calh(root);
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
    int amountOfTime(TreeNode* root, int start) {
        if(root->val==start){
            return calh(root);
        }
        fn(root,start);
        int h = height;
        height =  calh(sptr);
        return max(h,height);   
    }
};
