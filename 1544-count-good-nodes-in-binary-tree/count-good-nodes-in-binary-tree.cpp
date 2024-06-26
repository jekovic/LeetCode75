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
    int res = 1;

    void dfs(TreeNode* t, int max_val) {
        if(t->left == nullptr and t->right == nullptr) {
            return;
        }
        else if(t->left == nullptr) {
            if(t->right->val >= max_val) {
                res++;
                dfs(t->right,t->right->val);
            }
            else{
                dfs(t->right, max_val);
            }
        }
        else if(t->right == nullptr) {
            if(t->left->val >= max_val) {
                res++;
                dfs(t->left,t->left->val);
            }
            else{
                dfs(t->left, max_val);
            }
        }
        else{
            if(t->right->val >= max_val) {
                res++;
                dfs(t->right,t->right->val);
            }
            else{
                dfs(t->right, max_val);
            }
            if(t->left->val >= max_val) {
                res++;
                dfs(t->left,t->left->val);
            }
            else{
                dfs(t->left, max_val);
            }
        }
    }

    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        dfs(root, root->val);

        return res;
    }
};