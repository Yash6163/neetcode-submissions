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

bool path(TreeNode* root, TreeNode* target, vector<TreeNode*>& route) {
    if (root == nullptr) return false;
    route.push_back(root);
    if (root->val == target->val)
        return true;
    if (path(root->left, target, route) ||
        path(root->right, target, route)) {
        return true;
    }
    route.pop_back();
    return false;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //get path to both the nodes
        vector<TreeNode*>path1,path2;
        bool v1=path(root,p,path1);
        bool v2=path(root,q,path2);

        int i=0;
        while(i<path1.size() && i<path2.size() && path1[i]==path2[i]){
            i++;
        }
        return path1[i-1];
    }
};
