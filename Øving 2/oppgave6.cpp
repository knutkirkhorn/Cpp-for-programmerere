#include <iostream>

using namespace std;

int finnSum(const int *tabell, int antElementer) {
  int teller = 0;
  for (int i = 0; i < antElementer; i++) {
    teller += tabell[i];
  }
  return teller;
}

int main() {
  int antall = 20;
  int tabell[antall];
  
  for (int i = 0; i < antall; i++) {
    tabell[i] = (i+1);
  }
  
  int forste10 = finnSum(tabell, 10);
  int neste5 = finnSum(&tabell[10], 5);
  int siste5 = finnSum(&tabell[15], 5);
  
  cout << "Første 10: " << forste10 << endl;
  cout << "Neste 5: " << neste5 << endl;
  cout << "Siste 5: " << siste5 << endl;
}