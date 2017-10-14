//
// Vare.h
//
#ifndef VARE_DEFINERT
  #define VARE_DEFINERT
  #include <string>
  
  using namespace std;
  const double moms = 0.24; //moms er satt til 24% og ikke 25% i klientutskriften
  
  class Vare {
    public:
      Vare(string startNavn, int startVarenr, double startPris);
      string finnNavn() const;
      int finnVarenr() const;
      double finnPrisPrEnhet() const;
      void settPris(double nyPris);
      double finnPrisUtenMoms(double kvantum);
      double finnPrisMedMoms(double kvantum);
    
    private:
      string varenavn;
      int varenr;
      double pris;
  };

#endif
