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
   // struct TreeNode *cur = NULL;

private:
     void MidOrder(TreeNode *node, struct TreeNode **cur) {
        if (node == NULL)
             return;
        
         MidOrder(node->left, cur);
         (*cur)->right = node;
         node->left = NULL;
         *cur = node;
         MidOrder(node->right, cur);
     }

public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* tree_root = new struct TreeNode();
        TreeNode* cur = tree_root;
        MidOrder(root, &cur);

       return tree_root->right;
    }
};


class Solution {
    struct TreeNode *cur = NULL;

private:
     void MidOrder(TreeNode *node) {
        if (node == NULL)
             return;
        
         MidOrder(node->left);
         cur->right = node;
         node->left = NULL;
         cur = node;
         MidOrder(node->right);
     }

public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* tree_root = new struct TreeNode();
        cur = tree_root;
        MidOrder(root);

       return tree_root->right;
    }
};
