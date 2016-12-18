#include <iostream>
#include <stdlib.h>

/*Declaration des fonctions utilises */
using std::cout;

/*Definition de la classe*/
class Fraction{
private :
  int denominateur, numerateur;
public :
  Fraction();
  Fraction(int n, int d);
  Fraction(int n);
  int num();
  int denom();
  int signe();
  void Reduction();
  float ffloat();
  //Fraction operator *(Fraction &f);
};
