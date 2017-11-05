#include "broek.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Broek::Broek() : teller(0), nevner(1) {}

Broek::Broek(int initTeller, int initNevner) {
  settBroek(initTeller, initNevner);
}

void Broek::settBroek(int nyTeller, int nyNevner) {
  if (nyNevner != 0) {
    teller = nyTeller;
    nevner = nyNevner;
    forkort();
  } else {
    throw "nevneren ble null";
  }
}

Broek Broek::operator+(const Broek &denAndre) const {
  Broek hjelp = *this;
  hjelp += denAndre;
  return hjelp;
}

Broek &Broek::operator+=(const Broek &denAndre) {
  settBroek(teller * denAndre.nevner + nevner * denAndre.teller,
            nevner * denAndre.nevner);
  return *this;
}

Broek &Broek::operator++() {
  teller += nevner;
  return *this;
}

//Oppgave 1a)
Broek Broek::operator-(int heltall) const {
  Broek hjelp;
  hjelp.settBroek(heltall);
  hjelp = *this - hjelp;
  return hjelp;
}

Broek Broek::operator-(const Broek &denAndre) const {
  Broek hjelp = *this;
  hjelp -= denAndre;
  return hjelp;
}

Broek &Broek::operator-=(const Broek &denAndre) {
  settBroek(teller * denAndre.nevner - nevner * denAndre.teller,
            nevner * denAndre.nevner);
  return *this;
}

Broek &Broek::operator--() {
  teller -= nevner;
  return *this;
}

Broek Broek::operator-() const {
  Broek hjelp;
  hjelp.teller = -teller;
  hjelp.nevner = nevner;
  return hjelp;
}

Broek Broek::operator*(const Broek &denAndre) const {
  Broek hjelp = *this;
  hjelp *= denAndre;
  return hjelp;
}

Broek &Broek::operator*=(const Broek &denAndre) {
  settBroek(teller * denAndre.teller, nevner * denAndre.nevner);
  return *this;
}

Broek Broek::operator/(const Broek &denAndre) const {
  Broek hjelp = *this;
  hjelp /= denAndre;
  return hjelp;
}

Broek &Broek::operator/=(const Broek &denAndre) {
  settBroek(teller * denAndre.nevner, nevner * denAndre.teller);
  return *this;
}

Broek &Broek::operator=(const Broek &original) {
  teller = original.teller;
  nevner = original.nevner;
  return *this;
}

bool Broek::operator==(const Broek &denAndre) const {
  return (sammenlikn(denAndre) == 0) ? true : false;
}

bool Broek::operator!=(const Broek &denAndre) const {
  return (sammenlikn(denAndre) != 0) ? true : false;
}

bool Broek::operator<=(const Broek &denAndre) const {
  return (sammenlikn(denAndre) <= 0) ? true : false;
}

bool Broek::operator>=(const Broek &denAndre) const {
  return (sammenlikn(denAndre) >= 0) ? true : false;
}

bool Broek::operator<(const Broek &denAndre) const {
  return (sammenlikn(denAndre) < 0) ? true : false;
}

bool Broek::operator>(const Broek &denAndre) const {
  return (sammenlikn(denAndre) > 0) ? true : false;
}

//-------------------------------------------------------------------
//
// Sørg for at nevneren alltid er positiv.
// Bruker Euclids algoritme for å finne fellesnevneren.
//
void Broek::forkort() {
  if (nevner < 0) {
    teller = -teller;
    nevner = -nevner;
  }
  int a = teller;
  int b = nevner;
  int c;
  if (a < 0)
    a = -a;

  while (b > 0) {
    c = a % b;
    a = b;
    b = c;
  }
  teller /= a;
  nevner /= a;
}

//-------------------------------------------------------------------
//
// Returnerer +1 hvis *this > denAndre, 0 hvis de er like, -1 ellers
//
int Broek::sammenlikn(const Broek &denAndre) const {
  Broek hjelp = *this - denAndre;
  if (hjelp.teller > 0)
    return 1;
  else if (hjelp.teller == 0)
    return 0;
  else
    return -1;
}

//Oppgave 1a)
Broek operator-(int heltall, const Broek &denAndre) {
  Broek hjelp;
  hjelp = denAndre - heltall;
  return hjelp;
}