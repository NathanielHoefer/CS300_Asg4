/*****************************************************************************/
/* Program 4 - Linked List Class Creation									 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #4
*/
#include "node.hpp"

#include <iostream>
#include <string>

using namespace std;

/*****************************************************************************/
// Class Source Functions
/*****************************************************************************/


// CONSTRUCTORS ***************************************************************


Node::Node()
{
	mBookTitle = "Title";
	mAuthor = "Author";
	mDataRead = "01/01/1900";
	mNextNode = NULL;
	mPrevNode = NULL;
}


Node::Node(string title, string author, string date)
{
	mBookTitle = title;
	mAuthor = author;
	mDataRead = date;
	mNextNode = NULL;
	mPrevNode = NULL;
}



// METHODS ********************************************************************


// Compare a given book title against the one in the class.
int Node::CompareTitle(string title)
{
	return mBookTitle.compare(title);
}


/*****************************************************************************/


// Compare a given author against the one in the class.
int Node::CompareAuthor(string author)
{
	return mAuthor.compare(author);
}


/*****************************************************************************/



// Print the data to the screen
void Node::ProcessData()
{

	// Prints node info to screen
	cout << mBookTitle << ", " << mAuthor << ", " << mDataRead << endl;
}
