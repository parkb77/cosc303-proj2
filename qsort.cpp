// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <array>
#include <iostream>


int compareStringP(const void * a, const void * b){
	return strcmp(*(const char **) a, *(const char **) b);
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
                arr[index].number = current->number;
                arr[index].string = current->string;
		index++;
        	current=current->next;
        }

	if (numeric){
		qsort(arr, l.size, sizeof(int), compareintP);
	} else {
		qsort(arr, l.size, sizeof(string), compareStringP);
	}
	
	current = l.head;
        index=0;
        while (current != nullptr){
                current->string = arr[index].string;
                current->number = arr[index].number;
		index++;
                current = current->next;
        }
	delete[] arr;
}

