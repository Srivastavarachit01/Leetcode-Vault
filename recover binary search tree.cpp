class Solution {
 public:
  void recoverTree(TreeNode* root) {
    inorder(root);
    swap(x, y);
  }

 private:
  TreeNode* pred = nullptr;
  TreeNode* x = nullptr;  // the first wrong node
  TreeNode* y = nullptr;  // the second wrong node

  void inorder(TreeNode* root) {
    if (root == nullptr)
      return;

    inorder(root->left);

    if (pred && root->val < pred->val) {
      y = root;
      if (x == nullptr)
        x = pred;
      else
        return;
    }
    pred = root;

    inorder(root->right);
  }

  void swap(TreeNode* x, TreeNode* y) {
    const int temp = x->val;
    x->val = y->val;
    y->val = temp;
  }
};


Approach 2: Iterative (stack)¶
Time: 
O
(
n
)
O(n)
Space: 
O
(
h
)
O(h)

C++
Java
Python
class Solution {
 public:
  void recoverTree(TreeNode* root) {
    TreeNode* pred = nullptr;
    TreeNode* x = nullptr;  // the first wrong node
    TreeNode* y = nullptr;  // the second wrong node

    stack<TreeNode*> stack;

    while (root != nullptr || !stack.empty()) {
      while (root != nullptr) {
        stack.push(root);
        root = root->left;
      }
      root = stack.top(), stack.pop();
      if (pred && root->val < pred->val) {
        y = root;
        if (x == nullptr)
          x = pred;
      }
      pred = root;
      root = root->right;
    }

    swap(x, y);
  }

  void swap(TreeNode* x, TreeNode* y) {
    const int temp = x->val;
    x->val = y->val;
    y->val = temp;
  }
};


Approach 3: Morris¶
Time: 
O
(
n
)
O(n)
Space: 
O
(
1
)
O(1)

C++
Java
Python
class Solution {
 public:
  void recoverTree(TreeNode* root) {
    TreeNode* pred = nullptr;
    TreeNode* x = nullptr;  // the first wrong node
    TreeNode* y = nullptr;  // the second wrong node

    while (root != nullptr) {
      if (root->left != nullptr) {
        TreeNode* morrisPred = findPredecessor(root);
        if (morrisPred->right) {
          // The node has already been connected before.
          visit(root, pred, x, y);
          morrisPred->right = nullptr;  // Break the connection.
          root = root->right;
        } else {
          morrisPred->right = root;  // Connect it.
          root = root->left;
        }
      } else {
        visit(root, pred, x, y);
        root = root->right;
      }
    }

    swap(x, y);
  }

 private:
  TreeNode* findPredecessor(TreeNode* root) {
    TreeNode* pred = root->left;
    while (pred->right && pred->right != root)
      pred = pred->right;
    return pred;
  }

  void visit(TreeNode*& root, TreeNode*& pred, TreeNode*& x, TreeNode*& y) {
    if (pred && root->val < pred->val) {
      y = root;
      if (x == nullptr)
        x = pred;
    }
    pred = root;
  }

  void swap(TreeNode* x, TreeNode* y) {
    const int temp = x->val;
    x->val = y->val;
    y->val = temp;
  }
};

Was this page helpful?


 Back to top
Previous
98. Validate Binary Search Tree
Next
100. Same Tree
Copyright © 2019 - 2026 P.-Y. Chen | Magic Park Labs
Made with Material for MkDocs
