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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> tree;
        if (!root) return ret;

        tree.push(root);
        bool odd = true;
        while (!tree.empty())
        {
            int num = tree.size();
			ret.push_back({});
					         					
            while (num--)
            {
                TreeNode* currNode = tree.front();
                ret.back().push_back(currNode->val);
                tree.pop();

                if (currNode->left) tree.push(currNode->left);
                if (currNode->right) tree.push(currNode->right);                
            }
            
			if (!odd) reverse(ret.back().begin(), ret.back().end());
			odd^=1;
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
	{
		for (auto y:x)
			cout<<y<<" ";	
		cout<<endl;	
	}

	return 0;
}
