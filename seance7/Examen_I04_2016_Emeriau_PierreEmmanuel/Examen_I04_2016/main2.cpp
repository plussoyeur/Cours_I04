#include "Carre2.hpp"
#include <iostream>
#include <algorithm>
#include <random>

int main()
{
  int i,j;
  Carre<int> Ci0;
  Carre<float> Cf0;
  Carre<double> Cd0;

  std::cout << "Test Carre<int>\n";
  std::cout << Ci0;

  std::cout << "Test Carre<float>\n";
  std::cout << Cf0;

  std::cout << "Test Carre<double>\n";
  std::cout << Cd0;

  Carre<int> Ci1(5);
  std::cout << "Test Carre<int> de taille 5\n";
  std::cout << Ci1;

  Carre<float> Cf1(6);
  std::cout << "Test Carre<float>de taille  6\n";
  std::cout << Cf1;

  Carre<double> Cd1(7);
  std::cout << "Test Carre<double> de taille 7\n";
  std::cout << Cd1;

  // Partie 2 de l'examen

  std::cout << "Test fct put et taille()\n";

  std::default_random_engine dre;
  std::uniform_int_distribution<int> ddi(0,1);

  for (i=0;i<Ci1.taille();i++)
    for (j=0;j<Ci1.taille();j++)
      Ci1.put(i,j,ddi(dre));
  std::cout << "Test random int\n";
  std::cout << Ci1;


  std::uniform_real_distribution<float> ddf(0,1);

  for (i=0;i<Cf1.taille();i++)
    for (j=0;j<Cf1.taille();j++)
      Cf1.put(i,j,ddf(dre));
  std::cout << "Test random float\n";
  std::cout << Cf1;

  std::uniform_real_distribution<double> ddd(0,1);

  for (i=0;i<Cd1.taille();i++)
    for (j=0;j<Cd1.taille();j++)
      Cd1.put(i,j,ddd(dre));
  std::cout << "Test random double\n";
  std::cout << Cd1;


  auto Ci1a = Ci1;
  auto Cf1a = Cf1;
  auto Cd1a = Cd1;

  std::cout << "Opérateur assignation\n";
  std::cout << "int\n" <<Ci1a;
  std::cout << "float\n" <<Cf1a;
  std::cout << "double\n" <<Cd1a;

  std::cout << "Test constructeur par recopie\n";
  auto Ci2(Ci1);
  std::cout << "Entier\n"<< Ci2;
  auto Cf2(Cf1);
  std::cout << "Float\n"<<Cf2;
  auto Cd2(Cd1);
  std::cout << "Double\n"<<Cd2;

}
