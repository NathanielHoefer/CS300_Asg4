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


//	Delete(string title) - Searches and deletes the node(s) with a given title.
void LinkedList::Delete(string title)
{
	Retrieve(title);

	string reply = "";
	cout << "Do you want to delete the listed entries? (Y/N)" << endl;
	reply << cin;

	if (reply == "Y" || reply == "y")
	{
		Node *CurrentPtr = mHead;
		int compareResult;
		int itemsDeleted = 0;

		// Cycles through each node
		for (int i = 0; i < mCount; i++)
		{
			// Compares the entered title to node title
			compareResult = CurrentPtr->CompareTitle(title);

			if (compareResult == 0)
			{
				Node *next = CurrentPtr->getNextPointer();
				Node *prev = CurrentPtr->getPrevPointer();

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

				delete CurrentPtr;
				itemsDeleted++;
				mCount--;
				//TODO update pointer
			}
		}

		cout << itemsDeleted << " item(s) deleted" << endl;
	}
}


/*****************************************************************************/


//	Traverse(bool backwards) - Prints each node to the screen
void LinkedList::Traverse(bool backwards)
{

}


/*****************************************************************************/


//	Retrieve(string title) - retrieves the nodes with the given title and
//	prints info
void LinkedList::Retrieve(string title)
{

}
