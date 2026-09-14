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
	array<int,l.size> numbers;



}

