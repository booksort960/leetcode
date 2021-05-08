//方法1
bool Treehight(struct TreeNode* root, int* hight)
{
    if (root == NULL)
    {
        *hight = 0;
        return true;
    }

    int lefthight = 0;
    if (Treehight(root->left, &lefthight) == false)
        return false;
    int righthight = 0;
    if (Treehight(root->right, &righthight) == false)
        return false;
    *hight = fmax(lefthight, righthight) + 1;

    return abs(lefthight - righthight) < 2;
}
bool isBalanced(struct TreeNode* root) {
    int hight = 0;
    return Treehight(root, &hight);
}
//方法2
int TreeHight(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    int LeftHight = TreeHight(root->left);
    int RightHight = TreeHight(root->right);
    return fmax(LeftHight, RightHight) + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return abs(TreeHight(root->left) - TreeHight(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
}
//方法3
int TreeHight(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    int LeftHight = TreeHight(root->left);
    int RightHight = TreeHight(root->right);
    if (LeftHight == -1 || RightHight == -1)
        return -1;
    if (abs(LeftHight - RightHight) > 1)
        return -1;
    return fmax(LeftHight, RightHight) + 1;
}
bool isBalanced(struct TreeNode* root) {
    return TreeHight(root) >= 0;
}