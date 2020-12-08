/*
    A binary tree, rather than binary search tree.
    bottom-up postorder traversal. In each recursive, maintain <min,max> which are the smallest and
    largest value among the subtree respectively.
    T:O(n)/S:O(n)
    -----
    Notice edge case [8]
*/
// Recursive Solution
class Solution {
public:
    int maxAncestorDiff(TreeNode* root)
    {
        int ans=0;
        if (root) help(root,ans);
        return ans;
    }

    // min, max of subtree
    pair<int,int> help(TreeNode *root, int &ans)
    {
        pair<int,int> ret{root->val,root->val};
        if (!root->left&&!root->right) return ret;
        if (root->left) {
            auto left=help(root->left,ans);
            ret.first=min(ret.first,left.first);
            ret.second=max(ret.second,left.second);
            ans=max(ans,max(abs(root->val-left.first),abs(root->val-left.second)));
        }
        if (root->right) {
            auto right=help(root->right,ans);
            ret.first=min(ret.first,right.first);
            ret.second=max(ret.second,right.second);
            ans=max(ans,max(abs(root->val-right.first),abs(root->val-right.second)));
        }
        return ret;
    }
};

// Iterative Solution
typedef tuple<TreeNode*, int, int> tup;
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) return 0;

        stack <tup> s;
        int max_val = root->val, min_val = root->val, max_diff = 0;
        s.push(make_tuple(root, root->val, root->val));
        while(!s.empty()){
            tup cur_tup = s.top();
            s.pop();

            auto node = get<0>(cur_tup);
            int cur_max = get<1>(cur_tup), cur_min = get<2>(cur_tup);
            if(node->right){
                s.push(make_tuple(node->right, max(node->right->val, cur_max), min(node->right->val, cur_min)));
            }

            if(node->left){
                s.push(make_tuple(node->left, max(node->left->val, cur_max), min(node->left->val, cur_min)));
            }

            if(node->left==nullptr && node->right== nullptr){
                if (cur_max - cur_min > max_diff) max_diff = cur_max - cur_min;
            }

        }

        return max_diff;
    }

};
