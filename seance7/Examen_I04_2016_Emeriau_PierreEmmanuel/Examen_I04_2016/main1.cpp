#include "Carre1.hpp"
#include <iostream>

int main()
{
  int i,j;
  // Partie 1 de l'examen

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

}
