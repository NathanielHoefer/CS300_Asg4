/*****************************************************************************/
/* Program 4 - Linked List Class Creation									 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #4


Class Name: LinkedList
	This class initializes a unordered double linked list containing the information of
	a book, its author, and the date read within each node.

Data:
		- (Node) *mHead: Pointer to the Head of the list
		- (Node) *mTail: Pointer to the Tail of the list
		- (int) mCount: The number of nodes within the list

Constructors:
		+ LinkedList() - Creates an empty list
		+ LinkedList(string title, string author, string date): Creates a node with
			the information given and places it at the end of the list

Mutator Functions:
		+ setHead
		+ setTail
		+ setCount

Accessor Functions:
		+ getHead
		+ getTail
		+ getCount
		+ isEmpty

Functions:
		+ Insert(string title, string author, string date) - create a new node
			at the end of the linked list with the arguments passed.
			Preconditions: Date must be in the format MM/DD/YYYY to be properly
				read.
			Postconditions: New node is appended at end of list, tail is updated
			> Create new node with info
			> Check to see if list is empty, if so, update tail and head to
				new node.
			> Else, change next pointer of node in tail to new node to link and
				update tail to new node
			> Increase count by 1

		+ Delete(string title) - Searches and deletes the node(s) with a given
			title.
			Preconditions: Title must be spelled exactly the same to be found.
			Postconditions: Node(s) is deleted if found and message displayed
			> Loop through every node in list
			> Compare the title given to title in node
			> If same, print data (ProcessData()) for all same titles
			> Verify that they are to be deleted
			> If yes, remove node, decrease count, and keep track of number
				of nodes deleted
			> If list now empty, update head and tail accordingly
			> Print result to screen

		+ Traverse(bool backwards) - Prints each node to the screen
			Precondition: None
			Postcondition: Nodes are printed to screen either forwards or
				backwards
			> Check if list is empty, and display message if so
			> If forwards, print using ProcessData() starting with the head node
			> If backwards, print using ProcessData() starting with tail node

		+ Retrieve(string title) - retrieves the nodes with the given title
			and prints info
			Precondition: None
			Postcondition: Book info is printed to screen
			> Checks to see if list is empty
			> Compare each node's title to the title given
			> Print the node's info if title matches

*/
