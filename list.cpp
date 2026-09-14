#include "volsort.h"


List::List() {
size = 0; 
head = nullptr; 

}

List::~List() {
 Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
	delete current;
        current = next;
    }
    head = nullptr;

}

Node * List::newNode(const int &data) {
    return new Node(data);
}

// Push a value to the front of the list
void List::push_front(const std::string &s) {
    Node *new_node = newNode(s);
    new_node->next = head;
    head = new_node;
}
