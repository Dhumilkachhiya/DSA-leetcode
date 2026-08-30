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
    TreeNode* makeTree(vector<int>& preorder, int preStart, int preEnd,
                       vector<int>& inorder, int inStart, int inEnd,
                       unordered_map<int, int>& mp) {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int posinorder = mp[root->val];
        root->left =
            makeTree(preorder, preStart + 1, preStart + posinorder - inStart,
                     inorder, inStart, posinorder - 1, mp);
        root->right = makeTree(preorder, preStart + posinorder - inStart + 1,
                               preEnd, inorder, posinorder + 1, inEnd, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return makeTree(preorder, 0, n - 1, inorder, 0, n - 1, mp);
    }
};