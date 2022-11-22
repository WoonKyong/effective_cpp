// 항목 25 : 예외를 던지지 않는 swap 에 대한 지원도 생각해 보자

#include <iostream>
#include <algorithm>
using namespace std;


struct Foo {
    //Foo() { cout << "Cons" << endl; }
    Foo() = default;
    Foo(const Foo&) { cout << "Copy Cons" << endl;}
    Foo(const Foo&&) { cout << "Copy rvalue Cons" << endl;}
    Foo& operator=(const Foo&) {
        cout << "Operator =" << endl;
        return *this;
    }

    Foo& operator=(Foo&&) {
        cout << "Operator =&&" << endl;
        return *this;
    }
};

template<typename T>
void xswap(T& a, T& b) {
    T tmp = move(a);
    a = move(b);
    b = move(tmp);
}

int main() {
    Foo i;
    Foo j;

    //xswap(i, j);
    std::swap(i, j);

}