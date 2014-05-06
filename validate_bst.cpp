#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (root == NULL) return true;
        
        TreeNode *cur = root, *prev = NULL;
        while (cur != NULL) {
            if (cur->left == NULL) {
                if (prev != NULL && cur->val < prev->val) return false;
                prev = cur;
                cur = cur->right;
            } else {
                TreeNode *node = cur->left;
                while (node->right != NULL && node->right != cur) 
                    node = node->right;
                if (node->right == NULL) {
                    node->right = cur;
                    cur = cur->left;
                } else {
                    if (prev != NULL && cur->val < prev->val) return false;
                    node->right = NULL;
                    prev = cur;
                    cur = cur->right;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    // root->right = new TreeNode(15);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(20);
    cout << sol.isValidBST(root);

    return 0;
}