template <class type, class type2>
class Par {
public:
  type forste;
  type2 andre;
  Par(type f, type2 a) {
    forste = f;
    andre = a;
  }
  
  Par operator+(const Par &denAndre) {
    Par par = *this;
    par.forste += denAndre.forste;
    par.andre += denAndre.andre;
    return par;
  }
  
  bool operator>(const Par &denAndre) {
    return (sammenlikn(denAndre) == 1) ? true : false;
  }
  
  int sammenlikn(const Par &denAndre) {
    type sumDenne = forste + andre;
    type sumDenAndre = denAndre.forste + denAndre.andre;
    type forskjell = sumDenne - sumDenAndre;
    
    if (forskjell > 0) {
      return 1;
    } else if (forskjell == 0) {
      return 0;
    }
    return -1;
  }
};