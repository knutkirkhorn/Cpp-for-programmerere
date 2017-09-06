#include <fstream>
#include <iostream>

using namespace std;

void lesInnTemp(double temp[], int antall);

int main() {
  /*
   * Oppgave a
   */
  cout << "Oppgave a" << endl;
  
  const int antall = 5;
  int antallUnder = 0;
  int antallMellom = 0;
  int antallOver = 0;
  
  cout << "Du skal skrive inn 5 temperaturer." << endl;
  
  for (int i = 0; i < antall; i++) {
    double lestVerdi;
    cin >> lestVerdi;
    cout << "Temperatur nr " << (i+1) << ": " << lestVerdi << endl;
    
    if (lestVerdi < 10) {
      //Under 10 grader
      antallUnder++;
    } else if (lestVerdi > 20) {
      //Over 20 grader
      antallOver++;
    } else {
      //Mellom 10 og 20 grader
      antallMellom++;
    }
  }
  
  //Skriv ut antall temperaturer under 10
  cout << "Antall under 10 er " << antallUnder << endl;
  
  //Skriv ut antall temperaturer mellom 10 og 20
  cout << "Antall mellom 10 og 20 er " << antallMellom << endl;
  
  //Skriv ut antall temperaturer over 20
  cout << "Antall over 20 er " << antallOver << endl;
  
  
  /*
  * Oppgave b
  */
  cout << "\n\nOppgave b" << endl;
  
  int lengde = 10;
  double temp[lengde];
  lesInnTemp(temp, lengde);
  antallUnder = 0;
  antallMellom = 0;
  antallOver = 0;
  
  for (int i = 0; i < lengde; i++) {
    cout << "Temperatur nr " << (i+1) << ": " << temp[i] << endl;
    
    if (temp[i] < 10) {
      //Under 10 grader
      antallUnder++;
    } else if (temp[i] > 20) {
      //Over 20 grader
      antallOver++;
    } else {
      //Mellom 10 og 20 grader
      antallMellom++;
    }
  }
  
  //Skriv ut antall temperaturer under 10
  cout << "Antall under 10 er " << antallUnder << endl;
  
  //Skriv ut antall temperaturer mellom 10 og 20
  cout << "Antall mellom 10 og 20 er " << antallMellom << endl;
  
  //Skriv ut antall temperaturer over 20
  cout << "Antall over 20 er " << antallOver << endl;
}

void lesInnTemp(double temp[], int antall) {
  const char filnavn[] = "temperaturer.txt";
  ifstream innfil;
  innfil.open(filnavn);
  if (!innfil) {
    cout << "Feil skjedde ved åpning av fil." << endl;
    exit(EXIT_FAILURE);
  }
  
  for (int i = 0; i < antall; i++) {
    innfil >> temp[i];
  }
  
  innfil.close();
}
