#include <iostream>
using namespace std;

class Rational {
    public:
        Rational(int numerator = 0, int denomicator = 1) :
        n(numerator), d(denomicator) {
            cout << "Cons " << *this << endl;
        }
        
        Rational(const Rational& r) :
        n(r.n), d(r.d) {
            cout << "Copy cons " << *this << endl;
        }

        Rational(Rational&& r) :
        n(r.n), d(r.d) {
            cout << "Move cons " << *this << endl;
        }

    private:
        int n = 0;
        int d = 1;
        friend const Rational operator*(const Rational& lhs, const Rational& rhs) {
            return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
        }
        friend ostream& operator <<(ostream& o, const Rational& r) {
            o << r.n << "/" << r.d;
            return o;
        }
};


int main() {
    Rational r = 2 * Rational(2, 3);
    cout << r << endl;
}