bool isSame(struct TreeNode* pleft, struct TreeNode* pright)
{
    if (pleft == NULL && pright == NULL)
        return true;
    else if (pleft == NULL || pright == NULL)
        return false;
    else if (pleft->val != pright->val)
        return false;
    else
        return isSame(pleft->left, pright->right) && isSame(pleft->right, pright->left);
}
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return isSame(root->left, root->right);
}