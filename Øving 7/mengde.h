#ifndef MENGDE_DEFINERT
#define MENGDE_DEFINERT

#include <vector>

using namespace std;

class Mengde {
public:
  Mengde();
  Mengde(const vector<int> &startMengde);
  Mengde &operator+=(const Mengde &denAndre);
  Mengde operator+(const int tall);
  Mengde &operator=(const Mengde &nyMengde);
  void skrivUtMengde();
private:
  vector<int> mengde;
};

#endif