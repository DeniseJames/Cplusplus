#include <iostream>
// Sum of two bits can be obtained by performing XOR(^) 
// of the two bits.Carry bit can be obtained by 
// performing AND(&) of two bits.

class Solution {
public:
	int Add(int x, int y)
	{
		// Iterate till there is no carry  
		while (y != 0)
		{
			// carry now contains common set bits of x and y
			int carry = x & y;

			// Sum of bits of x and y where at least one of the bits is not set
			// but not both set, exclusive or
			x = x ^ y;

			// Carry is shifted by one so that adding it to x gives the required sum
			y = carry << 1;
		}
		return x;
	}


	int getSum(int a, int b) {

			if (b == 0)
				return a;
			else				
			{
				std::cout << " a is " << a << std::endl;
				// Carry bit is one
				return getSum(a ^ b, (a & b) << 1);
			}

				
	}
};
int main()
{
	Solution answer;
	int addend = 51;
	int addend2 = 76;
	int sum, sum2;
	sum = answer.getSum(addend, addend2);
	std::cout << " sum is " << sum << std::endl;
	sum2 = answer.Add(addend, addend2);
	std::cout << " sum2 is " << sum2 << std::endl;
	return 0;
}
//The size of an integer : 4 bytes
//The size of a short integer : 2 bytes
//The size of a long integer : 4 bytes
//The size of a character : 1 bytes
//The size of a boolean : 1 bytes
//The size of a float : 4 bytes
//The size of a double float : 8 bytes