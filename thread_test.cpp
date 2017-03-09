#include<iostream>
#include<thread>

using namespace std;

void foo() {
  std::thread::id this_id = std::this_thread::get_id();
  cout<<"I am in "<< this_id<<endl;
}

int main() {
  foo();
  std::thread t1{foo};

  //std::thread t2;
  t1.join();
}
