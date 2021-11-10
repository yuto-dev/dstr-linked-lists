// A complete working C++ program to
// demonstrate all insertion methods
#include <iostream>
using namespace std;

struct patient_data {
	int id, age; 
	string firstName, lastName, gender, phone, address, visitDate, visitTime, disabilityOption; 
};

// A linked list node
class Node
{
public:
	int id;
	string name;
	Node* next;
	Node* prev;
};

/* Given a reference (pointer to pointer)
to the head of a list
and an int, inserts a new node on the
front of the list. */
void push(Node** head_ref, int nID, string nName)
{
	/* 1. allocate node */
	Node* new_node = new Node();

	/* 2. put in the data */
	new_node->id = nID;
	new_node->name = nName;

	/* 3. Make next of new node as head
	and previous as NULL */
	new_node->next = (*head_ref);
	new_node->prev = NULL;

	/* 4. change prev of head node to new node */
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	/* 5. move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Given a node as prev_node, insert
a new node after the given node */
void insertAfter(Node* prev_node, int nID, string nName)
{
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL)
	{
		cout << "the given previous node cannot be NULL";
		return;
	}

	/* 2. allocate new node */
	Node* new_node = new Node();

	/* 3. put in the data */
	new_node->id = nID;
	new_node->name = nName;

	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next;

	/* 5. Make the next of prev_node as new_node */
	prev_node->next = new_node;

	/* 6. Make prev_node as previous of new_node */
	new_node->prev = prev_node;

	/* 7. Change previous of new_node's next node */
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

/* Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end */
void append(Node** head_ref, int nID, string nName)
{
	/* 1. allocate node */
	Node* new_node = new Node();

	Node* last = *head_ref; /* used in step 5*/

	/* 2. put in the data */
	new_node->id = nID;
	new_node->name = nName;

	/* 3. This new node is going to be the last node, so
		make next of it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new
		node as head */
	if (*head_ref == NULL)
	{
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;

	/* 7. Make last node as previous of new node */
	new_node->prev = last;

	return;
}

// This function prints contents of
// linked list starting from the given node
void printList(Node* node)
{
	Node* last;
	cout << "\nTraversal in forward direction \n";
	while (node != NULL)
	{
		cout << node->id << " ";
		cout << node->name << " " << endl;
		last = node;
		node = node->next;
	}
}

void modifyList(Node* node, int oldID, int nID)
{
	Node* last;
	cout << "\nTraversal in forward direction \n";
	while (node != NULL)
	{
		if(node->id == oldID){
			node->id = nID;
		}

		cout << node->id << " ";
		cout << node->name << " " << endl;
		last = node;
		node = node->next;
	}
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	// Insert 6. So linked list becomes 6->NULL
	append(&head, 1, "Reimu");

	// Insert 7 at the beginning. So
	// linked list becomes 7->6->NULL
	push(&head, 2, "Marisa");

	// Insert 1 at the beginning. So
	// linked list becomes 1->7->6->NULL
	push(&head, 3, "Sanae");

	// Insert 4 at the end. So linked
	// list becomes 1->7->6->4->NULL
	append(&head, 4, "Sakuya");

	// Insert 8, after 7. So linked
	// list becomes 1->7->8->6->4->NULL
	insertAfter(head->next, 8, "Reisen");

	cout << "Created DLL is: ";
	printList(head);
	modifyList(head, 4, 6);
	printList(head);

	return 0;
}

// This is code is contributed by rathbhupendra
