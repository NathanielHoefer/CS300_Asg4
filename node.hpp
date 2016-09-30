/*****************************************************************************/
/* Program 4 - Linked List Class Creation									 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #4


Class Name: Node
	This class is used for creating a node within a double linked list which
	incorporates a previous and next pointer, along with the data of the book.

Data:
		- (string) mBookTitle: The title of a book
		- (string) mAuthor: The author of the book
		- (int) mDateRead: contains numerical value of the date in the
			format of MMDDYYYY
		- (Node) *mNextNode: Pointer to next node in list
		- (Node) *mPrevNode: Pointer to previous node in list

Constructors:
		+ Node() - Sets the value to default
		+ Node(string title, string author, int date): creates node with the
			arguments passed

Mutator Functions:
		+ setNextPointer
		+ setPrevPointer

Accessor Functions:
		+ getNextPointer
		+ getPrevPointer
		+ getBookTitle
		+ getAuthor

Functions:
		+ CompareTitle(string title) - compare a given book title against the
			one in the class.
			Preconditions: None
			Postconditions: returns numeric value depending on the
				lexigraphic ordering
			Returns: (int) -1 if title < mBookTitle, 0 if title == mBookTitle,
				1 if title > mBookTitle.
			> Compare string and return value based on result

		+ CompareAuthor(string author) - compare a given author against the
			one in the class.
			Preconditions: None
			Postconditions: returns numeric value depending on the
				lexigraphic ordering
			Returns: (int) -1 if title < mAuthor, 0 if author == mAuthor,
				1 if author > mAuthor.
			> Compare string and return value based on result

		+ ProcessData() - Print the data to the screen
			Preconditions: None
			Postconditions: Data in node is printed to the screen
			> Print title
			> Print author
			> Print formatted date

*/
#include <string>

using namespace std;

#ifndef NODE_HPP_
#define NODE_HPP_

class Node
{
	private:

// Member Variables

	// The title of a book
	string mBookTitle;

	// The author of the book
	string mAuthor;

	// contains numerical value of the date in the format of MMDDYYYY
	string mDataRead;

	// Pointer to next node in list
	Node *mNextNode;

	// Pointer to previous node in list
	Node *mPrevNode;


	public:

// Constructors
	Node();
	Node(string title, string author, string date);


// Mutator and Accessor Functions
	void setNextPointer(Node *prt) { mNextNode = prt; };
	void setPrevPointer(Node *prt) { mPrevNode = prt; };
	Node * getNextPointer() { return mNextNode; };
	Node * getPrevPointer() { return mPrevNode; };
	string getBookTitle() { return mBookTitle; };
	string getAuthor() { return	mAuthor; };
	string getDate() { return mDataRead; };



// Member Functions


//	CompareTitle(string title) - compare a given book title against the one in
//	the class.
//	- Preconditions: None
//	- Postconditions: returns numeric value depending on the lexigraphic
//		ordering
//	- Returns: (int) -1 if title < mBookTitle, 0 if title == mBookTitle,
//		1 if title > mBookTitle.
	int CompareTitle(string title);



//	CompareAuthor(string author) - compare a given author against the one in the
//	class.
//	- Preconditions: None
//	- Postconditions: returns numeric value depending on the lexigraphic
//		ordering
//	- Returns: (int) -1 if title < mAuthor, 0 if author == mAuthor,
//		1 if author > mAuthor.
	int CompareAuthor(string author);



//	ProcessData() - Print the data to the screen
//	- Preconditions: None
//	- Postconditions: Data in node is printed to the screen
	void ProcessData();


};

#endif /* NODE_HPP_ */
