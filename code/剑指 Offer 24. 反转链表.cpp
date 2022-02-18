#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
		if (!head) return {};
		vector <int> a = reversePrint(head->next);
		a.push_back(head->val);
		return a;
    }
};

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* node2 = new ListNode(2);head->next = node2;
	ListNode* node3 = new ListNode(3);node2->next = node3;
	ListNode* node4 = new ListNode(4);node3->next = node4;
	ListNode* node5 = new ListNode(5);node4->next = node5;
	
	Solution solution = Solution();
	vector <int> ans = solution.reversePrint(head);
	// requires C++ 11
	for (auto i = ans.begin(); i != ans.end(); i++) cout << *i << ' ';

	return 0;
}
