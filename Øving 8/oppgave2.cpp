#include <iostream>
#include "par.cpp"

using namespace std;

int main() {
  Par<double, int> p1(3.5, 14);
  Par<double, int> p2(2.1, 7);
  cout << "p1: " << p1.forste << ", " << p1.andre << endl;
  cout << "p2: " << p2.forste << ", " << p2.andre << endl;
  if (p1 > p2)
  cout << "p1 er størst" << endl;
  else
  cout << "p2 er størst" << endl;
  auto sum = p1 + p2;
  cout << "Sum: " << sum.forste << ", " << sum.andre << endl;
  
  // Forutsetningene mine til denne oppgaven er at den første og den andre klassen lar seg sammenligne, noe som double og int gjør,
  // men også at operatorene +=, + og - eksisterer hos de klassene man bruker (altså i dette tilfellet hos double og int). 
}