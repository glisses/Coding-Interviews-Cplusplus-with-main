#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int index[30001];

    int longestValidParentheses(string s) {
        int counter = 0;
        int ans = 0;                    // length of the longest valid parentheses
        int n = s.length();

        for (int i=0; i<n+1; i++) index[i]=1e9;
        
        for (int i=0; i<s.length(); i++){
            char c = s[i];
            assert (c=='(' or c==')');  // only () in the string
            counter = (c=='(')? counter+1 : counter-1;
            int counter_convert = (counter+n)%n;    // to avoid negative index

            if (c==')'){
                ans = max(ans, i-index[(counter_convert+1)%n]+1);
                index[(counter_convert+2)%n] = 1e9;   // becomes invalid
            } else
                index[counter_convert] = min(index[counter_convert], i);
        
        }
        return ans;
    }
};

int main()
{
	string s = ")()())";
	
	Solution solution = Solution();
	cout<<solution.longestValidParentheses(s)<<endl;
	return 0;
}
