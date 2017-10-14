#include <iostream>
#include "Sirkel.cpp"

using namespace std;

int main() {
  Sirkel enSirkel(5);
  double arealet = enSirkel.finnAreal();
  cout << "Arealet er lik " << arealet << endl;
  double omkrets = enSirkel.finnOmkrets();
  cout << "Omkretsen er lik " << omkrets << endl;
  return 0;
}