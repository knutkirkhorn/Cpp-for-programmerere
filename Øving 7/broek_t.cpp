#include "broek.h"
#include <iostream>
#include <string>

using namespace std;

void skriv(const string &tekst, const Broek &Broek);

int main() {
  Broek a(10, 20);
  Broek b(3, 4);
  Broek c;
  c.settBroek(5);
  Broek d = a / b;

  skriv("a = ", a);
  skriv("b = ", b);
  skriv("c = ", c);
  skriv("d = ", d);

  b += a;
  ++c;
  d *= d;

  skriv("b = ", b);
  skriv("c = ", c);
  skriv("d = ", d);

  c = a + b - d * a;
  c = -c;

  skriv("c = ", c);

  if (a + b != c + d)
    cout << "a + b != c + d" << endl;
  else
    cout << " a + b == c + d" << endl;
  while (b > a)
    b -= a;
  skriv("b = ", b);

  // Oppgave 1 a)
  Broek broekA(40, 2);
  skriv("broekA = ", broekA);
  Broek broekB = broekA - 5;
  skriv("broekB = ", broekB);
  Broek broekC = 5 - broekA;
  skriv("broekC = ", broekC);
  
  return 0;
}

void skriv(const string &tekst, const Broek &broek) {
  cout << tekst << broek.finnTeller() << " / ";
  cout << broek.finnNevner() << endl;
}
