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
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
	int maxListCount = 100;
	LinkedList list;

	// Name of file to be saved and read from
	string fileName = "booklist.txt";


// Read from file **************************************************************


	ifstream readFile(fileName.c_str());
	string fileLine;

	// if 0, then error has occurred.
	int no_error = 1;
	if (readFile.is_open())
	{
		// Reads each line and uses parse function to store data
		// ParseLine will return 0 if an there is an issue with opening
		// the file.
		while (getline(readFile, fileLine) && no_error > 0)
		{
			// Checks to see if the count is greater than 100
			if (list.getCount() < maxListCount)
			{
				// First value of substring
				int sub1 = 0;

				// Second value of substring
				int sub2 = fileLine.find(',');

				string title;
				string author;
				string date;

				// Tries to parse the information into the correct fields
				// Exception is thrown if error occurs.
				try
				{
					// Parses the title
					title = fileLine.substr(sub1, (sub2-sub1));

					// Removes title from line
					sub1 = title.length() + 1;
					sub2 = fileLine.length();
					fileLine = fileLine.substr(sub1, (sub2 - sub1));

					// Parses the quantity
					sub1 = 0;
					sub2 = fileLine.find(',');
					author = fileLine.substr(sub1, (sub2-sub1));

					// Parses the price
					sub1 = author.length() + 1;
					sub2 = fileLine.length();
					date = fileLine.substr(sub1, (sub2 - sub1));



					// Creates new part from the parsed info
					list.Insert(title, author, date);

					no_error = 1;
				}
				catch (int i)
				{
					cout << "ERROR: Unable to open file" << endl;
					no_error = 0;
				}
			}
			else
			{
				no_error = 0;
			}
		}

		// Tells user if there was an error reading the file
		if (no_error == 0)
		{
			cout << "Error Reading File" << endl;
		}
		readFile.close();
	}


// Enter menu loop *************************************************************


	// Enters menu loop
	bool isExit = false;
	while (!isExit)
	{
		// Menu option chosen by user
		int option = 0;

		// Requests user input for menu selection
		bool isValid = false;
		while (!isValid)
		{
			// Application title
			cout << "\n\n---------------- Linked List Program - Assignment 4 "
					"-----------------" << endl;
			cout << "      This application utilizes a linked list to hold book"
					" data      " << endl;
			cout << "----------------------------------------------------"
					"-----------------\n" << endl;

			// Menu options
			cout << "1. Add a book" << endl;
			cout << "2. Delete a book" << endl;
			cout << "3. Retrieve a book" << endl;
			cout << "4. Traverse list forward" << endl;
			cout << "5. Traverse list backward" << endl;
			cout << "6. Save and Exit Program\n" << endl;

			// Receives user input and places it in option
			cout << "Please select a menu by entering a number: " << endl;
			cin >> option;

			// Checks to see if input is between 1 and 5, and max
			// inventory has been reached
			if ((option >= 1) && (option <= 6))
			{

				isValid = true;

				// Enters page depending on chosen option
				switch (option)
				{
				case 1 :

					// If max list count is reached, then skip insert method
					if (list.getCount() > maxListCount)
					{
						cout << "\n*** Max Count Reached ***" << endl;
					}
					else
					{
						string title = "";
						string author = "";
						string date = "";

						cout << "\n1. Add a book:\n" << endl;
						cout << "Enter Title: " << endl;
						getline(cin, title);
						cout << "Enter Author: " << endl;
						getline(cin, author);
						cout << "Enter Date (MM/DD/YYY): " << endl;
						getline(cin, date);

						cout << endl;

						list.Insert(title, author, date);
					}
					break;

				case 2 :

					// Checks to see if list is populated
					if (list.getCount() == 0)
					{
						cout << "\n*** No Items In List ***" << endl;
					}
					else
					{
						string title = "";

						cout << "\n2. Delete a book:\n" << endl;
						cout << "Enter Title: " << endl;
						getline(cin, title);

						list.Delete(title);
					}
					break;

				case 3 :
					// Checks to see if list is populated
					if (list.getCount() == 0)
					{
						cout << "\n*** No Items In List ***" << endl;
					}
					else
					{
						string title = "";

						cout << "\n3. Retrieve a book:\n" << endl;
						cout << "Enter Title: " << endl;

						// TODO Figure out how to account for space
						getline(cin, title);

						list.Retrieve(title);
					}
					break;

				case 4 :
					// Checks to see if list is populated
					if (list.getCount() == 0)
					{
						cout << "\n*** No Items In List ***" << endl;
					}
					else
					{
						cout << "\n4. Traverse list forward:\n" << endl;

						list.Traverse(false);
					}
					break;

				case 5 :
					// Checks to see if list is populated
					if (list.getCount() == 0)
					{
						cout << "\n*** No Items In List ***" << endl;
					}
					else
					{
						cout << "\n4. Traverse list backward:\n" << endl;

						list.Traverse(true);
					}
					break;

				case 6 :
					isExit = true;
					break;
				}
			}
			else
			{
				cout << "\n************************** Invalid "
						"option ***************************" << endl;
			}

			// Clears any data in the cin buffer
			cin.clear();
			cin.ignore(10000,'\n');
		}
	}


// Save to file ****************************************************************


	// Opens Text file and saves each part until inventory is complete.
	ofstream saveFile(fileName.c_str());
	int listCount = list.getCount();
	if (saveFile.is_open())
	{
		Node *currentPtr = list.getHead();
		Node *nextPtr = currentPtr->getNextPointer();

		// Writes every item to its own line using commas as delimiters
		for (int i = 0; i < listCount; i++)
		{

			string title = currentPtr->getBookTitle();
			string author = currentPtr->getAuthor();
			string date = currentPtr->getDate();
			saveFile << title << "," << author << "," << date << endl;

			delete currentPtr;

			if (i != listCount - 1)
				currentPtr = nextPtr;
				nextPtr = currentPtr->getNextPointer();
		}
		saveFile.close();

		cout << "\nFile Saved" << endl;
	}

	cout << "Program Ended" << endl;

	return 0;

}





