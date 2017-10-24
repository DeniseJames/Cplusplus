#include <iostream>		// for cout function
#include <vector>
#include <numeric>  // for accumulate function

using namespace std;
// Implement atoi to convert a string to an integer.
class Solution {
public:
	int myAtoi(string str) {
		const char * c = str.c_str();
		int val = 0;
		while (*c) {
			val = val * 10 + (*c++ - '0');
		}
		return val;
	}
};
int main()
{
	Solution results;
	string denise = "+";
	int returned_integer;
	returned_integer = results.myAtoi(denise);

	return 0;
}