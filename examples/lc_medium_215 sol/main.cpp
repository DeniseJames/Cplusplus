#include <iostream>		// for cout function
#include <vector>
#include <algorithm>	// for sort function
#include <functional>  // for greater function

using namespace std;
// Find the kth largest element in an unsorted array.
// Note that it is the kth largest element in the 
// sorted order, not the kth distinct element.
// For example,
// Given[3, 2, 1, 5, 6, 4] and k = 2, return 5.

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		std::sort(nums.begin(), nums.end(), std::greater<int>());
		cout << " The " << k << " element in the array is " << nums[k - 1];
		return nums[k - 1];
	}
};
int main()
{
	Solution result;
	vector<int> array_to_analyze = {3, 2, 1, 5, 6, 4};
	int y;
	int index = 2;
	y = result.findKthLargest(array_to_analyze, index);
	return 0;
}