/*****************************************************************************/
/* Program 4 - Linked List Class Creation									 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #4

*/

#include "linkedList.hpp"
#include "node.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

/*****************************************************************************/
// Class Source Functions
/*****************************************************************************/


// CONSTRUCTORS ***************************************************************


LinkedList::LinkedList()
{
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}



// METHODS ********************************************************************


//	Create a new node at the end of the linked list with the arguments passed.
void LinkedList::Insert(string title, string author, string date)
{
	// Creates a pointer to new node with entered info
	Node *newPtr = new Node(title, author, date);


	// Checks to see if linked list is empty
	if (isEmpty())
	{
		mHead = newPtr;
		mTail = newPtr;
	}
	else
	{
		// Attaches node to the end of list and update tail
		newPtr->setPrevPointer(mTail);
		mTail->setNextPointer(newPtr);
		mTail = newPtr;
	}

	// Increase count by 1
	mCount++;
}


/*****************************************************************************/


//	Searches and deletes the node(s) with a given title.
void LinkedList::Delete(string title)
{
	Retrieve(title);

	string reply = "";
	cout << "Do you want to delete the listed entries? (Y/N)" << endl;
	cin >> reply;

	if (reply == "Y" || reply == "y")
	{
		Node *currentPtr = mHead;
		Node *nextPtr = mHead;
		int numberOfCompares = mCount;
		int compareResult;
		int itemsDeleted = 0;

		// Cycles through each node
		for (int i = 0; i < numberOfCompares; i++)
		{
			// Loads next pointer in preparation for next node
			nextPtr = currentPtr->getNextPointer();

			// Compares the entered title to node title
			compareResult = currentPtr->CompareTitle(title);

			// Executes if titles match
			if (compareResult == 0)
			{
				Node *next = currentPtr->getNextPointer();
				Node *prev = currentPtr->getPrevPointer();

				// If selection is only item in list
				if (mHead == mTail)
				{
					mHead = mTail = NULL;
				}
				// If selection is last item in list
				else if (next == NULL)
				{
					prev->setNextPointer(NULL);
					mTail = prev;
				}
				// If selection is first item in list
				else if (prev == NULL)
				{
					next->setPrevPointer(NULL);
					mHead = next;
				}
				// If selection is in middle of list
				else
				{
					prev->setNextPointer(next);
					next->setPrevPointer(prev);
				}

				delete currentPtr;
				itemsDeleted++;
				mCount--;
			}

			currentPtr = nextPtr;
		}

		cout << itemsDeleted << " item(s) deleted" << endl;
	}
}


/*****************************************************************************/


//	Prints each node to the screen
void LinkedList::Traverse(bool backwards)
{
	// Checks if list is empty
	if (isEmpty())
	{
		cout << "List is empty" << endl;
	}
	else
	{
		// If backwards is true then begins at tail
		if (backwards)
		{
			Node *currentPtr = mTail;
			for (int i = 0; i < mCount; i++)
			{
				// Prints info and updates ptr to prev pointer
				currentPtr->ProcessData();
				currentPtr = currentPtr->getPrevPointer();
			}
		}
		// If not backwards, then begins at head until NULL is reached
		else
		{
			Node *currentPtr = mHead;

			for (int i = 0; i < mCount; i++)
			{
				// Prints info and updates ptr to next pointer
				currentPtr->ProcessData();
				cout << "	Current: " << currentPtr << " Next: " << currentPtr->getNextPointer() << endl;
				currentPtr = currentPtr->getNextPointer();
			}
		}
	}
}


/*****************************************************************************/


//	retrieves the nodes with the given title and prints info
void LinkedList::Retrieve(string title)
{
	// Checks if list is empty
	if (isEmpty())
	{
		cout << "List is empty" << endl;
	}
	else
	{
		Node *currentPtr = mHead;

		// Cycles through all nodes
		for (int i = 0; i < mCount; i++)
		{
			// If titles match, node info is printed
			if (currentPtr->CompareTitle(title) == 0)
				currentPtr->ProcessData();

			// Updates to next node
			currentPtr = currentPtr->getNextPointer();
		}
	}
}
