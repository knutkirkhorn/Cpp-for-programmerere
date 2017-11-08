#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<double> tabell = {1.1, 16.2, 2.4, 2.0, 22.8};
  
  tabell.emplace(tabell.begin() + 1, 2.2);
  
  cout << "front: " << tabell.front() << endl;
  cout << "back: " << tabell.back() << endl;
  
  // Leter etter et tall som eksisterer i tabellen
  vector<double>::iterator it = find(tabell.begin(), tabell.end(), 2.4);
  
  if (it != tabell.end()) {
    cout << "Tallet " << *it << " ble funnet" << endl;    
  } else {
    cout << "Tallet 2.4 ble ikke funnet" << endl;
  }
  
  // Leter etter et tall som ikke eksisterer i tabellen
  it = find(tabell.begin(), tabell.end(), 2.5);
  if (it != tabell.end()) {
    cout << "Tallet" << *it << " ble funnet" << endl;    
  } else {
    cout << "Tallet 2.5 ble ikke funnet" << endl;
  }
}