#include <iostream>
#include "calculator.h"
using namespace std;


//constructor
LinkedList::LinkedList(int n_capacity) {
	head = new Node(); 
	capacity = n_capacity;
	length = 0;
}

//destructor - ECE 150: Linked lists with dynamic memory allocation
LinkedList::~LinkedList() {
	while (head != nullptr) {
		Node* curr = head;
		head = head->next;
		delete curr;
		curr = nullptr;
		length--;
	}
}

Node* LinkedList::getNode(string name) {
	Node* curr = head;
	while (curr->next != nullptr) {
		curr = curr->next;
		if (curr->name==name) {
			Node* node_got = curr;
			return node_got;
		}
	}
	return nullptr;
//loop until x found, curr= head and curr->next, nullptr if no 
}

bool LinkedList::def(string name, double val) {

	if (getNode(name) != nullptr || length == capacity) {//x already exists - false
		return false;
	}
	else {
		Node* new_node = new Node(); //class Node, new_node = name for new Node() - make it at the end of linkedlist
			//next until next is not null and put new_node
			//next should be changed from nullptr to new_node, and new node's next is nullptr 
			Node* curr = head;
		while (curr-> next != nullptr) {
			curr = curr->next;
		}

		curr->next = new_node;
			//val and name and next in new_Node
		new_node->val = val;
		new_node->name = name;
		new_node->next = nullptr;
		length++;

		return true;
	}

}

double LinkedList::getVal(string name) {
	Node* ptr_result = getNode(name);
	Node* curr = head;
	while (curr != ptr_result) {
		curr = curr -> next;
	}
		//head to ptr_result and curr = ptr-result, curr -> val, val of node*curr
	double result_val = curr->val;
	return result_val;
}


bool LinkedList::add(string x, string y, string z) {
	if (getNode(x) == nullptr || getNode(y) == nullptr || getNode(z) == nullptr) {
		return false;
	}
	else {
		//get node so return Node *, and get val in the pointer
		double xplusy = getVal(x) + getVal(y);
		Node* z_ptr = getNode(z);//z's val to xy
		Node* curr = head;
		while (curr != z_ptr) {
			curr = curr->next;
		}
		curr = z_ptr;
		curr->val = xplusy;
		return true;
	}
}

bool LinkedList::sub(string x, string y, string z){
	if (getNode(x) == nullptr || getNode(y) == nullptr || getNode(z) == nullptr) {
		return false;
	}
	else {
		double x_y = getVal(x) - getVal(y);
		Node* z_ptr = getNode(z);
		Node* curr = head;
		while (curr != z_ptr) {
			curr = curr->next;
		}
		curr->val = x_y;
		return true;
	}
}
bool LinkedList::rem(string x) {
	//curr-> next : delete, and curr-> next = curr ->next -> next
	//Node* rem_node = getNode(x);
	if (getNode(x) == nullptr) {
		return false;
	}
	else {
		Node* curr = head;
		while (curr->next != getNode(x)) {
			curr = curr->next;
		}
		Node* temp = curr->next;
		curr->next = curr->next->next;
		delete temp;
		temp = nullptr;
		length--;
		return true;
	}
}
void LinkedList::prt(string x) {
	if (getNode(x) != nullptr) {
		std::cout<< getVal(x) <<std::endl;
}
	else {
		std::cout << "variable " << x << " not found" << std::endl;
	}
	return;
}