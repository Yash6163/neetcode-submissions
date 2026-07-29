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

vector<vector<int>> level(TreeNode* root){

    if(root==nullptr)return {};
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});

    vector<vector<int>>ans;

    int level=0;
    while(!q.empty()){
        vector<int>arr;
        while(!q.empty() && q.front().second==level){
            TreeNode* node=q.front().first;
            int curr_level=q.front().second;
            q.pop();
            arr.push_back(node->val);
            if(node->left)q.push({node->left,curr_level+1});
            if(node->right)q.push({node->right,curr_level+1});
        }
        ans.push_back(arr);
        level++;
    }
    return ans;
}
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        return level(root);
    }
};
