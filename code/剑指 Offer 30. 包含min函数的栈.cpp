#include <bits/stdc++.h>
using namespace std;

class MinStack {
	stack <int> stack1, stack2;
public:
    /** initialize your data structure here. */
    MinStack() {
		while (!stack1.empty()) stack1.pop();
		while (!stack2.empty()) stack2.pop();
    }
    
    void push(int x) {
		stack1.push(x);
		if (stack2.empty() or x<=stack2.top())  stack2.push(x);
    }
    
    void pop() {
    	if (stack2.top()==stack1.top()) stack2.pop();
		stack1.pop();
    }
    
    int top() {
		return stack1.top();
    }
    
    int min() {
		return stack2.top();
    }
};

int main()
{
	MinStack minStack = MinStack();
	minStack.push(0);
	minStack.push(1);
	minStack.push(0);
	cout<<minStack.min()<<endl;
	minStack.pop();
	cout<<minStack.min()<<endl;

	return 0;
}
