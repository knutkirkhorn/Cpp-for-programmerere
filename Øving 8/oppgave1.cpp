#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

template <class type>
bool likhet(type a, type b) {
  cout << "Templateversjon: likhet mellom `" << a << "` og `" << b << "`" << endl;
  
  if (a == b) {
    return true;
  }
  return false;
}

bool likhet(double a, double b) {
  setprecision(8);
  cout << "Doubleversjon: likhet mellom `" << a << "` og `" << b << "`" << endl;
  double feilmargin = 0.00001;
  
  if (abs(a - b) < feilmargin) {
    return true;
  }
  return false;
}

int main() {
  // Ulike double variabler
  double a = 1.1;
  double b = 0.1;
  if (likhet(a, b)) {
    cout << "=> Like" << endl << endl;
  } else {
    cout << "=> Ikke like" << endl << endl;
  }
  
  // Ulike double variabler, men like pga presisjonen
  double c = 1.00001;
  double d = 1.000011;
  if (likhet(c, d)) {
    cout << "=> Like" << endl << endl;
  } else {
    cout << "=> Ikke like" << endl << endl;
  }
  
  // Ulike double variabler
  double e = 1.00001;
  double f = 1.00003;
  if (likhet(e, f)) {
    cout << "=> Like" << endl << endl;
  } else {
    cout << "=> Ikke like" << endl << endl;
  }
  
  // Like string variabler
  string aa = "Denne strengen er lik for begge";
  string aac = "Denne strengen er lik for begge";
  if (likhet(aa, aac)) {
    cout << "=> Like" << endl << endl;
  } else {
    cout << "=> Ikke like" << endl << endl;
  }
}