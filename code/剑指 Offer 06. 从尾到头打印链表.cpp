#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

    }
};
public:
    vector<int> reverseList(ListNode* head) {
		if (!head) return {};
		vector <int> a = reversePrint(head->next);
		a.push_back(head->val);
		return a;
    }
};

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* node2 = new ListNode(3);
	ListNode* node3 = new ListNode(2);
	head->next = node2;
	node2->next = node3;
	Solution solution = Solution();
	
	vector <int> ans = solution.reverseList(head);
	// requires C++ 11
	for (auto i = ans.begin(); i != ans.end(); i++) cout << *i << ' ';

	return 0;
}
