#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
		vector<bool> vis(nums.size());
		for (int i=0;i<vis.size();i++) vis[i]=false;
		
		for (auto x:nums)
			if (!vis[x]) vis[x] = true;
			else return x;
        return -1;  // denotes no repeat nums
    }
};

int main()
{
	vector <int> nums = {2, 3, 1, 0, 2, 5, 3};
	Solution solution = Solution();
	cout<< solution.findRepeatNumber(nums)<< endl;
	return 0; 
}
