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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return track(p,q);
    }
    bool track(TreeNode* r1,TreeNode* r2){
        if(r1==nullptr && r2==nullptr)return true;
        else if (r1==nullptr && r2!=nullptr)return false;
        else if (r1!=nullptr && r2==nullptr)return false;
        if(r1->val != r2->val)return false;
        return track(r1->left,r2->left) && track(r1->right,r2->right);
    }
};
