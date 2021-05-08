struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
        return NULL;
    struct TreeNode* pleft = root->left;
    struct TreeNode* pright = root->right;
    root->left = invertTree(pright);
    root->right = invertTree(pleft);
    return root;
}