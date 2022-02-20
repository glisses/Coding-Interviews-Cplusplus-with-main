#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	if (nums[0]!=0) return 0;
		int l=0, r=nums.size()-1;
    	if (nums[r]==r) return r+1;
    	
    	while (l<r)
    		if (nums[(l+r)>>1]==(l+r)>>1) l=((l+r)>>1)+1; else r=(l+r)>>1;
    	
		return l; 
    }
};

int main()
{
	vector <int> nums = {0,1,2,3,4,5,6,7,9};
//	vector <int> nums = {0,1}; //一种很坑的情况 
	Solution solution = Solution();
	cout<< solution.missingNumber(nums)<< endl;
	return 0; 
}
