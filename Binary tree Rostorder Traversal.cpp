#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            auto node = st.top(); st.pop();
            res.push_back(node->val);
            if (node->left)  st.push(node->left);
            if (node->right) st.push(node->right);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};