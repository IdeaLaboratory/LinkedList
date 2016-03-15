#include "ManFile.h"
#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node *next;
}*start;

class LinkedList
{
private:
	Node *head = NULL;
	//just create a Node
	Node* CreateNode(int value);

public:
	int cc = 0;
	Node** GetHead()
	{
		return &head;
	}
	void InsertAtFirst(int input);
	void DeleteNode(int inputValue);
	void InsertAtPosition(int input, int pos);
	void SelectionSort(Node **input);
};

Node* LinkedList::CreateNode(int pValue)
{
	Node *resultNode = new Node(); //	Is there really any deference if we add this code	" ? ?
	resultNode->val = pValue;
	resultNode->next = NULL;
	return resultNode;
}

void LinkedList::InsertAtFirst(int input)
{
	Node * temp = CreateNode(input);

	//link with existing list
	temp->next = head;
	head = temp;
}

void LinkedList::DeleteNode(int inputValue)
{
	struct Node* current = head;
	struct Node* previous = NULL;

	while (current != NULL)
	{
		//iteration 
		if (current->val == inputValue)
		{
			//deleting head
			if (previous == NULL)
			{
				current = current->next;
				free(head);
				break;	//reduce un necessary looping
			}
			else
			{
				previous->next = current->next;
				free(current);
				current = previous->next;
				break;	//reduce un necessary looping
			}
		}
		//move the pointer of "previous" and "current" Node
		else
		{
			previous = current;
			current = current->next;
		}
	}
}

//considered, initial position is 0.
void LinkedList::InsertAtPosition(int input, int pos)
{
	//
	Node *current = head;
	Node *previous = NULL;

	for (int i = 0; i < pos; i++)	// i < initial position [either 0 or 1],	i < given position
	{
		previous = current;
		current = current->next;
	}
	//create a Node with given value and lined at given position of existing list
	Node *temp = CreateNode(input);
	previous->next = temp;
	temp->next = current;
}

void LinkedList::SelectionSort(Node **input)
{
	Node *startPtr = *input;
	Node *endPtr = NULL;
	//loop i= 0 to n-1
	while (startPtr->next!=NULL)
	{
		endPtr = startPtr->next;
		//loop j=i+1 to n
		while (endPtr!=NULL)
		{
			//swap if require
			if (startPtr->val > endPtr->val)
			{
				int tempVal = startPtr->val;
				startPtr->val = endPtr->val;
				endPtr->val = tempVal;
			}
			endPtr = endPtr->next;
		}
		startPtr = startPtr->next;
	}
}

///////////////////////////
//driver program, main
int main()
{
	LinkedList l1;
	
	l1.InsertAtFirst(1000);
	l1.InsertAtFirst(135);
	l1.InsertAtFirst(3500);
	l1.InsertAtFirst(15);
	l1.InsertAtFirst(7);
	l1.InsertAtFirst(1);

	//l1.DeleteNode(5);
	//l1.InsertAtPosition(100, 1);	// i.e. 2nd position, as we considered initial position is 0.
	Node **temp = l1.GetHead();		//

	l1.SelectionSort(temp);

	return 0;
}