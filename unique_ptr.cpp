#include<iostream>

using namespace std;

struct B {
  B() {
    cout<<"B()"<<endl;
  }
  ~B() {
    cout<<"~B()"<<endl;
  }
};

std::unique_ptr<B> creator() {
  return std::move(std::unique_ptr<B>(new B));
}

void TEST_RELEASE() {
  B* oldFashionPtr;
  {
    unique_ptr<B> bptr;
    unique_ptr<B> bptr2;
    if (bptr == nullptr) {
      cout<<"Unassigned unique_ptr is equal to nullptr"<<endl;
    }
    bptr.reset(new B);
    oldFashionPtr = bptr.release();
    cout<<"Going out of scope"<<endl;
  }
  cout<<"Coming into main scope"<<endl;
  delete oldFashionPtr;
}

void TEST_MOVE() {
  std::unique_ptr<B> bptr = creator();
  cout<<"TEST_MOVE: Going out of Scope"<<endl;
}

int main() {
  TEST_MOVE();
  return 0;
}
