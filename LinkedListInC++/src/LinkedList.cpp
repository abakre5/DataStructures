//============================================================================
// Name        : LinkedList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "LinkedList.h"

int main() {
	LinkedList l;
	l.createlist();
	l.printList();
	l.detectLoop();
	l.printReverseList(l.getHead());
	l.reverseList();
	l.printList();
	l.printMiddle();
	l.getNthNode(generateRandom());
	l.deleteFromLinkedList(generateRandom());
	return 0;
}
