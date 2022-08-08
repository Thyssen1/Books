#include <iostream>


class complex {
private:
	double m_re;
	double m_im;

public:
	complex() : m_re(0), m_im(0) {}							// Default
	complex(double re) : m_re(re), m_im(0) {}				// One scalar
	complex(double re, double im) : m_re(re), m_im(im) {}	// Two scalars

	double real() { return m_re; }
	void set_real(double re) { m_re = re; }
	double imag() { return m_im; }
	void set_imag(double im) { m_im = im; }

	complex& operator+=(complex z) { m_re += z.m_re; m_im += z.m_im; return *this; }
	complex& operator-=(complex z) { m_re -= z.m_re; m_im -= z.m_im; return *this; }
	/*complex& operator*=(complex z);
	complex& operator/=(complex z);*/
};

complex operator+(complex a, complex b) { return a += b; }
complex operator-(complex a, complex b) { return a -= b; }
complex operator-(complex a) { return { -a.real(), a.imag() }; }
//complex operator*(complex a, complex b) { return a *= b; }
//complex operator/(complex a, complex b) { return a /= b; }

bool operator==(complex a, complex b) {
	return a.real() == b.real() && a.imag() == b.imag();
}

bool operator!=(complex a, complex b) {
	return !(a == b);
}

void foo() {
	complex a{ 2.3 };
	complex b{ 2,2 };
	complex c{ a + b };

	std::cout << c.real() << "\n";
	std::cout << c.imag() << "\n";
}

int main() {
	complex z{ 2,1 };

	foo();

	return 0;
}