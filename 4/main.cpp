#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (a < b)
		swap(a, b);
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

class Fract {
public:
	int a, b; // a / b
	Fract() {
		a = 0;
		b = 1;
	}
	Fract(int a, int b) {
		this->a = a;
		if (b == 0)
			b = 1;
		this->b = b;
	}

	Fract reduct() {
		int d = gcd(a, b);
		return Fract(a / d, b / d);
	}
	void cut() {
		int d = gcd(a, b);
		a /= d;
		b /= d;
	}
	void print() {
		cout << a << "/" << b << endl;
	}
	Fract operator+(Fract F) {
		int a = this->a * F.b + F.a * this->b;
		int b = this->b * F.b;
		return Fract(a, b);
	}
	Fract operator-(Fract F) {
		int a = this->a * F.b - F.a * this->b;
		int b = this->b * F.b;
		return Fract(a, b);
	}
	Fract operator*(Fract F) {
		int a = this->a * F.a;
		int b = this->b * F.b;
		return Fract(a, b);
	}
	Fract operator/(Fract F) {
		int a = this->a * F.b;
		int b = this->b * F.a;
		return Fract(a, b);
	}

	~Fract() {}
};

int main(void) {
	int a, b, c, d, e, f, g, h, k, l;
	cin >> a >> b >> c >> d >> e >> f >> g >> h >> k >> l;
	Fract A(a, b), B(c, d), C(e, f), D(g, h), E(k, l), Z;
	Z = ((A + B) / C) * (D - E);
	Z.print();
	Z.reduct().print();
	return 0; 
}