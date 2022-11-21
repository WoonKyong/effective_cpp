#include <iostream>
using namespace std;

struct Foo {
    Foo() { cout << "Cons" << endl; }
    Foo(const Foo&) { cout << "Copy Cons" << endl;}
    Foo(const Foo&&) { cout << "Copy rvalue Cons" << endl;}
};

void func_ref(const Foo &f) {
    Foo i = f;

}

void func_move(Foo f) {
    Foo i = move(f);
 }

int main() {
    Foo f;
    cout << "-- const reference --" << endl;
    func_ref(f);
    cout << "-- value --" << endl;
    func_move(move(f));
}

/* shared_ptr은?? https://stackoverflow.com/questions/3310737/should-we-pass-a-shared-ptr-by-reference-or-by-value
Shortly, there is no reason to pass by value, unless the goal is to share ownership of an object
(eg. between different data structures, or between different threads).
*/
