#include <iostream>

using namespace std;

class Time {
private:
	int h, m, s;
public:
	Time() {
		h = 0;
		m = 0;
		s = 0;
	}
	Time(int h, int m, int s) {
		this->h = (h + (m + s / 60) / 60) % 12;
		this->m = (m + s / 60) % 60;
		this->s = s % 60;
	}
	int geth() {
		return h;
	}
	int getm() {
		return m;
	}
	int gets() {
		return s;
	}
	void print() {
		printf("%02d:%02d:%02d\n", h, m, s);
	}
	Time operator+(Time T) {
		return Time(h + T.geth(), m + T.getm(), s + T.gets());
	}
	~Time() {}
};

int main(void) {
	Time t(2, 520, 10000), a(2, 30, 12);
	t.print();
	a.print();
	(t + a).print();
	return 0;
}