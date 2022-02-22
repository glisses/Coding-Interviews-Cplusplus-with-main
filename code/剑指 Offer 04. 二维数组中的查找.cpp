#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		int row = matrix.size();
		if (row<1) return false;
		int column = matrix[0].size();
		if (column<1) return false;
		
		int indexI = 0, indexJ = column-1;
		while (indexI<row && indexJ>=0 && matrix[indexI][indexJ]!=target)
		{
			if (matrix[indexI][indexJ]>target) indexJ--; else
											   indexI++;
		}
		
		return indexI<row && indexJ>=0 && matrix[indexI][indexJ]==target;
    }
};

int main()
{
	Solution solution = Solution();
	vector<vector<int>> matrix = 
			  {
			  {1,   4,  7, 11, 15},
			  {2,   5,  8, 12, 19},
			  {3,   6,  9, 16, 22},
			  {10, 13, 14, 17, 24},
			  {18, 21, 23, 26, 30}
			  };
//				{{-5}
//				};
	int target = 20;		
	
	cout<<solution.findNumberIn2DArray(matrix, target)<<endl;
	return 0;
}
