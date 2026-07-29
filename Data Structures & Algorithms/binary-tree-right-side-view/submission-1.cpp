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
vector<int> level(TreeNode* root){
    if(root==nullptr)return {};
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    map<int,TreeNode*>mpp;
    vector<int>ans;
    while(!q.empty()){
        TreeNode* node=q.front().first;
        int level=q.front().second;
        q.pop();
        if(mpp.find(level)==mpp.end()){
            mpp[level]=node;
        }
        if(node->right)q.push({node->right,level+1});
        if(node->left)q.push({node->left,level+1});
    }

    for(auto it : mpp){
        ans.push_back(it.second->val);
    }
    return ans;
}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        return level(root);
    }
};
