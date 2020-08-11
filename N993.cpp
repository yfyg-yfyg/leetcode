**
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
  
    bool dfs(TreeNode* parent, TreeNode* node, int depth,
             int* node_depth,  TreeNode** node_parent, int val) {
        if (node == NULL)
            return false;
       
        if (node->val == val) {
            *node_parent = parent;
            *node_depth = depth;
            return true;
        }
        else {
            depth = depth + 1;
            bool ret = dfs(node, node->left, depth, node_depth, node_parent, val);
            if (ret)
                return true;
            else 
                return dfs(node, node->right, depth, node_depth, node_parent, val);

        }
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {

        int node_depth_x = 0, node_depth_y = 0;
        TreeNode *node_parent_x = NULL, *node_parent_y = NULL;
        
        bool ret = dfs(NULL, root, 0, &node_depth_x, &node_parent_x, x);
         if (ret == false)
           return false;

        ret = dfs(NULL, root, 0, &node_depth_y, &node_parent_y, y);
        if (ret == false)
           return false;

        if (node_depth_x == node_depth_y && node_parent_x != node_parent_y)
            return true;
        else 
            return false;
        
        return true;
    }
};

