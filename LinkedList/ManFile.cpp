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
	void MergeSort(Node **head);
	/* function prototypes */
	struct Node* SortedMerge(struct Node* a, struct Node* b);
	void FrontBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef);

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


/* sorts the linked list by changing next pointers (not data) */
void LinkedList::MergeSort(struct Node** headRef)
{
	struct Node* head = *headRef;
	struct Node* a;
	struct Node* b;

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL))
	{
		return;
	}

	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);

	/* Recursively sort the sublists */
	MergeSort(&a);
	MergeSort(&b);

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b);
}

/* Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra Node should go in the front list.
Uses the fast/slow pointer strategy.  */
void LinkedList::FrontBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef)
{
	struct Node* fast;
	struct Node* slow;

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

struct Node* LinkedList::SortedMerge(struct Node* a, struct Node* b)
{
	cc++;
	cout << cc << endl;
	/* Base cases */
	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);

	/* Pick either a or b, and recur */
	if (a->val <= b->val)
	{
		a->next = SortedMerge(a->next, b);
		return a;
	}
	else
	{
		b->next = SortedMerge(b->next, a);
		return b;
	}

	//struct Node* result = NULL;

	///* Base cases */
	//if (a == NULL)
	//	return(b);
	//else if (b == NULL)
	//	return(a);

	///* Pick either a or b, and recur */
	//if (a->val <= b->val)
	//{
	//	result = a;
	//	result->next = SortedMerge(a->next, b);
	//}
	//else
	//{
	//	result = b;
	//	result->next = SortedMerge(a, b->next);
	//}
	//return(result);
}


///////////////////////////
//driver program, main
int main()
{
	LinkedList l1;
	
	l1.InsertAtFirst(1);
	l1.InsertAtFirst(500);
	l1.InsertAtFirst(135);
	l1.InsertAtFirst(7);
	//l1.InsertAtFirst(11);

	//l1.DeleteNode(5);
	//l1.InsertAtPosition(100, 1);	// i.e. 2nd position, as we considered initial position is 0.
	Node **temp = l1.GetHead();		//
	l1.MergeSort(temp);

	return 0;
}