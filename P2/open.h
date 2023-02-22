#pragma once
#include <iostream>

class Page {
public:
	int page_start = 0;
	int page_status = 0;
	int x_val = 0;

};


class Processor {
public:
	int startaddr{};
	int PID = 0;
	//Processor* next = nullptr;

};

class Open {
public:
	//constructor
	Open(unsigned int N, unsigned int P);
	//destructor
	~Open();

	//Member functions
	bool insert(int PID);
	int search(int PID);
	bool write(int PID, int x, int ADDR);
	bool read(int PID, int ADDR);
	bool delet(int PID);

private:
	int table_size;
	int page_size;
	int memory_size;
	int page_num = 0;
	//Page* page;
	Page* memory;
	Processor* hashTable;
	//bool find(int PID, int h1, int h2, int h12, int k);
};