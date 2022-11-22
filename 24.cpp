//항목 24 : 타입 변환이 모든 매개변수에 대해 적용되어야 한다면 비멤버 함수를 선언하자

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
            return o << r.n << "/" << r.d;
        }
};


int main() {
    Rational r = 2 * Rational(2, 3);
    cout << r << endl;
}