#include <iostream>		// for cout function
#include <vector>
#include <algorithm>

using namespace std;
// Given a set of candidate numbers (C) (without 
// duplicates) and a target number (T), find all
// unique combinations in C where the candidate numbers
// sums to T.
// The same repeated number may be chosen from C 
// unlimited number of times.

// For example, given candidate set [2, 3, 6, 7] and target 7, 
//A solution set is :
//[
//	[7],
//	[2, 2, 3]
//]


// 
class Solution {
public:
	// Print all members of ar[] that have given
	void findNumbers(vector<int>& ar, int sum,
		vector<vector<int> >& res,
		vector<int>& r, int i)
	{
		// If  current sum becomes negative
		if (sum < 0)
			return;

		// if we get exact answer 
		if (sum == 0)
		{
			res.push_back(r);
			return;
		}

		// Recur for all remaining elements that
		// have value smaller than sum and the 
		// we have not been through the whole array
		while (i < ar.size() && sum - ar[i] >= 0)
		{

			// Til every element in the array starting
			// from i which can contribute to the sum
			r.push_back(ar[i]); // add them to list

			// recur for next numbers
			// send the array , difference between sum and value 
			// in ar array, send res in case we need to pushback vector
			// onto it , r array 
			findNumbers(ar, sum - ar[i], res, r, i);
			i++;

			// remove number from list (backtracking)
			r.pop_back();
		}
	}


	vector<vector<int> > combinationSum(vector<int>& candidates,
		int target)
	{
		// sort input array
		sort(candidates.begin(), candidates.end());

		// remove duplicates
		candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

		vector<int> r;
		vector<vector<int> > res;
		findNumbers(candidates, target, res, r, 0);

		return res;
	}
};
int main()
{
	Solution results;
	vector<int> candidate_list = { 2, 3, 6, 7 };
	int target = 7;
	vector<vector<int>> returned_lists;
	returned_lists = results.combinationSum(candidate_list, target);
	for (auto v: returned_lists)
	{
		std::cout << v[0] << std::endl;
	}

	return 0;
}