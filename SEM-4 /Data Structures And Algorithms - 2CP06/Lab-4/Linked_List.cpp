#include <iostream>
using namespace std;

class Linked_List
{
	// Node : An Element OF Linked List which has two data member data and pointer of Next Node
	struct Node
	{
		int data;
		Node* next;

		Node(int data) {
			this->data = data;
			this->next = NULL;
		}
	};

	// First or head Element of Linked List
	Node* head;
public:

	// Default Constructor
	Linked_List() : head(NULL) {
		cout << "> Default Constructor Invoked..." << endl;
	}

	// Parameterized Constructor
	Linked_List(int data) {
		Node* Newnode = new Node(data);
		head = Newnode;

		cout << "> Linked List Created With Parameterized Constructor..." << endl;
	}

	// Destuctor
	~Linked_List() {
		while (head != NULL) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}

		cout << "> Linked List Destroyed Successfully !!!" << endl;
	}

	// Display Function
	void display () {

		cout << "> Linked List : ";
		Node* nextnode = head;

		while (nextnode != NULL) {
			cout << nextnode->data << "->";
			nextnode = nextnode->next;
		}

		cout << "NULL" << endl;
	}

	// Count The Number Of Nodes In Linked List
	int cntNode () {
		int cnt = 0;
		Node* nextnode = head;

		while (nextnode != NULL) {
			cnt++;
			nextnode =	nextnode->next;
		}

		return cnt;
	}

	// Insert An Element At Beginning Of Linked List
	void insert_at_beginning (int data) {
		Node* Newnode = new Node(data);
		Newnode->next = head;
		head = Newnode;
		cout << "> Create A Node At Beginning Of Linked List..." << endl;
	}

	// Insert An Element At End Of Linked List
	void insert_at_end (int data) {
		Node* Newnode = new Node(data);
		if (head == NULL) {
			head = Newnode;
			return;
		}

		Node* nextnode = head;

		while (nextnode->next != NULL) {
			nextnode = nextnode->next;
		}

		nextnode->next = Newnode;
		cout << "> Create A Node At End Of Linked List..." << endl;
	}

	// Insert An Element At Given Position In Linked List
	void insert_at_position (int pos, int data) {
		if (pos > cntNode() || pos < 0) {
			cerr << "> Invalid Value Of Index/Position ???" << endl;
			return;
		}
		else if (pos == 0) {
			insert_at_beginning(data);
		} else {
			int cnt = 1;
			Node* Newnode = new Node(data);
			Node* nextnode = head;

			while (nextnode != NULL && ++cnt != pos - 1) {
				nextnode = nextnode->next;
			}

			Newnode->next = nextnode->next;
			nextnode->next = Newnode;
		}
		cout << "> Node is inserted at " << pos << "..."<< endl; 
	}


};

int main () {

	Linked_List L1(34);
	L1.insert_at_beginning(-12);
	L1.insert_at_beginning(9);
	L1.insert_at_beginning(0);

	L1.insert_at_end(5);
	L1.insert_at_end(100);
	L1.insert_at_end(23);

	L1.insert_at_position(3, 20);
	L1.insert_at_position(0, 22);
	L1.insert_at_position(L1.cntNode(), 07);

	cout << "> Number Of Nodes : " << L1.cntNode() << endl;

	L1.display();

	return 0;
}