bool isSame(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (root == NULL && subRoot == NULL)
        return true;
    else if (root == NULL || subRoot == NULL)
        return false;
    else if (root->val != subRoot->val)
        return false;
    else
        return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL)
        return false;
    if (isSame(root, subRoot))
        return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}