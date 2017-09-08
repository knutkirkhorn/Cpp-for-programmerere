#include <iostream>

using namespace std;

int main() {
  int a = 5;
  int &b = a;
  int *c;
  c = &b;
  a = b + *c;
  b = 2;
}