#include <bits/stdc++.h>
using namespace std;
 
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode* vectorToListNode(vector<int> &a);
};

ListNode* ListNode::vectorToListNode(vector<int> &a) {
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for (auto x:a) {
		ptr->next = new ListNode(x);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;	//don't need to deal with empty vector particularly
	return ptr;
}

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
    	if (head->val == val) return head->next;
    	
		for (auto ptr=head; ptr; ptr=ptr->next) 
			if (ptr->next->val == val) {
				ptr->next = ptr->next->next;
				break;
			}
		return head;
    }
};

int main()
{
	vector<int> a = {4,5,1,9};
	int val = 5;
	
	ListNode* head;
	head = head->vectorToListNode(a);
	for (auto ptr=head; ptr; ptr = ptr->next)
		cout<< ptr->val;
	cout<<endl;
	
	Solution* solution = new Solution();
	for (auto ptr=solution->deleteNode(head, val); ptr; ptr = ptr->next)
		cout<< ptr->val;
	cout<<endl;
	return 0;
}
