/***** Fourth Visit *****/
/*
    preorder to find max path sum start from root node
    left=preorder(root->left)
    right=preorder(root->right)
    max(left,right)+val
    -----
    post order to get max path sum from the current root
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int maxPathSum(TreeNode* root)
    {
        int ans=INT_MIN;
        postDFS(root,ans);
        return ans;
    }

    int postDFS(TreeNode *root, int &ans)
    {
        if (!root) return 0;
        int left=postDFS(root->left,ans);
        int right=postDFS(root->right,ans);
        int ret=max(root->val,max(left,right)+root->val);
        ans=max(ans,max(ret,left+right+root->val));
        return ret;
    }
};

/***** Third Visit *****/
class Solution {
public:
    int maxPathSum(TreeNode* root)
    {
        int ans=INT_MIN;
        postDFS(root,ans);
        return ans;
    }

    int postDFS (TreeNode *root, int &ans)
    {
        if (!root) return 0;
        int left=max(postDFS(root->left,ans),0);
        int right=max(postDFS(root->right,ans),0);
        int cmax=max(left,right)+root->val;
        ans=max(ans,root->val+left+right);
        return cmax;
    }
};
/***** Second Visit *****/
/*
    recursive approach.
    help(TreeNode* root): the max path sum including root node.
    left = maxPathSum(root->left)
    right = maxPathSum(root->right)
    maxPathSum(root)=max(left,right,left+right-root->val,root->val
*/
class Solution {
public:
    int ans=INT_MIN;
    int maxPathSum(TreeNode* root) {
        help(root);
        return ans;
    }

    int help(TreeNode* root)
    {
        if (!root->left&&!root->right) {
            ans=max(ans,root->val);
            return root->val;
        }
        else if (!root->left) {
            int right=help(root->right);
            ans=max(max(ans,right+root->val),root->val);
            return max(right+root->val,root->val);
        }
        else if (!root->right) {
            int left=help(root->left);
            ans=max(max(ans,left+root->val),root->val);
            return max(left+root->val,root->val);
        }
        else {
            int left=help(root->left);
            int right=help(root->right);
            int ret=max(max(left,right)+root->val,root->val);
            ans=max(max(max(ret,ans),max(left,right)),left+right+root->val);
            return ret;
        }
    }
};

/***** First Visit *****/
class Solution {
public:
    int ans=INT_MIN;
    int maxPathSum(TreeNode* root)
    {
        /*
            bottom up
            if (no child) return root->val;
            record ans=max(ans,left,right,left+right+root->val)
            return max path from root to leaf
            Apply postorder traversal
            T:O(N), S:O(logN)
        */
        help(root);
        return ans;
    }

    int help(TreeNode* root)
    {
        if (!root) return 0;
        if (!root->left&&!root->right) {
            ans=max(ans, root->val);
            return root->val;
        }
        else {
            int left = help(root->left);
            int right = help(root->right);
            int nonCross=max(max(left,right)+root->val,root->val);
            int cross = left+right+root->val;
            ans=max(ans,max(nonCross,cross));
            return nonCross;
        }
    }
};

/********************** Neat code **********************/
/*
    If pathSum is negative, CLIP TO ZERO
*/
class Solution {
    int sum;
public:
    int maxPathSum(TreeNode* root) {
        sum=INT_MIN;
        help(root);
        return sum;
    }

    /*** return the max-value-ended-at-root-node ***/
    int help(TreeNode* root){
        if(!root)   return 0;
        int left = max(0, help(root->left));
        int right = max(0, help(root->right));
        /*** key parts : embedding the max-value-find in the recursion process ***/
        sum = max(sum, left+right+root->val);
        /*** get the max-value-ended-at-root ***/
        return max(left, right)+root->val;
    }
};
