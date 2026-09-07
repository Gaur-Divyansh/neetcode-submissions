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
    void dfs(TreeNode* root, int maximum,int& count){
        if(!root) return;
        if(root->val >= maximum){
            maximum = root->val;
            count++;
        }
        dfs(root->left,maximum,count);
        dfs(root->right,maximum,count);
    }
public:
    int goodNodes(TreeNode* root) {
        int maximum = root->val, count = 0;
        dfs(root,maximum,count);
        return count;
    }
};
