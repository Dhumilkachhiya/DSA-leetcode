/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* makeTree(vector<int>& postorder, int postStart, int postEnd,
                       vector<int>& inorder, int inStart, int inEnd,
                       unordered_map<int, int>& mp) {
        if (postStart > postEnd || inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int posinorder = mp[root->val];
        root->left =
            makeTree(postorder, postStart, postStart + posinorder - inStart-1,
                     inorder, inStart, posinorder - 1, mp);
        root->right = makeTree(postorder, postStart + posinorder - inStart,
                               postEnd - 1, inorder, posinorder + 1, inEnd, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return makeTree(postorder, 0, n - 1, inorder, 0, n - 1, mp);
    }
};