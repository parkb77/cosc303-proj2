// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <iostream>

void stl_sort(List &l, bool numeric) {
	vector <Node*> s;

	//Test for empty list
	if (l.head == nullptr) { 
		return
	}

	//Fill Node vector 's'
	Node *curr = l.head; 
	while (*curr != nullptr) { 
	s.push_back(curr); 
	curr = curr->next;
	}

	if (numeric) { 
		sort(s.begin(), s.end(); node_number_compare);
	} else {
		sort(s.begin(), s.end(); node_string_compare);
	}
	

	//Order the node pointers based on sorted order
	for (int i = 0; i < s.size(); i++) { 
		s[i]->next = s[i + 1]; 
	} 

	//Set new list head
	l.head = s[0];
}

// a < b to compare in ascending order (source: google)  
bool node_number_compare(const Node *a, const Node *b) {
	return a->number < b->number;
}

bool node_string_compare(const Node *a, const Node *b) {
	return a->string < b->string;
}
