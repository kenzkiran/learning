/* constructor destructor experiments */

#include<iostream>

using namespace std;
class B {
public:
  B(){
    cout<<"B constructor"<<endl;
  }

  virtual ~B(){
    cout<<"~B destructor\n";
  }
};

class D: public B {
public:
  D() {
    cout<<"D constructor\n";
  }
  ~D() {
    cout<<"D destructor\n";
  }
};

int main() {

   D d;
   {
      B b = d;
   }
}
