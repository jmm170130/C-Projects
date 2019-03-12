//specification file for the NumberList class
#ifndef NUMBERLIST_H
#define NUMBERLIST_H
#include <iostream>
#include <string>

class NumberList
{
	private:

		//declare the structure for the list
		struct ListNode
		{
			double data;
			ListNode *next;
		};

		ListNode *head;  //create a "head" that will be used as a pointer to a node

	public:
		//Constructor
		NumberList()
			{ head = NULL; }

		//Linked list operations
		void insertNode(double);
		void deleteList();
		void printList(int );
};

#endif
