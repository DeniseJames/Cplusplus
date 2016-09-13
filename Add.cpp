/* This program works with a 3-digit augend
and a 2 digit addend.  It takes in an array of
single digit augend, single array addend and
a single sum array*/

#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*Function to left rotate arr[] of size n */
void rightRotatebyOne(int arr[], int n)
{
	int i, temp;
	temp = arr[n];// save the end element
	for (i = n; i >= 0; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = temp;
}

int main()
{
	//declare the augend and the addend
	string sAugend, sAddend;
	int iAugend[3] = { 0 };
	int iAddend[3]= { 0 };
	int iSum[4]= { 0 };


	void rightRotatebyOne(int arr[], int n);

	do
	{
		std::cout << "Type in the following information or q to quit" << endl;
		std::cout << "Type in the augend " << endl;
		getline(cin, sAugend);
		std::cout << endl << "Type in the addend " << endl;
		getline(cin, sAddend);

		for (int i = 0;  i < strlen(sAugend.c_str()); i++)
		{
			//convert character to integer
			iAugend[i] = sAugend[i] - '0';
			cout << "iaugend[" << i << "] = " << iAugend[i] << " ";
		}//for
		cout << endl;
		for (int i = 0; i < strlen(sAddend.c_str()); i++)
		{
			//convert character to integer
			iAddend[i] = sAddend[i] - '0';
			cout << "iaddend["<<i<<"] = " << iAddend[i] << " ";
		}//for
		cout << endl;
		//shift the arrays to line of the columns to add
		if (iAddend[strlen(sAddend.c_str())]==0)
		{
			// shift the array to the right
			rightRotatebyOne(iAddend, strlen(sAddend.c_str()));
		}
		for (int i = max(strlen(sAugend.c_str()), strlen(sAddend.c_str()))-1; i >=0 ; i--)
		{
			//add the augend, addend and carry 
			iSum[i] = iSum[i]+iAugend[i] + iAddend[i];
			
			//if a carry, add one to the next iSum array
			if (iSum[i]>9)
			{
				iSum[i] = iSum[i] - 10;
				iSum[i - 1]++;
			}
			cout << "Sum["<<i<<"] = " << iSum[i] << "  iAugend[" << i << "] = " << iAugend[i] << "  addend[" << i << "] = " << iAddend[i] << endl;

		}
	
		for (int i = 0; i < 3; i++)
		{
			cout << iAugend[i] ;
		}
		cout << " + ";
		for (int i = 0; i < 3; i++)
		{
			cout << iAddend[i] ;
		}
		cout << " = ";
		for (int i = 0; i < 3; i++)
		{
			cout << iSum[i];
		}
		cout << endl;
	} while (sAugend!="q" || sAddend!="q");
	return 0;
}
