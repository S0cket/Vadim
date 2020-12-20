#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Vector {
public:
	vector<T> vec;
	Vector() {}
	Vector(vector<T> v) {
		vec = v;
	}
	~Vector() {}

	T& operator[](unsigned index) {
		return vec[index];
	}
	void operator()(unsigned size) {
		vec.resize(size);
	}
	unsigned operator()() {
		return vec.size();
	}
	Vector<T> operator+(Vector<T> V) {
		vector<T> a = vec;
		for (int i = 0; i < min(a.size(), V.vec.size()); ++ i)
			a[i] += V.vec[i];
		return Vector<T>(a);
	}
};

class Time {
private:
	int min, sec;
public:
	Time() {
		min = 0;
		sec = 0;
	}
	Time(int s) {
		min = s / 60;
		sec = s % 60;
	}
	Time(int m, int s) {
		min = m + s / 60;
		sec = s % 60;
	}
	void set(int s) {
		min = s / 60;
		sec = s % 60;	
	}
	void set(int s, int m) {
		min = m + s / 60;
		sec = s % 60;	
	}
	void print() {
		cout << min << ":" << sec << endl;
	}
	~Time() {}
};

void print(Vector<int> V) {
	for (int i = 0; i < V.vec.size(); ++ i)
		cout << V.vec[i] << " ";
	cout << endl;
}

int main(void) {
	vector<int> a(5, 3), b(3, 2);
	Vector<int> A(a), B(b), C = A + B;
	print(A);
	print(B);
	print(C);
	Time t(12, 320);
	t.print();
	return 0;
}