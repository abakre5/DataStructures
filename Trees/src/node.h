/*
 * node.h
 *
 *  Created on: 27-Jul-2017
 *      Author: Abhishek
 */

#ifndef NODE_H_
#define NODE_H_

#include <bits/stdc++.h>
#define breakLine cout << endl;
using namespace std;

class node{
	int data;
	node *lchild;
	node *rchild;
public:
	node *setData(int data);
	void setLchild(node *temp);
	void setRchild(node *temp);
	int getData();
	node* getLchild();
	node* getRchild();
};

node *node::setData(int data){
	this->data = data;
	this->lchild = NULL;
	this->rchild = NULL;
	return this;
}

void node::setLchild(node *temp){
	this->lchild = temp;
}

void node::setRchild(node *temp){
	this->rchild = temp;
}

int node::getData(){
	return this->data;
}

node* node::getLchild(){
	return this->lchild;
}

node* node::getRchild(){
	return this->rchild;
}
int generateRandom(){
	return (rand() % 10001);
}

#endif /* NODE_H_ */
