#include <iostream>		// for cout function
#include <vector>
#include <numeric>  // for accumulate function

using namespace std;
// Given an array of n integers where n > 1, nums, 
// return an array output such that output[i] is equal
// to the product of all the elements of nums except nums[i].

// Solve it without division and in O(n).

// For example, given [1,2,3,4], return [24,12,8,6].

// Follow up:
// Could you solve it with constant space complexity? 
// (Note: The output array does not count as extra space 
// for the purpose of space complexity analysis.)

// 
class Solution {
public:
	vector<int> productExceptSelf(const vector<int>& nums) {
		
		vector<int> _return_nums;
		for (size_t i = 0; i < nums.size(); i++)
		{
			vector<int> _nums = nums;
			// remove the ith element from the array
			_nums.erase(_nums.begin() + i);
			// put the product of the remaining
			// elements in the array and push_back
			// multiply the remaining elements
			auto multi = std::accumulate(begin(_nums), end(_nums), 1, std::multiplies<>());
			_return_nums.push_back(multi);

		}
		return _return_nums;
	}
};
int main()
{
	Solution results;
	vector<int> candidate_list = { 1, 2, 3, 4 };
	vector<int> returned_lists;
	returned_lists = results.productExceptSelf(candidate_list);
	for (auto v : returned_lists)
	{
		std::cout << v << " ";
	}

	return 0;
}