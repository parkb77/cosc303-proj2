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

// Push a value to the front of the list
void List::push_front(const std::string &s) {
    Node *new_node = new Node;
	new_node->string = s;
	
	try { 
		new_node->number = std::stoi(s);
	} catch { 
		new_node->number = 0;
	}
    new_node->next = head;
    head = new_node;
	size++;
}
