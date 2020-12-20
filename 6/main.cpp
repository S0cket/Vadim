#include <iostream>

using namespace std;

class Transporter {
private:
	double speed, price;
public:
	double cost(double distance) {
		return price * distance;
	}
	double time(double distance) {
		return distance / speed;
	}
	friend class Airplane;
	friend class Train;
	friend class Car;
};

class Airplane : public Transporter {
public:
	Airplane() {
		speed = 700;
		price = 1000;
	}
	~Airplane() {}
};

class Train : public Transporter {
public:
	Train() {
		speed = 70;
		price = 700;
	}
	~Train() {}
};

class Car : public Transporter {
public:
	Car() {
		speed = 120;
		price = 500;
	}
	~Car() {}
};

int main(void) {
	Airplane a;
	Train t;
	Car c;
	double s;
	cout << "Input distance: ";
	cin >> s;

	cout << "Airplane:\n"
		<< "\tcost: " << a.cost(s) << endl
		<< "\ttime: " << a.time(s) << endl << endl;

	cout << "Train:\n"
		<< "\tcost: " << t.cost(s) << endl
		<< "\ttime: " << t.time(s) << endl << endl;

	cout << "Car:\n"
		<< "\tcost: " << c.cost(s) << endl
		<< "\ttime: " << c.time(s) << endl << endl;

	return 0;
}