#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector <int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	for (auto i:a) cout<<i<<endl;
	cout<<a[0]<<endl;
	reverse(a.begin(), a.end());
	for (auto i:a) cout<<i<<endl;
	return 0;
}
