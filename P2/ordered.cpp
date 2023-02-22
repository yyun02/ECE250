#include <iostream>
#include "ordered.h"
#include <vector>
using namespace std;

//3:24

Ordered::Ordered(unsigned int N, unsigned int P) {
	page_size = P;
	memory_size = N;
	table_size = N/P;
	hashTable = new vector<Processor2>[table_size];
	//= number of processors = same as number of page
	memory = new Page2[memory_size];
	page_num = 0;
	//vector <Processor> table_array[table_size];
	
	//.front, .back, .size, .capacity 
	//v1.pusk_back(x) - add at the back
	//v1.pop_back();
	//delete capacity - v1.shrink_to_fit()
	//v1.insert(v1.begin() "+1" , x) - insert at front
	//v1.erase(v1.begin())

}


Ordered::~Ordered() {
	for (int i = 0; i < table_size; i++) {
		hashTable[i].clear();
	}
	delete[] hashTable;
	delete[] memory;
	//vector

}


bool Ordered::insert(int PID) {

	int h1 = PID % table_size;
	int newStartAddr{};

	// If table is full || Process with PID already exists -> return false;
	if (search(PID) != -1) { //PID already exists
		return false;
	}
	if (page_num == table_size) {
		return false;
	}
	// Assign the startAddr to newPRocessor
	for (int j = 0; j < memory_size; j += page_size) {
		if (memory[j].page_status == 0) {
			newStartAddr = j;
			memory[j].page_status = 1;
		}
	}
	Processor2* new_pro = new Processor2();
	new_pro->PID = PID;
	new_pro->startaddr = newStartAddr;
	page_num++;

	// If table[index].size() == 0, begin() + 0
	if (hashTable[h1].size() == 0) {
		hashTable[h1].insert(hashTable[h1].begin(), *new_pro);
		delete new_pro;
		new_pro = nullptr;
		return true;
	}


	// WHIle looping table[index], if table[i].at(i).pid < PID, insert the new process to i
	for (int k = 0; k == 0 || k < hashTable[h1].size(); k++) {
		if (hashTable[h1].at(k).PID < PID) {
			hashTable[h1].insert(hashTable[h1].begin() + k, *new_pro);
			delete new_pro;
			new_pro = nullptr;
			return true;
		}
	}

	// Insert at the end of table[index] (table[index].size())
	hashTable[h1].insert(hashTable[h1].begin() + hashTable[h1].size(), *new_pro);


	delete new_pro;
	new_pro = nullptr;
		
	return true;
}

int Ordered::search(int PID) {
	int h1 = PID % table_size;
	for(int i = 0 ;i < hashTable[h1].size(); i++){
			if (hashTable[h1].at(i).PID == PID) {
				return h1;
		}
	}
	return -1;
}

bool Ordered::write(int PID, int ADDR, int x) {
	for (int k = 0; k < hashTable[search(PID)].size(); k++) {
		if (search(PID) == -1) {//exists in memory
			cout << "not found" << endl;
			return false;
		}
		else if (hashTable[search(PID)].at(k).PID == PID) {
			if (ADDR < 0 || ADDR >= page_size) {
				//cout << "page" << endl;
				return false;
			}
			//cout << "ELSE" << endl;
			memory[hashTable[search(PID)].at(k).startaddr + ADDR].x_val = x;
			return true;

		}
	}
	//cout << "fail" << endl;
	return false;
}

bool Ordered::read(int PID, int ADDR) {
	if (search(PID) == -1) {
		cout << "failure" << endl;
		return false;
	}
	for (int k = 0; k < hashTable[search(PID)].size(); k++) {
		if (hashTable[search(PID)].at(k).PID == PID) {
			if (ADDR < 0 || ADDR >= page_size) {
				cout << "failure" << endl;
				return false;
			}
			else {
				cout << ADDR << " " << memory[hashTable[search(PID)].at(k).startaddr + ADDR].x_val << endl;
				return true;
			}
		}
	}
	return false;
}
int Ordered::search_chain(int PID) {
	int h1 = PID % table_size;
	for (int i = 0; i < hashTable[h1].size(); i++) {
		if (hashTable[h1].at(i).PID == PID) {
			return i;
		}
	}
	return -1;
}
bool Ordered::delet(int PID) {
	int h1 = PID % table_size;
	if (search(PID) == -1) {
		return false;
	}
	hashTable[h1].erase(hashTable[h1].begin() + search_chain(PID));
	memory[h1*page_size].page_status = 0;
	page_num--;
	return true;
}

void Ordered::print(int m) {
	
	if (hashTable[m].size() == 0) {
		cout << "chain is empty" << endl;
		return;
	}
	for (int i = 0; i < hashTable[m].size(); i++) {
		cout << hashTable[m].at(i).PID << " ";
	}

	cout << endl;
}