#include <iostream>
#include <memory>
using namespace std;

/*
void operator delete(void *m) {
  cout << "Operator delete" << endl;
  free(m);
}
*/

struct Investment;
void Investmentdeleter(Investment* iv);

struct Investment {  
};


struct InvestmentFactory {
  static shared_ptr<Investment> createInvestment() {
    //return make_shared<Investment>(); // custom deleter 지원 안함.
    return shared_ptr<Investment>(new Investment(), Investmentdeleter);
  }
};

void Investmentdeleter(Investment* iv) {
  cout << "Custom Deleter" << endl;
  delete iv;
}

int main() {
  shared_ptr<Investment> iv = InvestmentFactory::createInvestment();
  return 0;
}

/*
https://source.chromium.org/chromium/chromium/src/+/main:third_party/blink/renderer/modules/modules_initializer.cc;l=327;drc=b75fd5075a90ada27a3360df23fa08c83e24e995;bpv=1;bpt=1
*/