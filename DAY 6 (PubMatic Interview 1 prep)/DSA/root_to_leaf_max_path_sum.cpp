#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

int maxPathSum(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int left = maxPathSum(root->left);
    int right = maxPathSum(root->right);

    return root->val + max(left, right);
}

int main()
{
    TreeNode *n1 = new TreeNode(5);
    TreeNode *n2 = new TreeNode(6);
    TreeNode *n3 = new TreeNode(2, nullptr, n1);
    TreeNode *n4 = new TreeNode(3, n2, nullptr);
    TreeNode *n5 = new TreeNode(2, n3, n4);
    TreeNode *n6 = new TreeNode(4);
    TreeNode *root = new TreeNode(1, n5, n6);

    cout << maxPathSum(root) << endl;
    return 0;
}