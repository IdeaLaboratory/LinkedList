#include "ManFile.h"
#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
	int val;
	struct Node *next;
};

class LinkedList
{
private:
	Node *head;
	//just create a Node
	Node* CreateNode(int value);

public:
    LinkedList();
	Node** GetHead()
	{
		return &head;
	}
	void InsertAtFirst(int inputValue);
	void DeleteNode(int inputValue);
	void InsertAtPosition(int input, int pos);
	void MergeSort(Node **head);
	/* function prototypes */
	Node* SortedMerge(Node* a,Node* b);
	void FrontBackSplit(Node* source, Node** frontRef, Node** backRef);

	//InsertedInSorted
	void InsertedInSorted(int inputValue);

};

LinkedList::LinkedList()
{
    head = NULL;
}



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
	Node* current = head;
	Node* previous = NULL;

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


/* sorts the linked list by changing next pointers (not data) */
void LinkedList::MergeSort(Node** headRef)
{
	Node* head = *headRef;
	Node* firstHalf;
	Node* secondHalf;

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL))
	{
		return;
	}

	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &firstHalf, &secondHalf);

	/* Recursively sort the sublists */
	MergeSort(&firstHalf);
	MergeSort(&secondHalf);

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(firstHalf, secondHalf);
}

/* Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra Node should go in the front list.
Uses the fast/slow pointer strategy.  */
void LinkedList::FrontBackSplit(Node* source, Node** frontRef, Node** backRef)
{
	Node* fast;
	Node* slow;

	slow = source;
	fast = source->next;

	/* Advance 'fast' two Nodes, and advance 'slow' one Node */
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}

	}/* 'slow' is before the midpoint in the list, so split it in two
		at that point. */
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;	//split the link
}

Node* LinkedList::SortedMerge(Node* firstHalf, Node* secondHalf)
{
	/* Base cases */
	if (firstHalf == NULL)
		return(secondHalf);
	else if (secondHalf == NULL)
		return(firstHalf);

	/* Pick either a or b, and recur */
	if (firstHalf->val <= secondHalf->val)
	{
		firstHalf->next = SortedMerge(firstHalf->next, secondHalf);
		return firstHalf;
	}
	else
	{
		secondHalf->next = SortedMerge(secondHalf->next, firstHalf);
		return secondHalf;
	}
}


void LinkedList::InsertedInSorted(int inputValue)
{
	Node *tempNode = head;
	//get the position to insert
	while (tempNode && tempNode->next && tempNode->next->val < inputValue)
	{
		tempNode = tempNode->next;
	}
	
	Node *newNode= new Node();
	newNode->val = inputValue;
	newNode->next = tempNode->next;
	tempNode->next = newNode;
}

///////////////////////////
//driver program, main
int main()
{
	LinkedList l1;
	Node **temp = l1.GetHead();		//

	//Insert node in list
	l1.InsertAtFirst(1);
	l1.InsertAtFirst(500);
	l1.InsertAtFirst(135);
	l1.InsertAtFirst(7);
	l1.InsertAtFirst(311);

	//insert a node in given position
	//l1.InsertAtPosition(100, 1);	// i.e. 2nd position, as we considered initial position is 0.
	

	//sort the list
	l1.MergeSort(temp);

	//Issert a node in sorted list
	l1.InsertedInSorted(247);

	//delete a node
	//void deleteNode(struct node *head, struct node *n)
	//l1.DeleteNode(7);

	return 0;
}
