const double pi = 3.141592;

class Sirkel {
  public:
    Sirkel(double startRadius);
    double finnAreal() const;
    double finnOmkrets() const;
  private:
    double radius;
};

Sirkel::Sirkel(double startRadius) : radius(startRadius) {}

double Sirkel::finnAreal() const {
  double areal = pi * radius * radius;
  return areal;
}

double Sirkel::finnOmkrets() const {
  double omkrets = 2.0 * pi * radius;
  return omkrets;
}