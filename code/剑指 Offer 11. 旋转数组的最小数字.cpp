#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
		int n = numbers.size()-1;
		
		int left = 0, right = n; // denotes the possible area of min
		while (left<right)
		{
			int mid = left + ((right-left)>>1);
			if (numbers[mid]>numbers[right]) left = mid+1; else
			if (numbers[mid]<numbers[left]) right = mid; else
											right--;						
		}
		return numbers[left];
    }
};

int main()
{
	Solution solution = Solution();
	vector<int> numbers = {2,0,1,1,1};		
	
	cout<<solution.minArray(numbers)<<endl;
	return 0;
}
