//============================================================================
// Name		    Denise R. James       : assignment_2_20160729.cpp
//
//  Microsoft Visual Studio Community 2015
//  Version:  14.0.25422.01
//  Description : Assignment #2 C++ Comprehensive, Ansi-style
//  This program simulates a parking lot with two alleys, Alley A and Alley B
//  Alley A is where the cars are parked.  The maximum of cars is five.
//  To retrieve a car, cars in alley A are moved to alley B until you get to
//  the car being retrieved.  This car is deleted and the cars in alley B are
//  moved back to alley A.  When a new car arrives it is placed in the last 
//  available spot in Alley A.  
// 
//============================================================================
#include <iostream>
#include <cstdio>
#include <cctype>

#define MAXSIZE 5		// define the maximum size of the alley
using namespace std;   // to use cout and cin objects

class CarNode {
public:
	CarNode() : m_pNext(0), m_ticketNum(0) { } // constructor 
	~CarNode() {}  // constructor to free memory after Carnode is of scope
	CarNode(CarNode &) :m_pNext(0), m_ticketNum(0) { }// constructor

	// assign next pointer
	void SetNext(CarNode* p) { m_pNext = p; }
	// assign next pointer
	void SetPrev(CarNode* p) { m_pPrev = p; }
	// assign ticket number
	void SetTicketNum(int tN) { m_ticketNum = tN; }
	// get the next pointer
	CarNode * GetNext(void) { return(m_pNext); }
	// get the next pointer
	CarNode * GetPrev(void) { return(m_pPrev); }
	// get the ticket number
	int GetTicketNum(void) { return(m_ticketNum); }
private:
	CarNode *m_pNext; // pointer to next node in stack
	CarNode * m_pPrev; // pointer to previous node in stack
	int m_ticketNum; // ticket number of car
};

class CAlley {
public:
	CAlley() : m_pTop(0), mSize(0), mMaxSize(MAXSIZE) { }//constructor
	~CAlley() {} //deconstructor to free memory when out of scope
	CAlley(CAlley &) :m_pTop(0), mSize(0), mMaxSize(MAXSIZE) { }
	int Park(int); // park a car and return a new ticket number
	void Retrieve(int userTicketNum, CAlley *pB);// retrieve a car
	void Display(); // display contents af alley
	//check if stack is empty
	bool Empty() { return ((mSize <= 0) ? true : false); }
	// check if stack is full
	bool Full() { return ((mSize >= MAXSIZE) ? true : false); }
	void Push(CarNode *); // push new node onto top of stack
	void PushWithNode(CarNode *); // push existing node onto top of the stack
	CarNode * Pop(); // pop one node from the top of stack
	CarNode * PopReverse(); // pop reverse linked list in alley b
	CarNode * m_pTop; // pointer to top of alley (stack)
	CarNode * m_pHead=0; // pointer to head of stack
	private:
	int mSize; // number of nodes in alley (stack)
	int mMaxSize; //max number of nodes in alley (stack)
};

////////////////////////////////////////////////////////////////
// Function: CAlley::Push
// Purpose: Add a new node to top of stack
// Parameters: pointer pNewNode, NewNodeToPush
// CarNode * pNewNode- the node to be added to top of stack
// Local Variables:  CarNode * NewNodeToPush
//   
// - no return value
////////////////////////////////////////////////////////////////

void CAlley::Push(CarNode *pNewNode)// type integer function pass by reference to pointer?
{
	if (mSize == 0)
	{
		m_pTop = pNewNode;  // put the head node at pNewNode Address
		m_pHead = pNewNode;
		++mSize;
	}
	else
	{
		CarNode * NewNodeToPush = new CarNode;
		NewNodeToPush = pNewNode; // get the address of pNewNode assign it to pNewNode
		m_pTop = NewNodeToPush;
		++mSize;
	}
}
///////////////////////////////////////////////////////////////
// Function: CAlley::PushWithNode
// Purpose: Add an exisiting node to top of stack
// Parameters:
// CarNode * pNewNode- pointer variable
// Local Variables:
// pointers 
// - return void type
////////////////////////////////////////////////////////////////

