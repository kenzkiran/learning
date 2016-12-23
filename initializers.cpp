#include<iostream>
#include<map>
#include<vector>

using namespace std;

// tighter control of the value, no defaulting to int
enum class Colors : char {red, green, blue};

void foo(Colors in) {
    cout<<" Color: ";
    switch(in) {
      case Colors::red:
        cout<<"Red"<<endl;
        break;
      case Colors::green:
        cout<<"Green"<<endl;
        break;
      case Colors::blue:
      default:
        cout<<"Blue"<<endl;
    }
}

struct B {
  int x;
  double y;
  void dump() {
    cout<<x<<" "<<y<<endl;
  }
};

B multiplyBy2(B in) {
  return {in.x *2 , in.y * 2};
}

int main() {
    map<string, vector<int>> m = {{"ravi", {1,2,3,4}}, {"mansi", {8, 9, 10, 11}}};
    cout<<m["mansi"][0]<<endl;
    int y = 8;
    int x = 3;
    int& refy = y;
    refy = 9;
    refy = x;
    refy++;
    cout<<"Real y: "<<y<<endl;
    cout<<"Ref y: "<<refy<<endl;
    // Lexical cast not available in std lib, seem only available in boost
    //cout<<" Doing lexical cast to an float : "<<lexical_cast<float>(5.6) + 4.4<<endl;
    //cout<<" Doing lexical cast to an string : "<<lexical_cast<string>(8.8) + "ravi"<<endl;
    foo(Colors::green);
    multiplyBy2({2, 4.2}).dump();
}
