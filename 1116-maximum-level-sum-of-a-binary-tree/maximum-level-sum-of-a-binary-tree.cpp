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
    int end = 0;

    void dfs(TreeNode* t, int cnt) {
        if(t == nullptr) {
            end = max(end, cnt);
            return;
        }
        cnt++;
        dfs(t->left, cnt);
        dfs(t->right, cnt);
    }

    void bfs(TreeNode* t, int idx, vector<int>& v) {
        if(t == nullptr) return;
        v[idx] += t->val;
        idx++;
        bfs(t->left, idx, v);
        bfs(t->right, idx, v);
    }
    
    int solve(vector<int>& v) {
        int res = 0;
        int max_ = 1e6* (-1);
        for(int i=1; i != v.size(); i++) {
            if(max_ < v[i]){
                max_ = v[i];
                res = i;
            }
        }
        return res;
    }

    int maxLevelSum(TreeNode* root) {
        dfs(root, 1);
        vector<int> v(end, 0);
       // v[1] = root->val;

        bfs(root, 1, v);

        int result = solve(v);

        return result;
    }
};