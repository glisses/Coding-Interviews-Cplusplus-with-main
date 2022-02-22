#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> ret;
    queue<TreeNode*> tree;
    vector<int> levelOrder(TreeNode* root) {
        ret.clear();
        while (!tree.empty()) tree.pop();
        if (!root) return ret;

        ret.push_back(root->val);
        tree.push(root);
        while (!tree.empty())
        {
            TreeNode* curr = tree.front();
            tree.pop();
            if (curr->left) ret.push_back(curr->left->val), tree.push(curr->left);
            if (curr->right) ret.push_back(curr->right->val), tree.push(curr->right);
        }

        return ret;
    }
};

int main()
{
	TreeNode* root = new TreeNode(3);
	TreeNode* node1 = new TreeNode(9);
	TreeNode* node2 = new TreeNode(20);
	TreeNode* node3 = new TreeNode(15);
	TreeNode* node4 = new TreeNode(7);
	
	root->left = node1; root->right = node2;
	node2->left = node3; node2->right = node4;
	
	Solution solution = Solution();
	for (auto x:solution.levelOrder(root))
		cout<<x<<" ";
	cout<<endl;
	return 0;
}
