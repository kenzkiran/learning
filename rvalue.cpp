#include<iostream>
#include<string>
#include<vector>

using namespace std;
void printReference(string& str) {
    cout<<"lvalue Str: "<<str<<(void *)&str<<endl;
}

void printReference(string&& str) {
    cout<<"rvalue Str: "<<str<<endl;
}

string getName() {
  return "I am an rvalue";
}

string& refRet() {
  string* s = new string;
  s->append("Hello");
  return *s;
}

int main() {

  int&& t  = 3;
  cout<<t<<endl;
  // strangely you can increment
  cout<<++t<<endl;

  string m("I am a lvalue");

  cout<<(void *)&m;
  printReference(m);
  printReference(getName());

  string& s = refRet();
  cout<<s;
}
