#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &v) {
  for (auto &e : v) {
    os << e << " ";
  }
  return os;
}

int main() {
  vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
  cout << "v1: " << v1 << endl;
  
  vector<int> v2 = {2, 3, 12, 14, 24};
  cout << "v2: " << v2 << endl;
  
  // Oppgave a)
  cout << endl << "Oppgave a)" << endl;
  vector<int>::iterator it = find_if(v1.begin(), v1.end(), [](const int &e) {
    if (e > 15) {
      return true;
    }
    return false;
  });
  cout << "Den første verdien større enn 15 i v1 er: " << *it << endl;
  
  // Oppgave b)
  cout << endl << "Oppgave b)" << endl;
  // Likhet i intervallet [v1.begin(), v1.begin() + 5] for v1 og v2
  bool equal5 = equal(v1.begin(), v1.begin() + 5, v2.begin(), v2.begin() + 5, [](const int &e1, const int &e2) {
    if (abs(e1 - e2) <= 2) {
      return true;
    }
    return false;
  });
  
  if (equal5) {
    cout << "v1 og v2 er like i intervallet [v1.begin(), v1.begin() + 5]" << endl;
  } else {
    cout << "v1 og v2 er ulike i intervallet [v1.begin(), v1.begin() + 5]" << endl;
  }
  
  // Likhet i intervallet [v1.begin(), v1.begin() + 4] for v1 og v2
  bool equal4 = equal(v1.begin(), v1.begin() + 4, v2.begin(), v2.begin() + 4, [](const int &e1, const int &e2) {
    if (abs(e1 - e2) <= 2) {
      return true;
    }
    return false;
  });
  
  if (equal4) {
    cout << "v1 og v2 er like i intervallet [v1.begin(), v1.begin() + 4]" << endl;
  } else {
    cout << "v1 og v2 er ulike i intervallet [v1.begin(), v1.begin() + 4]" << endl;
  }
  
  // Oppgave c)
  cout << endl << "Oppgave c)" << endl;
  replace_copy_if(v1.begin(), v1.end(), v1.begin(), [](const int &e) {
    if (e % 2 == 1) {
      return true;
    }
    return false;
  }, 100);
  cout << "oddetall byttet ut med 100 i v1: " << v1 << endl;
}
