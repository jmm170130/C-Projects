//implementation file for the NumberList class. Contains member function definitions
#include "NumberList.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


//insertNode inserts and sorts a node in to the list
void NumberList::insertNode(double number)
{
	ListNode *newNode;			 //A new node
	ListNode *nodePtr; 			//To traverse the list
	ListNode *previousNode = nullptr; 	//to point to the previous node

	//create a new node and set the data equal to the number from the insert file
	newNode = new ListNode;
	newNode->data = number;

	//if the list is empty, point the head to the newNode
	if(head == NULL)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else//if the list is not empty
	{
		//position nodePtr at the head of the list
		nodePtr = head;

		//set previousNode to NULL
		previousNode = nullptr;

		//skip all nodes whose value is less than the number being inserted
		while(nodePtr != nullptr && nodePtr->data < number)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}			//if previousNode remains equal to NULL insert the new node before all other nodes
		if(previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else //otherwise  insert after the previous node
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

//deleteList deletes the list in order to free up memory
void NumberList::deleteList()
{
	ListNode *nodePtr; //to traverse the list
	ListNode *nextNode; // to point to the next node

	//set nodePtr at the head of the list
	nodePtr = head;

	//continue while nodePtr isn't equal NULL
	while(nodePtr)
	{
		//save a pointer to the next node
		nextNode = nodePtr->next;

		//delete the current node
		delete nodePtr;

		//position nodePtr at the next node
		nodePtr = nextNode;
	}
	head = NULL;
}

//printList prints the sorted list
void NumberList::printList(int count)
{
	//set a pointer to the contents of the head pointer
	ListNode *nodePtr;
	nodePtr = head;

	//while the pointer is not NULL continue printing the list
	while(nodePtr)
	{
		cout << nodePtr->data;  //output data
		cout << endl;
		nodePtr = nodePtr->next; //set the nodePtr to the next node in the list
	}
	//output the number of items in the list

	cout << "Total number of Items: " << count << endl;

}
