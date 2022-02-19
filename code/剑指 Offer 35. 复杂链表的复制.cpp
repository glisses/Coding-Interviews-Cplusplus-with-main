#include <bits/stdc++.h>
using namespace std; 
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
    	if (!head) return NULL;
    	Node* curr = head;
    	Node* copy = NULL;
    	
    	//第一遍，产生复制节点S'
    	while (curr)
    	{
    		copy = new Node(curr->val);
			copy->next = curr->next;
			curr->next = copy;
	    	curr = copy->next;		
    	}
    	copy = head->next;
    	
    	//第二遍，处理S'->random 
    	curr = head;
    	while (curr)
    	{
    		if (curr->random)
    			curr->next->random = curr->random->next; // amazing
    		curr = curr->next->next;
    	}
    	
    	//第三遍，分开原链表head和复制链表copy 
    	curr = head;
    	while (curr)
    	{
    		auto x = curr->next->next;
			if (x) curr->next->next = x->next;
			curr->next = x;
    		curr = x;
    	}
    	
        return copy;
    }
};

int main()
{
	Node* head = new Node(7);
	Node* node1 = new Node(13); head->next = node1;
	Node* node2 = new Node(11); node1->next = node2;
	Node* node3 = new Node(10); node2->next = node3;
	Node* node4 = new Node(1);  node3->next = node4;
	node1->random = head;
	node2->random = node4;
	node3->random = node2;
	node4->random = head;
	
	Solution solution = Solution();
	Node* ans = solution.copyRandomList(head);
	for (auto i=ans; i; i=i->next) 
	{
		cout<<i->val<<" ";
		if (i->random) cout<<i->random->val; else cout<<"NULL";
		cout<<endl;
	}
	return 0;
}
