#include <iostream>
using namespace std;
/*#ifndef calculator.h
#define calculator.h*/

class Node {

public:
	string name;
	double val{};
	Node* next = nullptr;

};

class LinkedList {

public:
	//constructor
	LinkedList(int capacity);

	//destructor
	~LinkedList();

	//Member functions //
	bool def(string name, double val);
	bool add(string x, string y, string z);
	bool sub(string x, string y, string z);
	bool rem(string x);
	void prt(string x);


private:
	int capacity;
	int length;
	Node* head;
	Node* getNode(string name);
	double getVal(string name);


};
