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
    ListNode* reverseList(ListNode* head) {
    	auto tail = head;
    	while (tail && tail->next)  //判断tail是为了防止输入是空链表 
    	{
			auto swap = tail->next->next;
			tail->next->next = head; 
			head = tail->next;
			tail->next = swap;
    	}
		return head;
    }
};

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* node2 = new ListNode(2); head->next = node2;
	ListNode* node3 = new ListNode(3); node2->next = node3;
	ListNode* node4 = new ListNode(4); node3->next = node4;
	ListNode* node5 = new ListNode(5); node4->next = node5;

	Solution solution = Solution();
	ListNode* ans = solution.reverseList(head);
	// requires C++ 11
	for (auto i = ans; i; i=i->next) cout<<i->val<<"->";
	cout<<"NULL\n";
	return 0;
}
