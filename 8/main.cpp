#include <iostream>
#include <vector>
#include <stdarg.h>
#include "error.h"

using namespace std;

class Queue {
public:
	vector<int> q;
	Queue() {}
	Queue(vector<int> q) {
		this->q = q;
	}
	Queue(unsigned n, ...) {
		va_list args;
		va_start(args, n);
		for (int i = 0; i < n; ++ i)
			q.push_back(va_arg(args, int));
		va_end(args);
	}
	~Queue() {}

	void add(int n) {
		q.push_back(n);
	}
	int operator[](unsigned index) {
		if (index >= q.size()) throw error("Index out of range!");
		return q[index];
	}
	int operator()() {
		return q.size();
	}
	void operator()(unsigned size, int value = 0) {
		q.resize(size, value);
	}
	void operator+(int n) {
		if (q.size() == 0) throw error("Empty queue!");
		for (int i = 0; i < q.size(); ++ i)
			q[i] += n;
	}
	void operator-(int n) {
		if (n > q.size()) throw error("N is larger than the queue size!");
		q.erase(q.begin(), q.begin() + n);
	}
	void print() {
		for (int i = 0; i < q.size(); ++ i)
			cout << q[i] << " ";
		cout << endl;
	}
};

int main(void) {
	Queue q(4, 1, 2, 3, 4);
	q.print();
	q.add(5);
	q.print();
	q + 3;
	q.print();
	//cout << "size: " << q() << endl;
	q - 3;
	q.print();
	q(10, 10);
	q.print();
	try {
		q - 100;
	}
	catch (error & e) {
		e.what();
	}
	return 0;
}