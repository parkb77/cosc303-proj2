// quick.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
	// call recursive function, setting list head to newly sorted list head.
	l.head = qsort(l.head, numeric);
	
}

Node *qsort(Node *head, bool numeric) {
	// check if one or two node list (base case)
	if (head == nullptr || head->next == nullptr){
		return head;
	}
	
	// choose pivot and set L / R
	Node* pivot = head;
	Node* left = nullptr;
	Node* right = nullptr;
	
	// partition around pivot
	partition(head->next, pivot, left, right, numeric);
	
	// perform left and right recursion
	left = qsort(left, numeric);
	right = qsort(right, numeric);
	

	// unlink pivot so it can be concatenated where its supposed to be
	pivot->next = nullptr;
	left = concatenate(left, pivot);
	return concatenate(left, right);
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
	// Start from head and move forward placing nodes compared to pivot in L / R lists
	
			
	// track tail of new lists for easy appending
	Node* left_tail =nullptr;
	Node* right_tail = nullptr;
	// handle both numeric and string cases
	if (numeric){
		//loop through list using next pointer while underlying nodes might be changed
		while (head != nullptr){
			Node* next=head->next;
			if (head->number < pivot->number){
				// add node to left temp list
				if(left == nullptr){ 		// start new list case
					left = head;
					left_tail = head;
				} else {			// list already populated
					left_tail->next = head;
					left_tail = head;
				}
			} else {
				//add nnode to right
				if (right == nullptr){
					right = head;
					right_tail = head;
				} else {
					right_tail->next = head;
					right_tail = head;
				}
			}
			// move head 
			head = next;
			// update tail pointers 
			if (left_tail != nullptr){
				left_tail->next = nullptr;
			}
			if (right_tail != nullptr){
				right_tail->next = nullptr;
			}
			
		}
	  // handle string comparison (!numeric)	
	} else {
		while (head != nullptr){
			Node* next = head->next;
			if (head->string.compare(pivot->string) < 0){ //string compare returns < 0 when string a comes before string b
				// add left
				if(left == nullptr){ 		// start case
                                        left = head;
                                        left_tail = head;
                                } else {			// temp list already populated
                                        left_tail->next = head;
                                        left_tail = head;
                                }
			} else {
				// add to right
				if (right == nullptr){
                                        right = head;
                                        right_tail = head;
                                } else {
                                        right_tail->next = head;
                                        right_tail = head;
                                }
			}
			head = next;

			if (left_tail != nullptr){
                                left_tail->next = nullptr;
                        }
                        if (right_tail != nullptr){
                                right_tail->next = nullptr;
                        }
		}
	}
}

Node *concatenate(Node *left, Node *right) {
	// find end of left and point tail->next to head of right
	//return new head
	
	// need to handle case where left is empty
	if (left == nullptr){
		return right;
	}
	
	Node* tail = left;
	while (tail->next != nullptr){
		tail = tail->next;
	}

	tail->next = right;

	return left;
}

