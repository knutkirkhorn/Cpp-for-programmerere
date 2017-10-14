//
// VareTest.cpp
//

#include <iostream>
#include <string>
#include "vare.h"

using namespace std;

int main() {
  const double kvantum = 2.5;
  const double kilopris1 = 73.50;
  const double kilopris2 = 79.60;
  Vare enVare("Norvegia", 123, kilopris1);

  cout << "Varenavn: " << enVare.finnNavn() << ", varenr: " << enVare.finnVarenr()
       << " Pris pr enhet: " << enVare.finnPrisPrEnhet() << endl;
  double pris1 = enVare.finnPrisUtenMoms(kvantum);
  double pris2 = enVare.finnPrisMedMoms(kvantum);
  cout << "Kilopris: " << kilopris1 << endl;
  cout << "Prisen for " << kvantum << " kg er " << pris1 << " uten moms" << endl;
  cout << "Prisen for " << kvantum << " kg er " << pris2 << " med moms" << endl;

  enVare.settPris(kilopris2);
  cout << "Ny kilopris: " << enVare.finnPrisPrEnhet() << endl;
  cout << "Prisen for " << kvantum << " kg er "
       << enVare.finnPrisUtenMoms(kvantum) << " uten moms" << endl;
  cout << "Prisen for " << kvantum << " kg er "
       << enVare.finnPrisMedMoms(kvantum) << " med moms" << endl;
  return 0;
}