/*****************************************************************************/
/* Program 4 - Linked List Class Creation									 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #4


Description of the Problem:
	For this program, you are going to modify the Node class that you wrote for
	program #3 and implement a double linked list.  The node class will have the
	same member functions as before with the addition of another link.  You will
	now have a previous link (pointer) and a next link (pointer).  All of the
	information will be written to a file.  Just as in the first program, you
	are to check to see if the file exists.  If it does, open the file and
	populate the list.  Otherwise, when the program exits, print the information
	to a file.  Call the file “booklist.txt”.

Functions:
	+ main() - Loads data from file to new linked list if applicable and then
		presents the user with a menu with 6 choices:
			1. Add a book
			2. Delete a book
			3. Retrieve a book
			4. Traverse list forward
			5. Traverse list backward
			6. Exit program
		Preconditions: If file booklist.txt exists, then it will be read
		Postconditions: booklist.txt is saved with new book info
		> Check to see if txt file exists and parses info into new linked list.
		> Present user with menu
		> Option 1: ask for new book info and use insert method to create node
		> Option 2: ask for title to delete and use delete method
		> Option 3: ask for title and use retrieve method
		> Option 4: Use the traverse method
		> Option 5: Use the traverse method backward version
		> Option 6: Save list in txt file and exit program

*/

#include "node.hpp"
#include "linkedList.hpp"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	cout << "--------------------- Program 3 -----------------------\n" << endl;

	// Creates an array to contain 5 nodes
	Node * bookArray[5];

	// Creates 5 nodes with preset values
	bookArray[0] = new Node("Don Quixote",
			"Miguel de Cervantes", "01/15/1843");
	bookArray[1] = new Node("Tale of Two Cities",
			"Charles Dickens", "11/04/1993");
	bookArray[2] = new Node("The Hobbit",
			"J.R.R. Tolkien", "05/23/2001");
	bookArray[3] = new Node("The Great Divorce",
			"C.S. Lewis", "08/14/1986");
	bookArray[4] = new Node("The Catcher in the Rye",
			"J.D. Salinger", "12/25/2013");

	// Links the nodes using the member variables and compares the titles
	// of the next node.
	for (int i = 0; i < 4; i++)
	{
		bookArray[i]->setPointer(bookArray[i+1]);

		// Prints the current node title and author
		cout << "The book " << bookArray[i]->getBookTitle() << ", by " <<
				bookArray[i]->getAuthor() << " is ordered ";

		// Compares the values of the title
		int x = bookArray[i]->CompareData(bookArray[i+1]->getBookTitle());

		// Translates the compare value to the correct output
		if (x > 0)
			cout << "after ";
		else if (x < 0)
			cout << "before ";
		else
			cout << "equal to ";


		// Prints the next node title and author
		cout << bookArray[i+1]->getBookTitle() << ", by " <<
				bookArray[i+1]->getAuthor() << "." << endl;
	}

	cout << "\n";

	// Prints the information of a node, then deletes it
	for (int i = 0; i < 5; i++)
	{
		bookArray[i]->ProcessData();
		delete bookArray[i];
	}

	cout << "\nProgram Complete" << endl;

	return 0;
}




