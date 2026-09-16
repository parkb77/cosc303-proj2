// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <array>
#include <iostream>


int compareStringP(const void * a, const void * b){
	const Node * ia = *(const Node **) a;
        const Node * ib = *(const Node **) b;

	return ia->string.compare(ib->string);
}

int compareIntP(const void * a, const void * b){
	const Node * ia = *(const Node **) a;
	const Node * ib = *(const Node **) b;

	if (ia->number < ib->number) return -1;  // sorts in ascending order
        if (ia->number > ib->number) return 1;
        return 0;
}


void qsort_sort(List &l, bool numeric) {
	if (l.head == nullptr) return; 

	Node* current = l.head;
	const Node** arr = new const Node*[l.size];
	int index = 0;
	
	while (current != nullptr){
                arr[index].number = current;
		index++;
        	current=current->next;
        }

	if (numeric){
		qsort(arr, l.size, sizeof(int), compareIntP);
	} else {
		qsort(arr, l.size, sizeof(string), compareStringP);
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

	for (size_t i = 0; i < l.size -1; i++){
		arr[i]->next = arr[i+1];
	}

	arr[l.size-1]->next = nullptr;

	delete[] arr;
}

