#include <iostream>
#include <vector>


using namespace std;

struct Foo {
    Foo() { cout << "Cons" << endl; }
    Foo(const Foo&) { cout << "Copy Cons" << endl;}
    Foo& operator=(const Foo&) { cout << "Operator=&" << endl; return *this;}
    //Foo(const Foo&&) noexcept { cout << "Copy rvalue Cons" << endl;}
    Foo(const Foo&&) { cout << "Copy rvalue Cons" << endl;}
    Foo& operator=(Foo&&) { cout << "Operator=&&" << endl; return *this;}
};

int main() {
    vector<Foo> v;
    for (int i = 0; i < 64; i++) {
        v.emplace_back();
    }
}