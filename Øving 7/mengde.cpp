#include "mengde.h"
#include <iostream>

Mengde::Mengde() {
  mengde = vector<int>();
}

Mengde::Mengde(const vector<int> &startMengde) {
  mengde = startMengde;
}

Mengde Mengde::operator+(const int tall) {
  bool tallEksisterer = false;
  for (size_t i = 0; i < mengde.size(); i++) {
    if (mengde.at(i) == tall) {
      tallEksisterer = true;
    }
  }
  
  if (!tallEksisterer) {
    mengde.emplace_back(tall);
  }
  return *this;
}

Mengde &Mengde::operator+=(const Mengde &denAndre) {  
  for (size_t i = 0; i < denAndre.mengde.size(); i++) {
    bool funnet = false;
    for (size_t j = 0; j < mengde.size(); j++) {
      if (denAndre.mengde.at(i) == mengde.at(j)) {
        funnet = true;
      }
    }
    if (!funnet) {
      mengde.emplace_back(denAndre.mengde.at(i));
    }
  }
  return *this;
}

Mengde &Mengde::operator=(const Mengde &nyMengde) {
  mengde.clear();
  //mengde.emplace_back(nyMengde.mengde);
  for (size_t i = 0; i < nyMengde.mengde.size(); i++) {
    mengde.emplace_back(nyMengde.mengde.at(i));
  }
  
  return *this;
}

void Mengde::skrivUtMengde() {
  cout << "{";
  for (size_t i = 0; i < mengde.size(); i++) {
    if (i != 0) {
      cout << ", ";
    }
    cout << mengde.at(i);
  }
  cout << "}" << endl;
}