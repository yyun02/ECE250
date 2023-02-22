#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Page2 {
public:
	int page_start = 0;
	int page_status = 0;
	int x_val = 0;

};


class Processor2 {
public:
	int startaddr{};
	int PID = 0;


	//Processor(int n);
//private:
//	vector<int> chain;
//	int n;

//private:
//	vector<int> chain;
//	//processor* next = nullptr;

};

class Ordered {
public:
	//constructor
	Ordered(unsigned int N, unsigned int P);
	//destructor
	~Ordered();
	int search_chain(int PID);

	//Member functions
	bool insert(int PID);
	int search(int PID);
	bool write(int PID, int x, int ADDR);
	bool read(int PID, int ADDR);
	bool delet(int PID);
	void print(int m);

private:
	int table_size;
	int page_size;
	int memory_size;
	int page_num = 0;
	Page2* memory;
	vector <Processor2>* hashTable;
};