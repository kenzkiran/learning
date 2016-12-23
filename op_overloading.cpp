#include<iostream>
#include<string>

using namespace std;
class Test {
public:
  int i;
  std::string name;
  Test(int ii, string nn): i(ii), name(nn) {};
  Test& operator+(const Test& in) {
    //return {i+ in.i, name + in.name};
    Test* n = new Test(i + in.i, name + in.name);
    return *n;
  }
private:
  Test(const Test&) = delete;
  void operator=(const Test&) = delete;
};

void nameMe(Test t) {
  cout<<t.name<<endl;
}

int main() {
  Test t1 = {1, "mansi"};
  Test t2 = {2, "Ravi"};
  Test& t3 = t1 + t2;
  //Test t4  = t3;
  //nameMe(t2);
  cout<<t3.name<<"  "<<t3.i<<endl;
  //cout<<t4.name<<"  "<<t4.i<<endl;
  return 0;
}
