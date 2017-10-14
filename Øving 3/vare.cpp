//
// Vare.cpp
//
#include "vare.h"

using namespace std;

Vare::Vare(string startNavn, int startVarenr, double startPris) :
  varenavn(startNavn), varenr(startVarenr), pris(startPris) {}

string Vare::finnNavn() const {
  return varenavn;
}

int Vare::finnVarenr() const {
  return varenr;
}

double Vare::finnPrisPrEnhet() const {
  return pris;
}

void Vare::settPris(double nyPris) {
  pris = nyPris;
}

double Vare::finnPrisUtenMoms(double kvantum) {
  return pris * kvantum;
}

double Vare::finnPrisMedMoms(double kvantum) {
  double prisUtenMoms = finnPrisUtenMoms(kvantum);
  double prisMoms = pris * kvantum * moms;
  return prisUtenMoms + prisMoms;
}