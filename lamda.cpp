#include<iostream>
#include<string>
#include<vector>
#include<functional>

using namespace std;

using StudentList = vector<std::tuple<int, string>>;
using BaseDumpCb = std::function<string()>;
StudentList classOfGrade1;
StudentList classOfGrade2;

struct Base {
  int x;
  float y;
  std::function<string()> dump() {
    return [this]()->string { return "(" + to_string(x) + "," + to_string(y) + ")";};
  }


  ~Base() {
    cout<<"~B()"<<endl;
  }
  void sayHello() {
    cout<<"Hello I am Base"<<endl;
  }

  void callback(string result) {
    cout<<"Base::callback :"<<result<<endl;
  }
};

struct Other {
  int x;
  string name;
  std::function<string()> dump() {
    return [this]()->string { return "(" + to_string(x) + "," + name + ")";};
  }
};



int y = 8888;
int& getRef() {
  return y;
}

// TO BE BOUND FUNCTION
void addStudentToGrade(StudentList& grade, int age, string name) {
    cout<<"Adding "<<name<<age<<"  "<<(void *)&grade<<endl;
    grade.push_back({age, name});
}


void doSomeOperationAndCallback(std::function<void(string)> cb, bool ret) {
  if (ret) {
    cb("Success");
  } else {
    cb("Failure");
  }
}

void somefunction(int t) {
  cout<<"Value of t:" <<t<<endl;
}
int main() {
  string x = "yo";
  auto dummy = [=](string name)->void { cout<<x<<" Hello: " <<name<<endl;};

  Base b{5, 9.0f};
  Other o{8, "Mansi"};
  vector<std::function<string()>> arr = {b.dump(), o.dump()};
  for (auto&& x : arr) {
    cout<<x()<<endl;
  }

 cout<<" Y value "<<y;
 // this looks strange but it is manipulating y because it get a y's reference and hence
 getRef() = 9999;
 cout<<" Y value "<<y;

 string m("aiyoo");

 vector<int> ages = {26, 35, 18};

 // another good use of lambda functions
 for_each(ages.begin(), ages.end(), [](const int& val) {
   cout<<" Ages: "<< val<<endl;
 });

 // Bind usages and use of placehoders::_1 ..
 auto grade1adder = bind(addStudentToGrade, placeholders::_1, 5,placeholders::_2);
 // see the usage of std::ref
 auto grade2adder = bind(addStudentToGrade, std::ref(classOfGrade2), 6,placeholders::_1);

 grade1adder(classOfGrade1, "Ravi");
 // Look at how to use reference using std::ref
 grade2adder("Mansi");

 cout<<"size of grade 1: "<<classOfGrade1.size()<<endl;
 cout<<"size of grade 2: "<<classOfGrade2.size()<<endl;

 // using tuple 'unamed access'
 cout<<get<1>(classOfGrade2[0])<<" should be equal to \"Mansi\""<<endl;

// good old function pointer can also be bound
 void(*fptr)(int) = somefunction;
 auto boundFptr = std::bind(fptr, 999);
 boundFptr();

 //reference a method, see how first param is used for instance
 std::function<void(Base*)> baseSayHello = &Base::sayHello;
 baseSayHello(&b);

 doSomeOperationAndCallback(std::bind(&Base::callback, b, placeholders::_1), true);
 doSomeOperationAndCallback(std::bind(&Base::callback, b, placeholders::_1), false);

}
