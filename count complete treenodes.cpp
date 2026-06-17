#include<iostream>
using namespace std;
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (leftHeight == rightHeight) {
            // left subtree is perfect, has 2^leftHeight - 1 nodes
            return (1 << leftHeight) + countNodes(root->right);
        } else {
            // right subtree is perfect (one level shorter), has 2^rightHeight - 1 nodes
            return (1 << rightHeight) + countNodes(root->left);
        }
    }

private:
    int getHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }
};