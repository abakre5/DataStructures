/*
 * LinkedList.h
 *
 *  Created on: 26-Jul-2017
 *      Author: Abhishek
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "node.h"

class LinkedList{
	node *head;
public:
	LinkedList();
	node *getHead();
	node* getNode(int data);
	void createlist(void);
	void printList(void);
	void detectLoop(void);
	void printReverseList(node *temp);
	void reverseList();
	void printMiddle();
	void deleteFromLinkedList(int key);
	void getNthNode(int n);
};

LinkedList::LinkedList(void){
	head = NULL;
}

node *LinkedList::getHead(){
	return head;
}

node *LinkedList::getNode(int data){
	node *n = new node;
	return n->setData(data);
}

void LinkedList::createlist(){
	srand(time(NULL));
	head = getNode(generateRandom());
	node *temp = head;
	int len = generateRandom();
	for(int i = 0;i < len;i++){
		temp->setNext(getNode(generateRandom()));
		temp = temp->getNext();
	}
}

void LinkedList::printList(){
	node *temp = head;
	while(temp){
		cout << temp->getData() << " ";
		temp = temp->getNext();
	}
	cout << endl;
}

void LinkedList::detectLoop(){
	node *slowPtr = head;
	node *fastPtr = head;
	bool flag = false;
	while(slowPtr && fastPtr && fastPtr->getNext()){
		slowPtr = slowPtr->getNext();
		fastPtr = fastPtr->getNext()->getNext();
		if(slowPtr == fastPtr)	{
			flag = true;
			break;
		}
	}
	if(flag == true)	cout << "Loop Detected" << endl;
	else	cout << "NO Loop Detected" << endl;
}

void LinkedList::printReverseList(node *temp){
	if(temp){
		printReverseList(temp->getNext());
		cout << temp->getData() << " ";
	}
}

void LinkedList::reverseList(){
	cout << endl;
	node *prev = NULL;
	node *curr = head;
	node *next = NULL;
	while(curr){
		next = curr->getNext();
		curr->setNext(prev);
		prev = curr;
		curr = next;
	}
	head = prev;
}

void LinkedList::printMiddle(){
	node *slowPtr = head;
	node *fastPtr = head;
	while(slowPtr && fastPtr && fastPtr->getNext()){
		slowPtr = slowPtr->getNext();
		fastPtr = fastPtr->getNext()->getNext();
	}
	cout << slowPtr->getData() << endl;
}

void LinkedList::getNthNode(int n){
	int count = 1;
	node *temp = head;
	while(temp){
		if(count++ == n){
			cout << n << "'th Element :: " << temp->getData() << endl;
			break;
		}
		temp = temp->getNext();
	}
}

void LinkedList::deleteFromLinkedList(int data){
	node *temp = head->getNext();
	node *prev = head;
	if(temp->getData() == data){
		node *toBeDelete = head;
		head = head->getNext();
		delete toBeDelete;
		cout << "Data is Found and Deleted" << endl;
		return;
	}
	else{
		while(temp){
			if(temp->getData() == data){
				node *toBeDelete = temp;
				prev->setNext(temp->getNext());
				delete toBeDelete;
				cout << "Data is Found and Deleted" << endl;
				return;
			}
			prev = prev->getNext();
			temp = temp->getNext();
		}
	}
	cout << "Data Not Found" << endl;
}

#endif /* LINKEDLIST_H_ */
