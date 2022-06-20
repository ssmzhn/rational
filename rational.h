#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <cmath>
#include <iostream>
using namespace std;
namespace RATIONAL {
class Rational {
   private:
    unsigned int num;
    unsigned int deno;
    bool sign;
    void reduce(unsigned int& n, unsigned int& d);
    unsigned int gcd(unsigned int n,unsigned int d) const;

   public:
    Rational();
    Rational(int n, int d);
    Rational(bool s, unsigned int n, unsigned int d);
    // bool set(int n,int d);
    friend Rational operator+(const Rational a, const Rational b);
    friend Rational operator-(const Rational a, const Rational b);
    Rational operator-() const;
    friend Rational operator*(const Rational a, const Rational b);
    friend Rational operator/(const Rational a, const Rational b);
    friend ostream& operator<<(ostream& os, const Rational& rat);
};

void Rational::reduce(unsigned int& n, unsigned int& d) {
    int tmp_n = n, tmp_d = d;
    n /= RATIONAL::Rational::gcd(tmp_n, tmp_d);
    d /= RATIONAL::Rational::gcd(tmp_n, tmp_d);
}

unsigned int Rational::gcd(unsigned int n, unsigned int d) const {
    unsigned int ans = 1;
    unsigned int tmp_n = n, tmp_d = d;
    for (int i = 2; i <= ((tmp_n > tmp_d) ? tmp_d : tmp_n);) {
	if (n % i == 0 && d % i == 0) {
	    ans *= i;
	    n /= i;
	    d /= i;
	    continue;
	}
	i++;
    }
    return ans;
}

Rational::Rational() {
    num = 0;
    deno = 1;
    sign = true;
}

Rational::Rational(int n, int d) {
    if (d != 0) {
	num = n;
	deno = d;
	if ((num >= 0 && deno > 0) || (num < 0 && deno < 0)) {
	    sign = true;
	} else {
	    sign = false;
	    num = abs(n);
	    deno = abs(d);
	}
	Rational::reduce(num, deno);
    } else {
	throw 114;
    }
}

Rational::Rational(bool s, unsigned int n, unsigned int d) {
    if (d != 0) {
	num = n;
	deno = d;
	sign = s;
	Rational::reduce(num, deno);
    } else {
	throw 114;
    }
}
ostream& operator<<(ostream& os, const RATIONAL::Rational& rat) {
    if (rat.deno == 1)
	os << (rat.sign ? "" : "-") << rat.num;
    else
	os << (rat.sign ? "" : "-") << rat.num << "/" << rat.deno;
    return os;
}

Rational operator+(const Rational a, const Rational b) {
    Rational c;
    if (a.sign == b.sign) {
	int c_num = a.num * b.deno + a.deno * b.num;
	int c_deno = a.deno * b.deno;
	c = Rational(a.sign, c_num, c_deno);
    } else {
	int c_num = abs(int(a.num * b.deno - a.deno * b.num));
	int c_deno = abs(int(a.deno * b.deno));
	c = Rational(abs(c_num) >= 0 ? a.sign : b.sign, c_num, c_deno);
    }
    return c;
}

Rational operator-(const Rational a, const Rational b) {
    Rational min_b = b;
    min_b.sign = !b.sign;
    Rational c(a + min_b);
    return c;
}
Rational Rational::operator-() const {
    Rational ans = *this;
    ans.sign = !sign;
    return ans;
}
Rational operator*(const Rational a, const Rational b) {
    Rational c((a.sign == b.sign) ? true : false, a.num * b.num,
	       a.deno * b.deno);
    return c;
}
Rational operator/(const Rational a, const Rational b) {
    if (b.num == 0)
	throw 114;  //这句没有也行
    else {
	Rational tmp(b.sign, b.deno, b.num);
	return a * tmp;
    }
}
};  // namespace RATIONAL
#endif
