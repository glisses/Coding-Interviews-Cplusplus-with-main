# Coding-Interviews-C--with-main
本文严格按照[LeetCode上《剑指offer》学习计划](https://leetcode-cn.com/study-plan/lcof/?progress=wp5ibz5)的顺序撰写。

**动机**：LeetCode题解没有主程序，对我在本地测试造成了麻烦。想提供一份包含测试的完整程序，供大家使用。

对于《剑指offer》上的每道题，本文包含：

- **该题的LeetCode链接**
- **解题思路（简单题可能略过）**
- **完整代码（输入在main函数中）**
- **样例输出**
- **执行用时、内存消耗在LeetCode评测的排名**

代码的`.cpp`和`exe`文件见[./code](./code)中。

​                 

截至目前，本文中代码的执行用时平均排名为：100%；内存消耗平均排名为：55.3%。

你也可以在[我的博客](https://blog.fishercat.top/2022/02/18/Coding-Interviews-C-with-main/)中浏览以下内容，会有更好的阅读体验。

​                           

## Day 1

### [剑指 Offer 09. 用两个栈实现队列](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)

#### 【解题思路】

栈的特点是先进后出，队列的特点是先进先出。

两个栈，stack1负责插入，stack2负责删除。

对于插入操作，插入stack1即可；

对于删除操作，若stack2非空，则stack2.pop()；若stack2为空，则将stack1中所有值按顺序pop到stack2中。然后stack2再pop。

#### 【完整代码】

``` c++
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
```



#### 【样例输出】

``` c++
-1
5
2
```



#### 【**执行用时、内存消耗排名**】

执行用时：212 ms, 在所有 C++ 提交中击败了99%的用户

内存消耗：101MB, 在所有 C++ 提交中击败了78%的用户

通过测试用例：55 / 55

​                          

#### [剑指 Offer 30. 包含min函数的栈](https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/)

#### 【解题思路】

正常stack1，让stack2存放stack1中的**不上升**序列。注意是**不上升序列**而不是**下降序列**，不然无法处理有相同值的情况。我在这儿RE了。

#### 【完整代码】

``` c++
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
```



#### 【样例输出】

``` c++
0
0
```



#### 【**执行用时、内存消耗排名**】

执行用时：12ms, 在所有 C++ 提交中击败了100%的用户

内存消耗：14.6MB, 在所有 C++ 提交中击败了81%的用户

通过测试用例：19 / 19

​                          

## Day 2

#### [剑指 Offer 06. 从尾到头打印链表](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)

#### 【解题思路】

递归

#### 【完整代码】

``` c++
#include <bits/stdc++.h>
using namespace std;

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
	ListNode* node2 = new ListNode(3);
	ListNode* node3 = new ListNode(2);
	head->next = node2;
	node2->next = node3;
	Solution solution = Solution();
	
	vector <int> ans = solution.reversePrint(head);
	// requires C++ 11
	for (auto i = ans.begin(); i != ans.end(); i++) cout << *i << ' ';

	return 0;
}
```



#### 【样例输出】

``` c++
2 3 1
```



#### 【**执行用时、内存消耗排名**】

执行用时：0ms, 在所有 C++ 提交中击败了100%的用户

内存消耗：11MB, 在所有 C++ 提交中击败了7%的用户

通过测试用例：24 / 24

