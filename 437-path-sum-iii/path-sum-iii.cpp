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
    void dfs(TreeNode* t, int targetsum, int& cnt, unordered_map<long long ,int>& mp , long long sum) {
        if(t == nullptr) return;
        
        sum += t->val;

        if(sum == targetsum) cnt++;
        
        if(mp.find(sum - targetsum) != mp.end()) // find sum - targetsum 
            cnt += mp[sum-targetsum];
        
        mp[sum]++;

        dfs(t->left, targetsum, cnt, mp, sum);
        dfs(t->right, targetsum, cnt, mp, sum);

        mp[sum]--;

    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        int cnt = 0;
        unordered_map<long long, int> m;
        
        dfs(root, targetSum, cnt, m, 0);

        return cnt;
    }
};