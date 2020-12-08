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
 *

/***** Second Visit *****/
/*
    inorder checking
    T:O(n)/S:O(n)
    -----
    Notice that not only check current node's left/right but also need to check its predecessor and successor.
*/
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        double start=(double)INT_MIN-1.0;
        return help(root,start);
    }

    bool help(TreeNode *node, double &val)
    {
        if (!node) return true;
        if(!help(node->left,val)) return false;
        if(val>=node->val) return false;
        val=node->val;
        if(!help(node->right,val)) return false;
        return true;
    }
};

/***** First Visit *****/
class Solution {
public:

    bool isValidBST(TreeNode* root)
    {
        if (!root) return true;
        bool left = isValidBST(root->left);
        bool right = isValidBST(root->right);

        bool checkLeft=true, checkRight=true;
        if (root->left&&root->left->val>=root->val) checkLeft=false;
        if (root->right&&root->right->val<=root->val) checkRight=false;

        bool checkpred=true, checksucc=true;
        TreeNode *pred=0, *succ=0;
        pred=root->left;
        while(pred&&pred->right) pred=pred->right;
        succ=root->right;
        while(succ&&succ->left) succ=succ->left;
        if(pred&&root->val<=pred->val) checkpred=false;
        if(succ&&root->val>=succ->val) checksucc=false;
        return checkLeft&&checkRight&&left&&right&&checkpred&&checksucc;
    }
};
/*
[2,1,3]
[5,1,4,null,null,3,6]
[1,1]
[10,5,15,null,null,6,20]
*/