void CAlley::PushWithNode(CarNode *pNewNode)// type integer function pass by reference to pointer?
{
	if (mSize == 0)
	{
		m_pTop = pNewNode;  // put the head node at pNewNode Address
		m_pHead = pNewNode;
		++mSize;
	}
	else
	{
		m_pTop = pNewNode;
		++mSize;
	}
}
/////////////////////////////////////////////////////////////////
// Function: CAlley::Pop
// Purpose: Remove a node to top of alley (stack).
// Parameters:  
// CarNode * pNewNode- returns the node removed from top of alley
// Error message sent if alley is empty
// Local Variables: pTemp to return the node sent to Pop
//	
//					-
/////////////////////////////////////////////////////////////////
CarNode * CAlley::Pop()
{
	if (Empty()) {
		cout << "PARKING LOT IS EMPTY";
	}
	else {
		CarNode *  pNodeToPop = m_pTop;	// the node before the one after popping
		CarNode * pTemp; // used to return the popped node
		pTemp = m_pTop; // save the node to return
		if (m_pTop==m_pHead)
		{// only one node
			
			(pTemp->GetNext())->SetPrev(nullptr)  ;
			mSize--;
			return pTemp;
		}
		else
		{
			m_pTop = pNodeToPop->GetPrev();  // the new top points to the previous node now
			mSize--;
			return pTemp;
		}
			
	}
}
/////////////////////////////////////////////////////////////////
// Function: CAlley::PopReverse
// Purpose: Remove a node to top of alley (stack).
// Parameters:  
// CarNode * pNewNode- returns the node removed from top of alley
// Error message send if alley is empty
// Local Variables:
//					- Integer Ticket
//					-
/////////////////////////////////////////////////////////////////
CarNode * CAlley::PopReverse()
{

	if (Empty()) {
		cout << "PARKING LOT IS EMPTY";
	}
	else {
		CarNode *  pNodeToPop = m_pTop;	// the node before the one after popping
		CarNode * pTemp, *pTemp2; // used to return the popped node

		if (m_pTop == m_pHead)
		{// only one node
			pTemp = m_pTop; // save the node to return
			m_pHead = m_pTop = nullptr;
			mSize--;
			return pTemp;
		}
		else
		{
			pTemp2 = m_pTop;
			m_pTop = pNodeToPop->GetNext();  // the new top points to the previous node now
			mSize--;
			return pTemp2;
		}

	}
}
///////////////////////////////////////////////////////////////
// Function: CAlley::Park ( )
// Purpose: Park a car, if lot is not full. First allocate a
// node, then add it to the top of the stack
// Parameters:
// userTicketNum - the ticket number for the node to be added
// Local Variables:
// CarNode *pNewNode - local pointer to newly allocated node
// void status - returns nothing
//  
///////////////////////////////////////////////////////////////
int CAlley::Park(int userTicketNum)
{

	CarNode * Currptr = new CarNode;
	if (mSize == 0)
	{
		CarNode * headptr = new CarNode;
		m_pHead = headptr;
		headptr->SetTicketNum(userTicketNum);
		headptr->SetPrev(nullptr);
		Push(headptr);
		headptr->SetNext(nullptr);
		cout << "Ticket no. = " << userTicketNum<<endl;
		return ++userTicketNum; // make the next ticket number
	}
	else
	{
		Currptr = m_pTop;  // the current node address is in m_pTop
		CarNode * NewNode = new CarNode;
		NewNode->SetPrev(m_pTop);  // Set the previous node value
		//assign ticketnumber to the new node
		NewNode->SetTicketNum(userTicketNum);
		// assign m_pNext to the current node not the new node
		Currptr->SetNext(NewNode);  // put the next address into the previous node
		Push(NewNode);
		NewNode->SetNext(nullptr);
		cout << "Ticket no. = " << userTicketNum << endl;
		return ++userTicketNum; // make the next ticket number
	}
}
///////////////////////////////////////////////////////////////
// Function: CAlley:: Retrieve ( int userTicketNum, CAlley *pB)
// Purpose: Retrieve a car from alley A. Search for the car/node
// based on ticket num. by driving a car (popping off top) out of
// A and driving (pushing onto top) into B.
// If the car is found, it is not pushed onto B, but rather,
// it is deleted. Then the cars in B are moved back into A.
//
// Parameters:
// userTicketNum - the ticket number for the node to be added
// pB - pointer to CAlley B
//
// Local Variables: 
// CarNode * pCurr - local pointer used as index
// bool found - used to determine if car is found
// CarNode * pPrevNode , * pIterate_Backwards, * pNextNode, * pTempR
// CarNode * pInitialTop, * ptemp, * pTemp2 pointers 
///////////////////////////////////////////////////////////////
void CAlley::Retrieve(int userTicketNum, CAlley * pB)
{
	// This function is called at Alley A location
	int SetTicket;
	bool found = false;
	CarNode * pPrevNode = nullptr, * pIterate_Backwards, * pNextNode, * pTempR;
	CarNode * pInitialTop = m_pTop, * ptemp = m_pHead, * pTemp2 = m_pTop;

	if (!Empty())
	{
		for (int i = 0; i < mSize - 1; i++)
		{
			if (userTicketNum == pInitialTop->GetTicketNum())
			{
				found = true;
			
			}
			pInitialTop = pInitialTop->GetPrev();

		}
		if (userTicketNum == pInitialTop->GetTicketNum())
			found = true;
	}
	
	if (!found)
	{
		cout << "CAR NOT PARKED IN MY LOT " << endl;
		return;
	}
	pIterate_Backwards = m_pTop; // assign pointer to top of stack
	SetTicket = pIterate_Backwards->GetTicketNum();// access the first ticket number
	while (mSize!=0)//while alley A is not empty
							  // and ticket not found yet
	{
		if (SetTicket == userTicketNum)  // if matches exit while loop
		{
			found = true;
			if (pIterate_Backwards==m_pHead)
			{//delete first node
				if (mSize==1)
				{
					m_pHead = nullptr;
					--mSize;
					cout << "Here is your car:  " << SetTicket << endl;
				}
				else
				{
					pNextNode = pIterate_Backwards->GetNext();
					m_pHead = m_pTop = nullptr;
					pNextNode->SetPrev(nullptr);
					--mSize;
					cout << "Here is your car:  " << SetTicket << endl;
				}
				break;
			}
			else if (pIterate_Backwards==pTemp2)
			{//delete the tail node

				pPrevNode = pIterate_Backwards->GetPrev();
				pPrevNode->SetNext(nullptr);
				m_pTop = pPrevNode;
				--mSize;
				cout << "Here is your car:  " << SetTicket << endl;
				break;
			}
			else
			{// delete node in the middle
				pNextNode = pIterate_Backwards->GetNext();
				pPrevNode = pIterate_Backwards->GetPrev();
				pNextNode->SetPrev(pPrevNode);
				pPrevNode->SetNext(pNextNode);
				cout << "Here is your car:  " << SetTicket << endl;
				--mSize;
			}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
		}
		else {// Did not find the car so go to the next node
				pTempR = Pop();
				if (pB->mSize==0)
				{
					pB->m_pHead = pTempR;
				}
				pB->Push(pTempR); //push the node into Alley B
				pIterate_Backwards = pIterate_Backwards->GetPrev();// current pointer
				if (pIterate_Backwards!=nullptr)
				{
					SetTicket = pIterate_Backwards->GetTicketNum(); // get the next ticket
				}
			}// end of else
  }// end of while
	while (pB->mSize != 0)
	{
		pTempR = pB->PopReverse();
		PushWithNode(pTempR);
	}//end of while
	
} 
///////////////////////////////////////////////////////////////
// Function: CAlley:: Display ( )
// Purpose: Display the nodes in the stack/alley
// Parameters:
// m_pTop - pointer to the top of the alley (stack)
// m_pHead - Head pointer to the beginning of the stack 
//
// Local Variables:
//  pCurr - current pointer variable in the alley
//  
///////////////////////////////////////////////////////////////
void CAlley::Display()
{
	if (!Empty())
	{
		CarNode * pCurr = m_pTop;  // create a node pointer and assign it to m_pTop
		cout << "Alley A: ";
		for (int i = 0; i < mSize - 1; i++)
		{
			cout << " <" << pCurr->GetTicketNum() << ">  ";
			pCurr = pCurr->GetPrev();
		}
			cout << " <" << m_pHead->GetTicketNum() << ">  ";
	}
	else
	{
		cout << "The parking lot is empty " << endl;
	}
	cout << endl;
}

