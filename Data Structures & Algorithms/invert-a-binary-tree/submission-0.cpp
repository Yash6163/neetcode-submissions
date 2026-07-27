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

TreeNode* traverse(TreeNode* root){
    if (root==nullptr)return nullptr;
    swap(root->left,root->right);
    traverse(root->left);
    traverse(root->right);
    return root;
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return traverse(root);
    }
};
