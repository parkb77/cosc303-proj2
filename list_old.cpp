#include "list.h"
#include <iostream>
#include <utility>
// Node constructor
Node::Node(const int &data) : data(data), next(nullptr) {}

// Node getter methods
int Node::getData() const {
    return data;
}

Node * Node::getNext() const {
    return next;
}

// List constructor
List::List() : head(nullptr) {}

// List destructor - must delete all nodes
List::~List() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
	//std::cout << "This is debug: " << current->data << std::endl;
	delete current;
        current = next;
    }
    head = nullptr;
}

// copy
List::List(const List& other) : head(nullptr) {
	if (!other.head) return;

	head = new Node(other.head->data);
	Node* dst = head;
	Node* src = other.head->next;

	while (src){
		dst->next = new Node(src->data);
		dst = dst->next;
		src = src->next;
	}
}


List& List::operator=(const List& other) {
	if (this == &other) return *this;

	List temp(other);
	std::swap(head, temp.head);
	return *this;
}


// Create a new node
Node * List::newNode(const int &data) {
    return new Node(data);
}

// Push a value to the front of the list
void List::push_front(const int &data) {
    Node *new_node = newNode(data);
    new_node->next = head;
    head = new_node;
}

// Check if list is empty
bool List::empty() const {
    return head == nullptr;
}

// Get the number of nodes in the list
int List::nodeCount() const {
    int count = 0;
    Node *current = head;
    while (current != nullptr) {
        count++;
        current = current->getNext();
    }
    return count;
}

// Get the head of the list
Node * List::getHead() const {
    return head;
}
