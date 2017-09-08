#include <iostream>

using namespace std;

int main() {
  //Oppgave a
  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;
  
  cout << "i: Verdi: " << i << ", Adresse: " << &i << endl;
  cout << "j: Verdi: " << j << ", Adresse: " << &j << endl;
  cout << "p: Verdi: " << p << ", Adresse: " << &p << endl;
  cout << "q: Verdi: " << q << ", Adresse: " << &q << endl;
  
  //Oppgave b
  *p = 7;      //i = 7
  *q += 4;     //j += 4
  *q = *p + 1; //j = 7 + 1 = 8
  p = q;       //p = q = 8
  cout << *p << " " << *q << endl; //8 8
}

/* Oppgave a)
 * Eksempel ved kjøring:
i: Verdi: 3, Adresse: 0x7fff337f9f90
j: Verdi: 5, Adresse: 0x7fff337f9f94
p: Verdi: 0x7fff337f9f90, Adresse: 0x7fff337f9f98
q: Verdi: 0x7fff337f9f94, Adresse: 0x7fff337f9fa0
 */

/* Oppgave b)
 * Utskrift:
 8 8
 */