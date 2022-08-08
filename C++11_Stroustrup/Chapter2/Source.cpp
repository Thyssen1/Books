#include <iostream>
#include <complex>

template <typename T>
double square(T x) {
	return x * x;
}

void print_sizeof() {
	std::cout << "Size of bool: " << sizeof(bool) << "\n";
	std::cout << "Size of char: " << sizeof(char) << "\n";
	std::cout << "Size of int: " << sizeof(int) << "\n";
	std::cout << "Size of float: " << sizeof(float) << "\n";
	std::cout << "Size of double: " << sizeof(double) << "\n";
	std::cout << "Size of std::complex<double>: " << sizeof(std::complex<double>) << "\n";
}

bool accept() {
	int tries = 1;
	while (tries <= 4) {
		std::cout << "Do you want to proceed? (y/n) \n";
		char answer = 0;
		std::cin >> answer;

		switch (answer) {
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			std::cout << "Sorry I do not understand that option.\n";
			tries++;
		}
	}

	std::cout << "I will take that as a no.\n";
	return false;
}

void print() {
	int v1[] = { 0,1,2,3,4,5,6,7,8,9 };
	int v2[10];

	std::cout << "Copy elements of v1 into v2.\n";
	for (auto& i : v1) {
		v2[i] = v1[i];

		std::cout << v2[i] << "\n";
	}
}

//struct Vector {
//	int n_elems;	// Number of elements
//	double* elems;	// Pointer to elements in Vector
//};
//
//// Initialize Vector object
//void vector_init(Vector& v, int s) {
//	v.elems = new double[s];
//	v.n_elems = s;
//}

class Vector {
public:
	Vector(int s) : sz(s), elem{ new double[s] } {}
	~Vector() {
		delete elem;
	}

	double& operator[](int i) { 
		/*if (i < 0 || size() < i) {
			throw std::out_of_range{"Vector::operator[]"};
		}*/
		try {
			return elem[i];
		}
		catch (std::out_of_range) {
			std::cout << "Out of range error!\n";
		}
		return elem[i]; 
	}
	int size() { return sz; }

private:
	double* elem;
	int sz;
};

enum class Color {
	red, 
	blue, 
	green
};

enum class TrafficLight {
	green,
	yellow, 
	red
};

TrafficLight& operator++(TrafficLight& t) {
	switch (t) {
	case TrafficLight::green:
		return t = TrafficLight::red;
	case TrafficLight::red:
		return t = TrafficLight::yellow;
	case TrafficLight::yellow:
		return t = TrafficLight::green;
	}
}

namespace MySpace {
	void print() {
		std::cout << "Hello from my space!\n";
	}
}

int main() {
	// Hello world!
	std::cout << "Hello world!\n";

	// Square a number
	constexpr int a = 5;	// Evaluate at compile time
	int b = square(a);

	// Print size of different data types
	print_sizeof();

	// 
	bool isAccepted = accept();

	// Pointers
	char v[6];
	char* p = &v[3]; // Point to the fourth member of v

	//
	print();

	// Initialize enums
	Color col = Color::red;
	TrafficLight light = TrafficLight::green;
	++light; // Increment 

	// Example of defining a namespace and using the code inside
	MySpace::print();

	// Static assertions
	constexpr double C = 299792.458;

	//static_assert(8 <= sizeof(int), "Integers are too small."); // Compile-time error

	return 0;
}