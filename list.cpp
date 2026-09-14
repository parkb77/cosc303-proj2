#include "volsort.h"


List::List() {


}

List::~List() {

}

void List::push_front(const std::string &s) {
 
}

// Push a value to the front of the list
void List::push_front(const std::string &s) {
    Node *new_node = newNode(s);
    new_node->next = head;
    head = new_node;
}
