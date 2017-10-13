#include <iostream>

using namespace std;

int main() {
  int a = 5;
  int &b = a; // Man må sette en verdi for b også 
  int *c;
  c = &b;
  a = b + *c; // a er en int og ikke en referanse
              // b er en peker og ikke en referanse
  b = 2;      // b er en peker og ikke en referanse
}