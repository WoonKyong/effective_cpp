#include <iostream>

using namespace std;
template<typename T>
struct WidgetImpl {
    T t;
};

template<typename T>
class Widget {
    public:
    Widget() = default;
    Widget(const Widget& rhs) : pImpl(new WidgetImpl(*rhs.pImpl)) {}
    Widget& operator=(const Widget& rhs) {
        *pImpl = *rhs.pImpl;
        return *this;
    }
    void swap(Widget& other) {
        using std::swap;
        swap(pImpl, other.pImpl);
    }

    private:
    WidgetImpl<T> * pImpl;
};

template<typename T>
void swap(Widget<T>&a , Widget<T>& b) {
    cout << "Template swap" << endl;
    a.swap(b);
}

int main() {
    
    Widget<int> a;
    Widget<int> b;
    using std::swap;
    swap(a, b);    
}