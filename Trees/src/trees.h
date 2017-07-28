/*
 * trees.h
 *
 *  Created on: 27-Jul-2017
 *      Author: Abhishek
 */

#ifndef TREES_H_
#define TREES_H_

#include "node.h"

class Trees{
	node *root;
public:
	Trees();
	node *getRoot(void);
	node *insertInTree(node *temp, int data);
	node *getNode(int data);
	void createTree(void);
	void inOrder(node *temp);
	void preOrder(node *temp);
	void postOrder(node *temp);
	int heightOfTree(node *temp);
	int sizeOfTree(node *temp);
	bool isBst(node *temp, int min, int max);
	node *minValue(node *root);
	node *deleteFromTree(node *temp, int data);
	node *lca(node *temp, int no1, int no2);
	void findPreSuc(node* temp, node*& pre, node*& suc, int data);
};

Trees::Trees(){
	root = NULL;
}

node *Trees::getRoot(void){
	return root;
}

node *Trees::insertInTree(node *temp, int data){
	if(temp == NULL)	return getNode(data);
	if(temp->getData() > data)
		temp->setLchild(insertInTree(temp->getLchild(), data));
	else if(temp->getData() < data)
		temp->setRchild(insertInTree(temp->getRchild(), data));
	return temp;
}

node *Trees::getNode(int data){
	node *temp = new node;
	temp->setData(data);
	return temp;
}

void Trees::createTree(void){
	srand(time(NULL));
	root = getNode(generateRandom());
	int noOfElements = generateRandom() - 1;
	for(int i = 0;i < noOfElements;i++){
		insertInTree(root, generateRandom());
	}
}

void Trees::inOrder(node *temp){
	if(temp){
		inOrder(temp->getLchild());
		cout << temp->getData() << " ";
		inOrder(temp->getRchild());
	}
}

void Trees::preOrder(node *temp){
	if(temp){
		cout << temp->getData() << " ";
		preOrder(temp->getLchild());
		preOrder(temp->getRchild());
	}
}

void Trees::postOrder(node *temp){
	if(temp){
		postOrder(temp->getLchild());
		postOrder(temp->getRchild());
		cout << temp->getData() << " ";
	}
}

int Trees::heightOfTree(node *temp){
	int lHeight = 0, rHeight = 0;
	if(temp->getLchild())	lHeight = 1 + heightOfTree(temp->getLchild());
	if(temp->getRchild())	rHeight = 1 + heightOfTree(temp->getRchild());
	return lHeight > rHeight ? lHeight : rHeight;
}

int Trees::sizeOfTree(node *temp){
	if(temp == NULL)	return 0;
	return (sizeOfTree(temp->getLchild()) + 1 + sizeOfTree(temp->getRchild()));
}

bool Trees::isBst(node *temp, int min, int max){
	if(temp == NULL)	return true;
	if(temp->getData() < min || temp->getData() > max)	return true;
	return (isBst(temp->getLchild(), min, temp->getData()) && isBst(temp->getRchild(), temp->getData(), max));
}

node *Trees::minValue(node *temp){
    while(temp->getLchild())
    	temp->setLchild(temp->getLchild());
    return temp;
}


node *Trees::deleteFromTree(node *temp, int data){
	if(temp == NULL)	return temp;
	if(temp->getData() > data)	temp->setLchild(deleteFromTree(temp->getLchild(), data));
	else if(temp->getData() < data)	temp->setRchild(deleteFromTree(temp->getRchild(), data));
	else{
		if(temp->getLchild() == NULL){
			node *toBeReturn = temp->getRchild();
			delete temp;
			return toBeReturn;
		}
		else if(temp->getRchild() == NULL){
			node *toBeReturn = temp->getLchild();
			delete temp;
			return toBeReturn;
		}
		else{
			node *toBeReturn = minValue(temp->getRchild());
			temp->setData(toBeReturn->getData());
			temp->setRchild(deleteFromTree(temp->getRchild(), data));
		}
	}
	return temp;
}

node *Trees::lca(node *temp, int no1, int no2){
	if(temp->getData() > no1 && temp->getData() > no2)	return lca(temp->getLchild(), no1, no2);
	if(temp->getData() < no1 && temp->getData() < no2)	return lca(temp->getRchild(), no1, no2);
	return temp;
}

void Trees::findPreSuc(node* temp, node*& pre, node*& suc, int data){
    if(temp == NULL)    return;
    if(temp->getData() == data){
        if(temp->getLchild()){           //MAX IN LEFT SUBTREE IS PRE
            struct node *lTemp = temp->getLchild();
            while(lTemp->getRchild())
                lTemp = lTemp->getRchild();
            pre = lTemp;
        }
        if(temp->getRchild()){           //MIN IN RIGHT SUBTREE IS PRE
            struct node *lTemp = temp->getRchild();
            while(lTemp->getLchild())
                lTemp = lTemp->getLchild();
            suc = lTemp;
        }
        return;
    }
    else if(data < temp->getData()){
        suc = temp;
        findPreSuc(temp->getLchild(), pre, suc, data);
    }
    else if(data > temp->getData()){
        pre = temp;
        findPreSuc(temp->getRchild(), pre, suc, data);
    }
    return;
}


#endif /* TREES_H_ */
