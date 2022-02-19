#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
		return s.substr(n)+s.substr(0,n);
    }
};

int main()
{
	Solution solution = Solution();
	string s = "abcdefg";
	int k = 2;
	cout<<solution.reverseLeftWords(s,k)<<endl;
	return 0;
}
