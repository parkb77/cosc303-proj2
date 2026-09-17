// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <array>
#include <iostream>


int compareStringP(const void * a, const void * b){	// referenced string compare from notes
	const Node * ia = *(const Node **) a;
        const Node * ib = *(const Node **) b;

	return ia->string.compare(ib->string);
}

int compareIntP(const void * a, const void * b){ // referenced int compare from notes
	const Node * ia = *(const Node **) a;
	const Node * ib = *(const Node **) b;

	if (ia->number < ib->number) return -1;  // sorts in ascending order
        if (ia->number > ib->number) return 1;
        return 0;
}


void qsort_sort(List &l, bool numeric) {
	if (l.head == nullptr) return; 
	// init current holding vars and array
	Node* current = l.head;
	Node** arr = new Node*[l.size];
	int index = 0;

	// write node pointers to arr
	while (current != nullptr){
                arr[index] = current;
		index++;
        	current=current->next;
        }
	// run qsort 
	if (numeric){
		qsort(arr, l.size, sizeof(Node*), compareIntP);
	} else {
		qsort(arr, l.size, sizeof(Node*), compareStringP);
	}
	
	// Update the linked list with arr stuff
	/*current = l.head;
        index=0;
        while (current != nullptr){
                current->string = arr[index]->string;
                current->number = arr[index]->number;
		index++;
                current = current->next;
        }
	*/
	// Scrapped this because it modified Nodes via pointer 
	// Found better way to just reconnect list using the array
	//
	
	// set new head
	l.head = arr[0];
	// order underlying linked list
	for (size_t i = 0; i < l.size -1; i++){
		arr[i]->next = arr[i+1];
	}
	// set end to null
	arr[l.size-1]->next = nullptr;

	delete[] arr;
}

