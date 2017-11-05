#include <iostream>
#include "mengde.h"

using namespace std;

int main() {
  // Lage en tom mengde og så fylle på elementer
  Mengde mengdeA;
  mengdeA + 1;
  mengdeA + 4;
  mengdeA + 6;
  mengdeA.skrivUtMengde();
  
  // Lage en mengde med startmengde
  vector<int> tall = {1, 2, 3};
  Mengde mengdeB(tall);
  mengdeB.skrivUtMengde();
  
  // Lage summen (union) av to mengder
  Mengde sumAB;
  sumAB = mengdeA;
  sumAB += mengdeB;
  sumAB.skrivUtMengde();
}