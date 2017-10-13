#include <iostream>

using namespace std;

int main() {
  double tall = 1.1;
  double *peker = &tall;
  double &referanse = tall;
  
  double tilordnet = 0.1;
  
  //Måte 1
  tilordnet = tall;
  cout << tilordnet << endl;
  
  //Måte 2
  tilordnet = *peker;
  cout << tilordnet << endl;
  
  //Måte 3
  tilordnet = referanse;
  cout << tilordnet << endl;
}