#include <iostream>
#include <vector>
#include <forward_list>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

void show_vector(vector<int> vec) {
	for (int i = 0; i < vec.size(); ++ i)
		cout << vec[i] << " ";
	cout << endl;
}
void show_list(forward_list<int> l) {
	for (auto i = l.begin(); i != l.end(); ++ i)
		cout << *i << " ";
	cout << endl;
}

int main(void) {
	srand(time(NULL));
	//1
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; ++ i)
		cin >> vec[i];

	show_vector(vec);
	for (int i = 1; i < vec.size() - 1; ++ i) {
		if (vec[i] == vec[i - 1] + vec[i + 1])
			vec[i] = vec[i - 1] * vec[i + 1];
	}
	show_vector(vec);
	int mx = *max_element(vec.begin(), vec.end());
	for (int i = 1; i < vec.size() - 1; ++ i) {
		if (vec[i] == vec[i - 1] * vec[i + 1])
			cout << (mx - vec[i - 1]) << " " << (mx - vec[i + 1]) << endl;
	}


	//2

	forward_list<int> l, l1, l2;
	cin >> n;
	for (int i = 0; i < n; ++ i) {
		l.push_front(rand() % 100 - 50);
	}
	show_list(l);
	for (auto i = l.begin(); i != l.end(); ++ i) {
		if (*i > 0)
			l1.push_front(*i);
		else if (*i < 0)
			l2.push_front(*i);
	}
	show_list(l1);
	show_list(l2);
	return 0;
}

//2 5 3 1 2 3 7 4