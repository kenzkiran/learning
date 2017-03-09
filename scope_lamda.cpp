#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<memory>

using namespace std;

struct Foo {
  Foo() {
    cout<<"Foo()"<<endl;
  }
  Foo(const Foo& b) {
    cout<<"Copy Construct Foo()"<<endl;
  }

  Foo& operator=(const Foo& rhs) {
    cout<<"Copy Assignment Foo"<<endl;
    return *this;
  }
  ~Foo() {
    cout<<"~Foo()"<<endl;
  }
  void sayWorld() {
    cout<<"World !"<<endl;
  }
};


struct Base {
  int x = 8;
  Foo f;
  int *arr;
  Base() {
    arr = new int[3];
    arr[0] = 9;
    arr[1] = 10;
    arr[2] = 6418;
    cout<<"B()"<<endl;
  }
  Base(const Base& b) {
    x = b.x;

    cout<<"Copy Construct B()"<<endl;
  }

  void sayHello() {
    cout<<"Hello "<<endl;
  }
  Base& operator=(const Base& rhs) {
    cout<<"Copy Assignment"<<endl;
    x = rhs.x;
    return *this;
  }
  ~Base() {
    if (arr) {
      delete arr;
    }
    arr = nullptr;
    cout<<"~B()"<<endl;
  }
  std::function<void()> dump() {
    return [this]()->void{
      sayHello();
      f.sayWorld();
      cout<<"Base's value :" << x<<" arr[2]: "<< arr[2]<<endl;
    };
  }
};

int main() {
    std::function<void()> baseCb;
    {
      unique_ptr<Base> b(new Base);
      baseCb = b->dump();
      b->x = 9;
      baseCb();
      cout<<"Going out of scope"<<endl;
    }
    cout<<"Should not execute since base has gone out of scope"<<endl;
    baseCb();
}
