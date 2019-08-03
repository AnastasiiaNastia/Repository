#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

int NOD(int a, int b) {
	return b == 0 ? a : NOD(b, a % b);
}

int sign(int a) {
	return a > 0 ? 1 : -1;
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
        	num = abs(numerator/NOD(numerator, denominator)) * sign(numerator*denominator);
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

Rational operator+ (const Rational& l, const Rational& r) {
	return {l.Numerator() * r.Denominator() + r.Numerator() * l.Denominator(),
		l.Denominator() * r.Denominator()};
}

Rational operator- (const Rational& l, const Rational& r) {
	return {l.Numerator() * r.Denominator() - r.Numerator() * l.Denominator(),
		l.Denominator() * r.Denominator()};
}

Rational operator* (const Rational& l, const Rational& r) {
	return {l.Numerator() * r.Numerator(), l.Denominator() * r.Denominator()};
}

Rational operator/ (const Rational& l, const Rational& r) {
	return {l.Numerator() * r.Denominator(), l.Denominator() * r.Numerator()};
}

ostream& operator<< (ostream& stream, const Rational& r) {
	return stream << r.Numerator() << "/" << r.Denominator();
}

istream& operator>> (istream& stream, Rational& r){
	int p, q;
	if (stream >> p && stream.ignore(1) && stream >> q) {
		r = {p, q};
	}
	return stream;
}

bool operator< (const Rational& l, const Rational& r) {
	return l.Numerator() * r.Denominator() < r.Numerator() * l.Denominator();
}

bool operator== (const Rational& l, const Rational& r) {
	return !((r < l) || (l < r));
}

int main(){
	return 0;
}
