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

unordered_map<int,int> traverse(vector<int>&arr){
    int n=arr.size();
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]=i;
    }
    return mpp;
}
TreeNode* build(vector<int>&preorder,vector<int>&inorder,int in_start,int in_end,unordered_map<int,int>&mpp,int &index){
    if(in_start>in_end)return nullptr;
    int root_val=preorder[index];//initially 0
    TreeNode* root=new TreeNode(root_val);
    index++;
    root->left=build(preorder,inorder,in_start,mpp[root->val]-1,mpp,index);
    root->right=build(preorder,inorder,mpp[root->val]+1,in_end,mpp,index);
    return root;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp=traverse(inorder);
        int index=0;
        return build(preorder,inorder,0,inorder.size()-1,mpp,index);
    }
};
