#include <iostream>
#include <string>

using namespace std;

int GetSetting(const std::string& name, const int def_value) {
  return 8;
}

std::string GetSetting(const std::string& name, const std::string& def_value) {
  return std::string("ravi");
}

template <class T>
T MyGetSetting(std::string& name, const T&& def_value) {
  T val = GetSetting(name, std::forward<const T>(def_value));
  return val;
}

int main() {
  std::string some_name = "name";
  cout << MyGetSetting<int>(some_name, 1) << endl;
  cout << MyGetSetting<std::string>(some_name, std::string("something"))
       << endl;
}