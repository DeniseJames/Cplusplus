//============================================================================
// Name		    Denise R. James       : assignment_1_20160705.cpp
//
//Eclipse IDE for C/C++ Developers
//
//Version: Mars Release (4.5.0)
//Build id: 20150621-1200
//
// Description : Assignment #1 C++ Comprehensive, Ansi-style
//============================================================================
#include <iostream>
#include <iomanip>  // to use setw object

using namespace std;   // to use cout and cin objects
//MAGIC SQUARE - An NxN matrix containing values from 1 to N*N that are //ordered so that the sum of the rows, columns, and the major diagonals
//are all equal.  There is a particular algorithm for odd integers, and
//this program constructs that matrix, up to 13 rows and columns.  This
//program also adds the sums of the row, columns, and major diagonals.
class CMagicSquare {
public:
	void Allocate_Init(int size);
	void Fill(int sizeofarray);
	void Display(int rankofarray);
private:
	int **pnMatrix;
	int m_iRowCount;
	int m_iColCount;
	int m_iMainDiagonal;
	int rankofarray;;
	int m_iAntiDiagonal;
	int m_iTotal;

};
void CMagicSquare::Allocate_Init(int size)
{
	//   Assign the dimension of the square array
	m_iRowCount = m_iColCount = size;
	//	  Dynamically Allocate the matrix
	pnMatrix = new int*[m_iRowCount];  // pointer to a column of rows
	for (int i = 0; i < m_iRowCount; i++)
	{
		pnMatrix[i] = new int[m_iColCount];
	}

	// Initialization of Matrix elements to zero
	for (int j = 0; j < m_iRowCount; j++)
	{
		for (int i = 0; i < m_iColCount; i++)
			pnMatrix[i][j] = 0;
	}

}

void CMagicSquare::Fill(int sizeofarray)
{
	// Define the first cell, [row][column], to populate with 1
	m_iRowCount = 1;
	m_iColCount = sizeofarray / 2 + 1;
	// Put initial value in first defined cell location

	//put initial value in first defined cell
	m_iMainDiagonal = 0;
	m_iAntiDiagonal = 0;

	// Populate the magic square
	// Add to the main diagonal if on the main diagonal
	// Populate the magic square
	for (int k = 1; k <= sizeofarray*sizeofarray; k++)
	{
		if (m_iRowCount == 0)
		{
			m_iRowCount = sizeofarray;
			
		}
		if (m_iColCount > sizeofarray)
		{
			m_iColCount = 1;
			
		}
		if (pnMatrix[m_iRowCount - 1][m_iColCount - 1])// if not null
		{
			m_iRowCount = m_iRowCount + 2;
			if (m_iRowCount > sizeofarray)
			{
				m_iRowCount = 1;
			}
			m_iColCount = m_iColCount - 1;
			if (m_iColCount < 1)
			{
				m_iColCount = sizeofarray;
			}
			if (pnMatrix[m_iRowCount - 1][m_iColCount - 1])// if still not null
				do
				{
					m_iRowCount = m_iRowCount + 1;
					if (m_iRowCount > sizeofarray)
					{
						m_iRowCount = 1;
					}

				} while (pnMatrix[m_iRowCount - 1][m_iColCount - 1]);
		}

		// if the cell already has a number then

		pnMatrix[m_iRowCount - 1][m_iColCount - 1] = k;

		// Calculate the main diagonal
		if (m_iRowCount == m_iColCount)
		{
			m_iMainDiagonal += pnMatrix[m_iRowCount - 1][m_iColCount - 1];
		}
		// Add the antidiagonal total if the element is on the antidiagonal
		if ((m_iRowCount + m_iColCount) == (sizeofarray + 1))


		{
			m_iAntiDiagonal += pnMatrix[m_iRowCount - 1][m_iColCount - 1];
		}
	
		// Move up one row and down one column
		m_iRowCount = m_iRowCount - 1; // move up one row
		m_iColCount = m_iColCount + 1;  // move one column rig
	}  // End of for loop
	   // Add the column elements

}
void CMagicSquare::Display(int rankofarray)
{
	// Print Magic Square

	m_iRowCount = m_iColCount = rankofarray;
	cout.fill(' ');
	for (int i = 0; i < m_iRowCount; i++)
	{
		cout << "     ";
		for (int j = 0; j < m_iColCount; j++)
			cout << setw(5) << pnMatrix[i][j];
		cout << endl;
	}

	// Add five blank spaces before adding the line
	cout << "     ";
	// Add ---- line separating matrix and column total
	for (int i = 0; i<rankofarray; i++)
	{
		cout << "-----";
	}
	// Print out the antidiagonal total
	cout << endl << setw(5) << m_iAntiDiagonal;
	// Print out the column totals

	// Calculate and print out the column totals

	for (int col = 0; col<rankofarray; col++)
	{
		m_iTotal = 0;
		for (int row = 0; row<rankofarray; row++)
		{
			m_iTotal += (pnMatrix[row][col]);
			//m_iAntiDiagonal+=pnMatrix[m_iRowCount-1][m_iColCount-1] ;

		}
		cout << setw(5) << m_iTotal;
	}
	// Print out the main diagonal total
	cout << setw(5) << m_iMainDiagonal;

	//  Free the memory space
	for (int i = 0; i < m_iRowCount; i++)
	{
		delete[]pnMatrix[i];
	}
	delete[]pnMatrix;

}
int main()
{
	int input;        //User inputs the number for rows=columns                                 //Determines row of matrix
					  //Print introduction of what this program is all about.
	cout.fill(' ');  // format unused setw values
	cout << "\nMagic Squares: This program produces an NxN matrix where" << endl;
	cout << "N is some positive odd integer.  The matrix contains the" << endl;
	cout << "values 1 to N*N.  The sum of each row, each column, and" << endl;
	cout << "the two main diagonals are all equal.  Not only does this" << endl;
	cout << "program produces the matrix, it also computes the totals for" << endl;
	cout << "each row, column, and two main diagonals." << endl;

	cout << endl << "Because of display constraints, this program can work with" << endl;
	cout << "values up to 13 only." << endl << endl;

	cout << endl << "Enter a positive, odd integer (-1 to exit program):" << endl;
	while (cin >> input)
	{
		//   If input = -1, then exit program.
		if (input == -1)
			break;
		//   Validity check for input: Must be a positive odd integer < 13.
		//
		if (input <= 0)
		{
			cout << "Sorry, but the integer has to be positive." << endl;
			cout << "\nEnter a positive, odd integer (-1 to exit program):" << endl;
			continue;
		}
		if (input > 13)
		{
			cout << "Sorry, but the integer has to be less than 15." << endl;
			cout << endl << "Enter a positive, odd integer (-1 to exit program):" << endl;
			continue;
		}
		if (input % 2 == 0)
		{
			cout << "Sorry, but the integer has to be odd." << endl;
			cout << endl << "Enter a positive, odd integer (-1 to exit program):" << endl;
			continue;
		}
		//
		cout << endl << "The number you selected was:  " << input;
		CMagicSquare *ptrSquareArray = new CMagicSquare;
		ptrSquareArray->Allocate_Init(input);
		ptrSquareArray->Fill(input);
		cout << ", and the matrix is: " << endl << endl;
		ptrSquareArray->Display(input);

		cout << endl << "Enter a positive odd integer less than 15 (-1 to exit program):" << endl;
	}                                   //End of while input>-1 loop
	cout << endl << "Bye bye!" << endl;
}