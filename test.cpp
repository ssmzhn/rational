#include "rational.h"
using namespace RATIONAL;
int main() {
	//54/78896,4656/9796565
    Rational a(545,0),b(5448,44855);
    cout <<a<<"+"<<b<<"=="<<a+b<<endl;
	cout <<a<<"-"<<b<<"=="<<a-b<<endl;
	cout <<a<<"*"<<b<<"=="<<a*b<<endl;
	cout <<a<<"/"<<b<<"=="<<a/b<<endl;
    return 0;
}
