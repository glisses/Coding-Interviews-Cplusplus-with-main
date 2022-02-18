#include <bits/stdc++.h>
using namespace std;

class CQueue {
	stack<int> stack1, stack2;
public:
    CQueue() {
		while (!stack1.empty())
			stack1.pop();
		while (!stack2.empty())
			stack2.pop();
    }
    
    void appendTail(int value) {
		stack1.push(value);
    }
    
    int deleteHead() {
    	if (stack1.empty() && stack2.empty())
    		return -1;
    
		if (!stack2.empty())
		{
			int ret = stack2.top();
			stack2.pop();
			return ret;
		}
		
		while(!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		int ret = stack2.top();
		stack2.pop();
		return ret;
    }
};
int main()
{
	CQueue* obj = new CQueue();
	cout<<(obj->deleteHead())<<endl;
	obj->appendTail(5);
	obj->appendTail(2);
	cout<<obj->deleteHead()<<endl;
	cout<<obj->deleteHead()<<endl;
	return 0;
}
