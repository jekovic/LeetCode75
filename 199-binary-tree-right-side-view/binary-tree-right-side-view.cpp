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
    //the righetest node in each level, not just right side! 
    vector<int> res;
    vector<vector<int>> tree;
    int level = 0;

    void dfs(TreeNode* root, int cnt){
        if(!root) {
            level = max(cnt, level);
            return;
        }
        cnt++;
        dfs(root->left, cnt);
        dfs(root->right, cnt);
    }

    void bfs(TreeNode* root, int idx) {
        if(!root) return;
        tree[idx].push_back(root->val);
        idx++;
        bfs(root->left, idx);
        bfs(root->right, idx);
    }

    void solve(){
        for(int i=0; i != tree.size(); i++){
            res.push_back(tree[i].back());
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        if(!root) return res;

        dfs(root, 0);

        tree.assign(level, vector<int>(0, 0));
        bfs(root, 0);
        solve();
        return res;
    }
};