///////////////////////////////////////////////////////////////
// Function: void main()
// Purpose: Entry point into the C++ assignment 2 program
// The main function is where the program execution begins
// and ends
// Variables:
// userTicketNum - the ticket number for the node to be added
// pB - pointer to Class Alley B
// inputTicketStub - integer value user input to retrieve the car
// input - integer variable use to create ticket numbers
// CAlley classes - AlleyA and AlleyB
// enum is used to make the switch statement more readable
//  
///////////////////////////////////////////////////////////////
int main()
{
	static int ticketStub = 1;  //ticket stub is the pointer
	int inputTicketStub;
	char input;        //User inputs whether to Quit, Park, Display or Retrieve Car(s)      
	CAlley AlleyA, AlleyB;  // Create the parking alley
	enum commands { PARK = 'P', RETRIEVE = 'R', DISPLAY = 'D', QUIT = 'Q' };
	do
	{
		cout << "D)isplay     P)ark     R)etrieve     Q)uit  " ;
		cin >> input;
		input = toupper(input);
			switch (input)
			{
			case  PARK:	
				if (AlleyA.Full())
				{
					cout << "PARKING LOT FULL" << endl;
				}
				else
				{
					ticketStub = AlleyA.Park(ticketStub);
				}
				break;
			case RETRIEVE:
				cout << "Type in the ticket number ";
				cin >> inputTicketStub;
				AlleyA.Retrieve(inputTicketStub, &AlleyB);
				break;
			case DISPLAY:
				AlleyA.Display();
				break;
			default:
				cout <<endl<<"Invalid Command! Please try again." << endl;
				break;
			}//end of switch
	
	} while (input != 'Q' && input != 'q');  // end of do

}// end of main
