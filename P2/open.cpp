#include <iostream>
#include "open.h"
//#include <vector>
using namespace std;

Open::Open(unsigned int N, unsigned int P) {
	page_size = P;
	memory_size = N;
	table_size = N / P; //= number of processors = same as number of page
	hashTable = new Processor[table_size]; //table_size size hashtable created
	//page = new Page[table_size]; //# of page*P = N (memory)
	memory = new Page[memory_size];
	page_num = 0;
}
Open::~Open(){
	delete[] hashTable;
	delete[] memory;
}

bool Open::insert(int PID) {

	int h1 = PID % table_size;
	int h2 = (PID / table_size) % table_size;
	if (h2 % 2 == 0) {
		h2++;
	}
	int k = 0;
	int h12 = h1;
	int newStartAddr{};
	if (search(PID)!=-1) { //PID already exists
			return false;
		}
	if (page_num == table_size) {
		return false;
	}

	//Find newStartAddr

	for (int j = 0; j < memory_size; j += page_size) {
		if (memory[j].page_status == 0) {
			newStartAddr = j;
			memory[j].page_status = 1;
		}
	}

	//h1 = empty
	if (hashTable[h1].PID == 0) {
		hashTable[h1].PID = PID;
		hashTable[h1].startaddr = newStartAddr;
		page_num++;
		return true;

	}

	//h1 = not empty
	else {
		while (hashTable[h12].PID != 0) {
			h12 = (h12 + h2) % table_size;
			if (h12 == h1) {
				return false;
			}
		}
		hashTable[h12].PID = PID;
		hashTable[h12].startaddr = newStartAddr;
		page_num++;
		return true;
		
	}//if full

	return false;
}

int Open::search(int PID) {
	////cout << "hash table has:" << endl;
	/*for (int i{ 0 }; i < table_size; i++) {
		if (hashTable[i].PID == PID) {
			return i;
		}
	}*/
	//	cout << "\tidx " << i << " has PID: " << hashTable[i].PID << endl;
	int start= PID % table_size;
	int h2 = (PID / table_size) % table_size;
	int i = 1;
	int h12;

	if (h2 % 2 == 0) {
		h2 += 1;
	}

	if (hashTable[start].PID == PID) {
		return start;
	}
	while (i == 1 || h12 != start%table_size) {
		h12 = (start + i * h2) % table_size;
		if (hashTable[h12].PID == PID) {
			return h12;
		}
		i++;
	}

	//for (int i{ 0 }; i < table_size; i++) {
		//if (hashTable[(h12 = (h12 + h2*i)) % table_size].PID == PID) {
			//return h12;
		//}
	//}

	return -1;
}

bool Open::write(int PID, int ADDR, int x) {
	//virtual memory addr + processor's startaddr = physical memory addr?
	//x is given
	//hashtable's startaddr = start of its page
	// assign x to the page
//	hashTable[search(PID)].startaddr; //= start of the page;
	//memory_size / P = page_size;

	if (search(PID) == -1) {
		return false;
	}
	else if (ADDR < 0 || ADDR >= page_size) {
		return false;
	}
	else {
		memory[hashTable[search(PID)].startaddr + ADDR].x_val = x;

		return true;
	}

	return false;
}

bool Open::read(int PID, int ADDR) {

	if (search(PID) == -1) {
		cout << "failure" << endl;
		return false;
	}
	else if (ADDR < 0 || (/*hashTable[search(PID)].startaddr + */ADDR) >= (/*hashTable[search(PID)].startaddr + */page_size)) {
		cout << "failure" << endl;
		return false;
	}
	else {
		cout << ADDR<< " " << memory[hashTable[search(PID)].startaddr + ADDR].x_val << endl;
		return true;
	}
	cout << "failure" << endl;
	return false;
}

bool Open::delet(int PID) {
	if (search(PID) == -1) {
		return false;
	}
	else {

		memory[search(PID)*page_size].page_status = 0;
		hashTable[search(PID)].PID = 0;
		page_num--;

		return true;
	}
	return false;
}
