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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root;
        TreeNode* toInsert = new TreeNode(val);
        if(!root) return toInsert;
        while (true) {
            if (node->val < val) {
                if (node->right)
                    node = node->right;
                else{
                    node->right = toInsert;
                    break;
                }

            } else {
                if (node->left)
                    node = node->left;
                else{
                    node->left = toInsert;
                    break;
                }
            }
        }
        return root;
    }
};