//merge.cpp

#include "volsort.h"

#include <iostream>

using namespace std;

// Prototypes

Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

void merge_sort(List &l, bool numeric) {

	//List already sorted or empty
	if (l.head == nullptr || l.head->next == nullptr) { 
		return;
	}

	//Set list equal to sorted list
	l.head = msort(l.head, numeric); 
}


Node *msort(Node *head, bool numeric) {
	if (head == nullptr || head->next == nullptr) { 
		return head;
	}
	Node *left = nullptr;
	Node *right = nullptr;

	//Split list into two halves
	split(head,left,right);

	//sort both halves
	left = msort(left, numeric);
	right = msort(right, numeric); 

	//merge sorted halves
	return merge(left, right, numeric); 

}

void split(Node *head, Node *&left, Node *&right) {

	if (head == nullptr || head->next == nullptr) { 
		left = head;
		right = nullptr;
		return;
	}
	
	Node *slow = head;
	Node *fast = head->next;

	//Find and initialize pivot
	while (fast !=nullptr && fast->next != nullptr) { 
		slow = slow->next;
		fast = fast->next->next;
	}

	left = head;
	right = slow->next;
	slow->next = nullptr;

}

//TA slides from lab, TA video, and "Learn Merge Sort in 13 minutes" from Bro Code on youtube. All sources specifically used for the merge function
Node *merge(Node *left, Node *right, bool numeric) {

	Node* temp = nullptr;
	Node* start = nullptr;

	bool compare;

	//Set the head 
	if (numeric) { 
		compare = node_number_compare(left, right);
	} else { 
		compare = node_string_compare(left,right);
	}

	if (compare) { 
		start = left;
		left = left->next;
	} else { 
		start = right;
		right = right->next;
	}

	//Make the temp iterator start at the head
	temp = start; 


	while (left != nullptr && right != nullptr) { 
	 

	// If compare true, right value greater than left, logic from STL used
	if (numeric) { 
		compare = node_number_compare(left, right);
		} else {
		compare = node_string_compare(left, right);
		}

		//Value from lesser half gets attached, list with greater value gets iterated
		if (compare) {
			temp->next = left; 
			left = left->next;
		} else { 
			temp->next = right;
			right = right->next;
		}

		temp = temp->next; 
	}

	//Attach remaining nodes 
	if (left != nullptr) { 
		temp->next = left;
	} else { 
		temp->next = right;
	} 

	
	
return start; 	
	
}

