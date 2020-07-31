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
    
private:
    int ans = 0;

    void dfs(TreeNode *node, int L, int R){
        if (node == NULL)
            return; 

        if (node->val >= L && node->val <= R) {
            ans += node->val;
        }

        if (node->val > L) {
            dfs(node->left, L , R);
        }
        
        if (node->val < R) {
            dfs(node->right, L, R);
        }
    }



public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        dfs(root, L, R);
        return ans;
    }
};

