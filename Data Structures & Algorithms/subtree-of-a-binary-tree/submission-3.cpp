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
    void serialize(TreeNode* node,string& out){
        if(!node){
            out += ",#";
            return;
        }
        out += "," + to_string(node->val);
        serialize(node->left,out);
        serialize(node->right,out);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s,t;
        serialize(root,s);
        serialize(subRoot,t);      
        return s.contains(t);
    }
};
