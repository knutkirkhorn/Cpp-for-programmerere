#include <iostream>

using namespace std;

int main() {
  double tall = 1.1;
  double *peker = &tall;
  double &referanse = tall;
  
  //Måte 1:
  cout << tall << endl;
  
  //Måte 2:
  cout << *peker << endl;
  
  //Måte 3:
  cout << referanse << endl;
}