#include <iostream>
#include <functional>

using namespace std;

struct MyStruct {
  int x;
};

using MyCb = std::function<int(MyStruct)>;

void setFunc(MyCb cb) {
  MyStruct s{8};
  if (cb) {
    cout<<"Value : "<<cb(s);
  }
}

int someCb(MyStruct s) {
  return s.x;
}

int main() {
  setFunc(someCb);
  return 1;
}
