#include<iostream>

using namespace std;

template<typename T>
class Handle {
  T* p;
public:
  Handle(T* pp): p(pp) {}
  ~Handle() {delete p;}
  Handle(Handle&& h): p(h.p) { cout<<"move ctr"<<endl; h.p = nullptr; }
  Handle& operator=(Handle&& h) {cout<<"move operator"<<endl; delete p; p =  h.p; h.p = nullptr; return *this;}
  Handle(const Handle&) = delete;
  Handle& operator=(const Handle&) = delete;
};

int main() {
  class Test {
    int id;
  public:
    Test(int i): id(i) {
      cout<<"Test "<<id<<endl;
    }
    ~Test() {
      cout<<"~Test "<<id<<endl;
    }
  };
  Handle<Test> h1(nullptr);
  {
    Handle<Test> h2(new Test(0));
    // moving via operator
    h1 = std::move(h2);
    // moving via constructor
    Handle<Test> h3(std::move(h1));
    cout<<"out of loop"<<endl;
  }
  cout<<"Getting out"<<endl;
}
