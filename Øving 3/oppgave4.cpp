#include <iostream>


using namespace std;

int main() {
  /*
   * Oppgave a
   */
  string ord1;
  string ord2;
  string ord3;
  
  cin >> ord1;
  cin >> ord2;
  cin >> ord3;
  
  /*
  * Oppgave b
  */
  string setning = ord1 + " " + ord2 + " " + ord3 + ".";
  cout << setning << endl;
  
  /*
  * Oppgave c
  */
  
  cout << "ord1 har lengde " << ord1.length() << endl;
  cout << "ord2 har lengde " << ord2.length() << endl;
  cout << "ord3 har lengde " << ord3.length() << endl;
  cout << "setning har lengde " << setning.length() << endl;
  
  /*
  * Oppgave d
  */
  string setning2 = setning;
  
  /*
  * Oppgave e
  */
  
  if (setning2.length() >= 12) {
    setning2.replace(9, 3, "xxx");
  }
  
  /*
  * Oppgave f
  */
  string begynnelsen;
  if (setning.length() >= 5) {
    begynnelsen = setning.substr(0, 5);
  }
  cout << "begynnelsen: " << begynnelsen << endl;
  
  /*
  * Oppgave g
  */
  if (setning.find("hallo") != string::npos) {
    cout << "Fant ordet hallo" << endl;
  } else {
    cout << "Fant ikke ordet hallo" << endl;
  }
  
  /*
  * Oppgave h
  */
  int antall = 0;
  for (int i = 0; i < setning.length(); i++) {
    if (setning.substr(i, 2) == "er") {
      antall++;
    }
  }
  cout << "Det er " << antall << " forekomster av er i setning" << endl;
}