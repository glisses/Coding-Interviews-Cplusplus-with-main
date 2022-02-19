#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
		string ret = "";
		for (auto c:s)
			if (c==' ')
				ret.push_back('%'), ret.push_back('2'), ret.push_back('0');
			else
				ret.push_back(c);
		return ret;
    }
};

int main()
{
	Solution solution = Solution();
	string s = "We are happy.";
	cout<<solution.replaceSpace(s)<<endl;
	return 0;
}
