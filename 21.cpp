// 항목 21 : 함수에서 객체를 반환해야 할 경우에 참조자를 반환하려고 들지 말자
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
        friend const Rational operator*(const Rational& lhs, const Rational& rhs);
        friend ostream& operator <<(ostream& o, const Rational& r) {
            return o << r.n << "/" << r.d;            
        }
};

const Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
}


int main() {
    Rational r = Rational(1,2) * Rational(3,6);    
    cout << r << endl;
}

/* 
const Rational& operator*(const Rational& lhs, const Rational& rhs)
{
  Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
  return result;
}

const Rational& operator*(const Rational& lhs, const Rational& rhs)
{
  Rational *result = new Rational(lhs.n * rhs.n, lhs.d * rhs.d);
  return *result;
}


const Rational& operator*(const Rational& lhs, const Rational& rhs)
{
  static Rational result;
  result = Rational(lhs.n * rhs.n, lhs.d * rhs.d);
  return result;
}
*/