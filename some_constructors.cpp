#include<iostream>

using namespace std;
class Foo {
public:
  string name = "anonymous";
protected:
  int side;
  void setSide(int s) { cout<<"Base class side set"<<endl; side = s;};
};

class Bar: public Foo {
  double angle;
public:
  Bar(int s = 0) {side= s; cout<<"Bar's int constructor"<<endl;}
  // Delegating constructors
  Bar(double ag = 90.0): Bar{0} { cout<<"Bar's double constructor"<<endl; angle = ag;}
  using Foo::setSide;
  void setSide(int s, double ag) {side = s; angle = ag;};
};


//Note:  no need of explicit 'public'
struct B {
		void f(double) {};
};

struct D : B {
  using B::f;
	void f(int){};
};

int main() {
  Bar bar(89.9);
  cout<<"My name: "<<bar.name<<endl;
  bar.setSide(8);

  B b;   b.f(4.5);	// fine
	D d;   d.f(4.5);
}
