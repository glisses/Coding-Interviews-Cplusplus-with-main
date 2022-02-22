#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        bool vis[26+26];
        int first[26];
        memset(vis,false,sizeof(vis));
        memset(first,0,sizeof(first));

        for (int index=0; index<s.length(); index++)
            if (vis[s[index]-'a'+26]) continue; else
                if (vis[s[index]-'a']) vis[s[index]-'a'+26]=true; else
                                     vis[s[index]-'a']=true, first[s[index]-'a']=index;
        
        int ans=s.length(); //s[ans] denotes the firstUnicChar
        for (int index=0; index<26; index++)
            if (vis[index] && !vis[index+26] && first[index]<ans) ans=first[index];
        return (ans<s.length())? s[ans] : ' ';
    }
};

int main()
{
	string s = "abaccdeff";
	Solution* solution = new Solution();
	cout<< solution->firstUniqChar(s)<<endl; 
	return 0;
}
