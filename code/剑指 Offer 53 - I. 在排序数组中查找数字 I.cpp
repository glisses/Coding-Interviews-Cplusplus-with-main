#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		int l=0, r=nums.size()-1;
		if (r<0) return 0;
		
		while (l<r)
		{
			int mid=(l+r)>>1;
			if (nums[mid]<target) l=mid+1; else r=mid;
		}
		if (nums[l]!=target) return 0;
		
		r = nums.size()-1;
		while (l<r)
		{
			int mid = (l+r)>>1;
			if (nums[mid]>target) r=mid-1; else break;
		}
		while (nums[r]!=target && r>=l) r--;
		
        return r-l+1;
    }
};

int main()
{
	vector <int> nums = {5,7,7,8,8,8,8,8,8,8,10};
//	vector <int> nums = {};
	int target = 8;
	Solution solution = Solution();
	cout<< solution.search(nums, target)<< endl;
	return 0; 
}
