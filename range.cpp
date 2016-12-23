#include<iostream>
#include<vector>
#include <string>

using namespace std;

vector<int> vec = {6, 7, 9};

struct Student {
  string name;
  int id;
};
class Grade {
public:
  Grade(initializer_list<Student> args) {
    for(auto p = args.begin(); p != args.end(); ++p) {
        cout<<(*p).name<<":";
        cout<<(*p).id<<endl;
    }
  }
};
int main() {

  vector<int> *t = &vec;
  for (auto v : *t) {
      cout<<v<<endl;
  }

  Grade g = {{"ravi", 10}, {"mansi", 9}, {"putta", 90}};

}
