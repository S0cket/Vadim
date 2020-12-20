#include <iostream>
#include <math.h>
#define PI 3.14159265

using namespace std;

class Triangle {
protected:
	double a, b, c;
public:
	Triangle() {
		a = 1;
		b = 1;
		c = 1;
	}
	Triangle(double a, double b, double c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	~Triangle() {}

	bool exist() {
		return (a + b > c && a + c > b && b + c > a);
	}
	double P() {
		return a + b + c;
	}
	double S() {
		double p = P() / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	void print() {
		if (!exist()) {
			cout << "Triangle:\n\tNot exist!\n";
			return;
		}
		double alp = acos((b * b + c * c - a * a) / (2 * b * c));
		double bet = acos((a * a + c * c - b * b) / (2 * a * c));
		double gam = acos((a * a + b * b - c * c) / (2 * a * b));
		double alpd = alp / PI * 180;
		double betd = bet / PI * 180;
		double gamd = gam / PI * 180;
		cout << "Triangle:\n"
			<< "\tSides:\n"
				<< "\t\ta = " << a << "\n"
				<< "\t\tb = " << b << "\n"
				<< "\t\tc = " << c << "\n"
			<< "\tAngles:\n"
				<< "\t\talpha = " << alp << " rad = " << alpd << " deg\n"
				<< "\t\tbeta = " << bet << " rad = " << betd << " deg\n"
				<< "\t\tgamma = " << gam << " rad = " << gamd << " deg\n"
			<< "\tP = " << P() << "\n"
			<< "\tS = " << S() << "\n\n";
	}
};

class EqTriangle : public Triangle {
public:
	EqTriangle() {
		a = 1;
		b = 1;
		c = 1;
	}
	EqTriangle(double a, double b, double c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	~EqTriangle() {}

	bool exist() {
		return (a + b > c && a + c > b && b + c > a && a == b && a == c && b == c);
	}
};

int main(void) {
	int k, l;
	cin >> k >> l;

	double s = 0;
	for (int i = 0; i < k; ++ i) {
		cout << "Triangle " << (i + 1) << ":\n";
		double a, b, c;
		cin >> a >> b >> c;
		Triangle t(a, b, c);
		if (!t.exist()) {
			cout << "Error! Triangle not exist!\n";
			-- i;
			continue;
		}
		s += t.S();
		t.print();
	}
	s /= k;

	EqTriangle mx;
	bool flag = true;
	for (int i = 0; i < l; ++ i) {
		cout << "EqTriangle " << (i + 1) << ":\n";
		double a, b, c;
		cin >> a >> b >> c;
		EqTriangle t(a, b, c);
		if (!t.exist()) {
			cout << "Error! EqTriangle not exist!\n";
			-- i;
			continue;
		}
		if (flag) {
			flag = false;
			mx = t;
		}
		else {
			if (t.S() > mx.S())
				mx = t;
		}
		t.print();
	}
	cout << "1:\n" << s << "\n\n2:\n";
	mx.print();
	return 0;
}