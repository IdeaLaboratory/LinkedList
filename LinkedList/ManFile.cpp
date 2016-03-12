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
	Node head;

public:
	Node* CreateNode(int value);

};

Node* LinkedList::CreateNode(int pValue)
{
	Node *resultNode; //	Is there really any deference if we add this code	"= new Node" ?? 
	resultNode->val = pValue;
	resultNode->next = NULL;
	return resultNode;
}

//driver program, main
int main()
{
	return 0;
}