#include "Carre5.hpp"
#include <iostream>
#include <algorithm>
#include <random>

int main()
{
  int i,j;

  // Partie 1 de l'examen 
  Carre<int> Ci0;
  Carre<float> Cf0;
  Carre<double> Cd0;

  std::cout << "Test Ci0 Carre<int>\n";
  std::cout << Ci0;

  std::cout << "Test Cf0 Carre<float>\n";
  std::cout << Cf0;

  std::cout << "Test Cd0 Carre<double>\n";
  std::cout << Cd0;

  Carre<int> Ci1(5);
  std::cout << "Test Ci1 Carre<int> de taille " <<Ci1.taille()<<"\n";
  std::cout << Ci1;

  Carre<float> Cf1(6);
  std::cout << "Test Cf1 Carre<float>de taille "  <<Cf1.taille()<<"\n";
  std::cout << Cf1;

  Carre<double> Cd1(7);
  std::cout << "Test Cd1 Carre<double> de taille "  <<Cd1.taille()<<"\n";
  std::cout << Cd1;

  // Partie 2 de l'examen

  std::default_random_engine dre;
  std::uniform_int_distribution<int> ddi(0,1);


  for (i=0;i<Ci1.taille();i++)
    for (j=0;j<Ci1.taille();j++)
      {
	Ci1.put(i,j,ddi(dre));
      }
  std::cout << "Test Ci1 random int\n";
  std::cout << Ci1;


  std::uniform_real_distribution<float> ddf(0,1);

  for (i=0;i<Cf1.taille();i++)
    for (j=0;j<Cf1.taille();j++)
      Cf1.put(i,j,ddf(dre));
  std::cout << "Test Cf1 random float\n";
  std::cout << Cf1;

  std::uniform_real_distribution<double> ddd(0,1);

  for (i=0;i<Cd1.taille();i++)
    for (j=0;j<Cd1.taille();j++)
      Cd1.put(i,j,ddd(dre));
  std::cout << "Test Cd1 random double\n";
  std::cout << Cd1;
  
  // again 

  Carre<int> Ci2(Ci1);
  Carre<float> Cf2(Cf1);
  Carre<double> Cd2(Cd1);

  for (i=0;i<Ci2.taille();i++)
    for (j=0;j<Ci2.taille();j++)
      {
	Ci2.put(i,j,ddi(dre));
      }
  std::cout << "Test Ci2 random int\n";
  std::cout << Ci2;

  for (i=0;i<Cf2.taille();i++)
    for (j=0;j<Cf2.taille();j++)
      Cf2.put(i,j,ddf(dre));
  std::cout << "Test Cf2 random float\n";
  std::cout << Cf2;

  for (i=0;i<Cd2.taille();i++)
    for (j=0;j<Cd2.taille();j++)
      Cd2.put(i,j,ddd(dre));
  std::cout << "Test Cd2 random double\n";
  std::cout << Cd2;



  auto Ci2a = Ci2;
  auto Cf2a = Cf2;
  auto Cd2a = Cd2;

  std::cout << "Opérateur assignation\n";
  std::cout << "int auto Ci2a = Ci2; \n" <<Ci2a;
  std::cout << "float auto Cf2a = Cf2; \n" <<Cf2a;
  std::cout << "double  auto Cd2a = Cd2;\n" <<Cd2a;

  std::cout << "Test constructeur par recopie\n";
  auto Ci2b(Ci2);
  std::cout << "Entier auto Ci2b(Ci2);  \n"<< Ci2b;
  auto Cf2b(Cf2);
  std::cout << "Float auto Cf2b(Cf2); \n"<<Cf2b;
  auto Cd2b(Cd2);
  std::cout << "Double auto Cd2b(Cd2);\n"<<Cd2b;

  // partie 3 de l'examen

  std::cout << " Test des operateurs arithmétiques\n";

  Carre<int> Ci3(Ci1);
  Carre<float> Cf3(Cf1);
  Carre<double> Cd3(Cd1);


  auto Ci4=Ci1+Ci2;
  std::cout << "Ci4 = Ci1 + Ci2\n";
  std::cout << Ci4;
  auto Ci5=Ci1-Ci2;
  std::cout << "Ci5 = Ci1 - Ci2\n";
  std::cout << Ci5;
  auto Ci6=Ci1*Ci2;
  std::cout << "Ci6 = Ci1 * Ci2\n";
  std::cout << Ci6;

  auto Cf4=Cf1+Cf2;
  std::cout << "Cf4 = Cf1 + Cf2\n";
  std::cout << Cf4;
  auto Cf5=Cf1-Cf2;
  std::cout << "Cf5 = Cf1 - Cf2\n";
  std::cout << Cf5;
  auto Cf6=Cf1*Cf2;
  std::cout << "Cf6 = Cf1 * Cf2\n";
  std::cout << Cf6;

  auto Cd4=Cd1+Cd2;
  std::cout << "Cd4 = Cd1 + Cd2\n";
  std::cout << Cd4;
  auto Cd5=Cd1-Cd2;
  std::cout << "Cd5 = Cd1 - Cd2\n";
  std::cout << Cd5;
  auto Cd6=Cd1*Cd2;
  std::cout << "Cd6 = Cd1 * Cd2\n";
  std::cout << Cd6;

  // Partie 4 cd l'examen 

  auto Ci4a(Ci4);
  auto Cf6a(Cf6);
  auto Cd6a(Cd6);

  std::cout << "Test moyenne miroir\n";
  Ci4a.moyenne("miroir");
  std::cout << Ci4a;
  Cf6a.moyenne("miroir");
  std::cout << Cf6a;
  Cd6a.moyenne("miroir");
  std::cout << Cd6a;

  auto Ci4b(Ci4);
  auto Cf6b(Cf6);
  auto Cd6b(Cd6);

  std::cout << "Test moyenne tore\n";
  Ci4b.moyenne("miroir");
  std::cout << Ci4b;
  Cf6b.moyenne("miroir");
  std::cout << Cf6b;
  Cd6b.moyenne("miroir");
  std::cout << Cd6b;

  // Partie 5 de l'examen

  std::cout << "Test mutiplication par un T\n";
  
  auto Ci7 = 3 * Ci4;

  std::cout << " Ci7 = 3 * Ci4\n";
  std::cout << Ci7;

  auto Ci8 = Ci4 * 3;

  std::cout << " Ci8 = Ci4 * 3\n";
  std::cout << Ci8;

  

}
