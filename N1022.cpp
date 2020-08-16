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
    vector<int> path_nums;

    int convertToNumber(const vector<int> &num_vec) {
        int len = num_vec.size();
        int i = 0, sum = 0;
        while(i < len) {
            sum += num_vec[i] << (len - 1 - i);
            i ++;
        }
         
        return sum;
    }

    void dfs(TreeNode* node, vector<int> &num_vec) {
        if (node->left == NULL && node->right == NULL) {
            num_vec.push_back(node->val);
            int number = convertToNumber(num_vec);
            path_nums.push_back(number);
            num_vec.pop_back();
            return;
        }
        else {
            num_vec.push_back(node->val);

            if (node->left != NULL)
                dfs(node->left, num_vec);

            if (node->right != NULL)
                dfs(node->right, num_vec);

            num_vec.pop_back();
        }
       
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        vector<int> num_vec;

        dfs(root, num_vec);

        int sum = 0;
        for(int i = 0; i < path_nums.size(); i ++) {
            sum += path_nums[i];
        }

        return sum;
    }
};

