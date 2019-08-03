#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

int NOD (int a, int b){
	a = abs(a);
	b = abs(b);
	while (a > 0 && b > 0) {
		if (a > b) {
			a = a % b;
		} else {
			b = b % a;
		}
	}
	return a + b;
}

int sign(const int& a){
	if (a > 0){
		return 1;
	} else {
		return -1;
	}
}

class Rational {
public:
    Rational() {
    	num = 0;
    	denom = 1;
    }

    Rational(int numerator, int denominator) {
        if (numerator == 0){
        	num = 0;
        	denom = 1;
        } else {
        	num = abs(numerator/NOD(numerator, denominator))
        			*sign(numerator*denominator);
        	denom = abs(denominator/NOD(numerator, denominator));
        }
    }

    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return denom;
    }

private:
    int num;
    int denom;
};

bool operator== (const Rational& right, const Rational& left){
	return (right.Denominator() == left.Denominator() &&
			right.Numerator() == left.Numerator());
}

Rational operator+ (const Rational& r, const Rational& l){
	int p = r.Numerator() * l.Denominator() +
		l.Numerator() * r.Denominator();
	int q = r.Denominator() * l.Denominator();
	return {p, q};
}

Rational operator- (const Rational& r, const Rational& l){
	int p = r.Numerator() * l.Denominator() -
		l.Numerator() * r.Denominator();
	int q = r.Denominator() * l.Denominator();
	return {p, q};
}

Rational operator* (const Rational& r, const Rational& l){
	int p = r.Numerator()*l.Numerator();
	int q = r.Denominator() * l.Denominator();
	return {p, q};
}

Rational operator/ (const Rational& r, const Rational& l){
	int p = r.Numerator() * l.Denominator();
	int q = r.Denominator() * l.Numerator();
	return {p, q};
}

ostream& operator<< (ostream& stream, const Rational& r){
	stream << r.Numerator() << "/" << r.Denominator();
	return stream;
}

istream& operator>> (istream& stream, Rational& r){
	int p, q;
	if (stream >> p && stream.ignore(1) && stream >> q){
		r = {p, q};
	}
	return stream;
}

bool operator> (const Rational& r, const Rational& l){
	return (r.Numerator() * l.Denominator()
			> l.Numerator() * r.Denominator());
}

bool operator< (const Rational& r, const Rational& l){
	return (r.Numerator() * l.Denominator()
			< l.Numerator() * r.Denominator());
}
