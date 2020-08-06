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
    int val;
    bool ans = true;

    void dfs(TreeNode* node) {
        if (node == NULL) 
            return; 

        if (node->val != val) {
            ans = false;
            return;
        }
        
        dfs(node->left);
        if (ans == false)
            return;
        
        dfs(node->right);
        if (ans == false)
            return;

    }
public:
    bool isUnivalTree(TreeNode* root) {
        val = root->val;

        dfs(root);

        return ans;

    }
};

