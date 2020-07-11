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
    vector<int> getLeaves(TreeNode* root) {
        vector<int>  leaves;
        vector<struct TreeNode*> nodes;

        nodes.push_back(root);

        while(true) {
            root = nodes.back();
            nodes.pop_back();
            while(root->left != NULL) {
                if (root->right != NULL)
                    nodes.push_back(root->right);
                root = root->left;
            }
            if (root->right != NULL) {
               nodes.push_back(root->right);
            }
            else {
                leaves.push_back(root->val);
            }

            if (nodes.size() == 0) {
                break;
            }
        }

       return leaves;
     }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> leaves1 = getLeaves(root1);
        vector<int> leaves2 = getLeaves(root2);

        if (leaves1.size() != leaves2.size())
            return false;
        else {
            for(int i = 0; i < leaves1.size(); i ++) {
                if (leaves1[i] != leaves2[i]) 
                    return false;
            }

            return true;
        }
    }
};
