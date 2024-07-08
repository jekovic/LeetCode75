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
    vector<int> inorder;
    void inorderTraversal(TreeNode* root, int key) {
        if(root == nullptr)
            return;
        inorderTraversal(root->left, key);
        if(root->val != key) {
            inorder.push_back(root->val);
        }
        inorderTraversal(root->right, key);
    }

    TreeNode* makeTree(int start, int end) {
        if(start >= inorder.size() || end < 0 || start > end) 
            return nullptr;

        TreeNode* temp = new TreeNode();
        if(start == end) {
            temp -> val = inorder[start];
            return temp;
        }
        int mid = (start + end)/2;
        temp->val = inorder[mid];
        temp->left = makeTree(start, mid-1);
        temp->right = makeTree(mid+1, end);
        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        inorderTraversal(root, key);

        int n = inorder.size();
        if(n==0) return nullptr;
        TreeNode* temp_root = new TreeNode();
        if(n == 1){
            temp_root->val = inorder[0];
            return temp_root;
        }
        temp_root->val = inorder[n/2];
        temp_root->left = makeTree(0, (n/2)-1);
        temp_root->right = makeTree((n/2)+1, n);
    
        return temp_root;
    }
};