#include "fraction.hpp"


/*QUESTION 1_1 sur la definition de classe :*/

/*Def des constructeurs : */
Fraction::Fraction(){
  numerateur = 0;
  denominateur = 1;
}

Fraction::Fraction(int n, int d){
  numerateur = n;
  if (d == 0){
    cout << "Le denominateur ne doit pas etre nul" << "\n";
    denominateur = 1;}
  else
    denominateur = d;
}

Fraction::Fraction(int n){
  numerateur = n;
  denominateur = 1;
}


/* Def des fonctions : */
int Fraction::num(){
  return numerateur;
}

int Fraction::denom(){
  return denominateur;
}

int Fraction::signe(){
  if( (numerateur >= 0 and denominateur >0) or (numerateur <= 0 and denominateur <0) )
    return 1;
  else
    return -1;
}

/*QUESTION 1_2*/
/*Fraction Fraction::operator *(Fraction &f){
  return Fraction (num()*f.num(),denom()*f.denom() );
  }*/
Fraction operator *(Fraction &f, Fraction &g){
  return Fraction(f.num()*g.num(), f.denom()*g.denom());
}

Fraction operator +(Fraction &f, Fraction &g){
  return Fraction(f.num()*g.denom() + f.denom()*g.num() , f.denom()*g.denom() );
}

Fraction operator -(Fraction &f, Fraction &g){
  return Fraction(f.num()*g.denom() - f.denom()*g.num() , f.denom()*g.denom() );
}

Fraction operator -(Fraction &f){
  return Fraction(-f.num(), f.denom());
}

Fraction operator /(Fraction &f, Fraction &g){
  return Fraction(f.num()*g.denom(), f.denom()*g.num() );
}

std::ostream & operator <<(std::ostream &os, Fraction &f){
  return os << f.num() << "/" << f.denom();
}

/*QUESTION 1_3*/
int pgcd(int a, int b){
  if (b == a)
    return a;
  else if (b < a)
    return b ?  pgcd(b,a%b) : a;
  else
    return a ?  pgcd(a,b%a) : b;
}

void Fraction::Reduction(){
  int p = pgcd(numerateur, denominateur);
  numerateur = numerateur/p;
  denominateur = denominateur/p;
}

float Fraction::ffloat(){
  return 1.0*numerateur/denominateur;
}



int main(int argc, char **argv){
  Fraction f;
  Fraction g(2);
  int num1 = atoi(argv[1]);
  int denom1 = atoi(argv[2]);
  int num2 = atoi(argv[3]);
  int denom2 = atoi(argv[4]);
  Fraction h1(num1,denom1);
  Fraction h2(num2,denom2);
  Fraction p1 = h1*h2;
  Fraction p2 = h1+h2;
  Fraction p3 = h1 - h2;
  Fraction p4 = h1/h2;

  cout << "f egale : " << f.num() << "/" << f.denom() << " de signe : " << f.signe() << "\n" ;
  cout << "g egale : " << g.num() << "/" << g.denom() << " de signe : " << g.signe() << "\n" ;
  cout << "h1 egale : " << h1.num() << "/" << h1.denom() << " de signe : " << h1.signe() << "\n" ;
  cout << "h2 egale : " << h2.num() << "/" << h2.denom() << " de signe : " << h2.signe() << "\n" ;
  cout << "L'opposée de h2 est : " << h2.num() << "/" << h2.denom() << " de signe : " << -h2.signe() << "\n";
  cout << "Le produit de h1 et de h2 vaut : " << p1.num() << "/" << p1.denom() << " de signe : " << p1.signe() << "\n";
  cout << "La somme de h1 et de h2 vaut : " << p2.num() << "/" << p2.denom() << " de signe : " << p2.signe() << "\n";
  cout << "La différence de h1 et de h2 vaut : " << p3.num() << "/" << p3.denom() << " de signe : " << p3.signe() << "\n";
  cout << "La division de h1 par h2 vaut : " << p4.num() << "/" << p4.denom() << " de signe : " << p4.signe() << "\n";
  cout << "Test << " << h1 << "\n";

  h1.Reduction();

  cout << "Reduction de h1 :" << h1 << "\n";

  cout << "Evaluation flottante de h1 : " << h1.ffloat() << "\n";
  return 0;
}
