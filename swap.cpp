#include <iostream>
#include <algorithm>
using namespace std;


struct Foo {
    Foo() { cout << "Cons" << endl; }
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

int main() {
    Foo i;
    Foo j;

    swap(i, j);

}