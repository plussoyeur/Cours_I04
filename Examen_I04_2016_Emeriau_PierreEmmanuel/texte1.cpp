#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using std::ifstream;
using std::string;
using std::cout;
using std::vector;
using std::endl;

vector <string> lecture(string filename){
  ifstream fichier(filename);
  if(fichier)
    {
      //L'ouverture s'est bien passée, on peut donc lire

      string mot; //Une variable pour stocker les mots lues

      while(fichier >> mot) //Tant qu'on n'est pas à la fin, on lit
        {
          cout << mot << endl;
          //Et on l'affiche dans la console
          //Ou alors on fait quelque chose avec ce mot
          //À vous de voir
        }
    }
  else
    {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }

};

int main(){

  lecture("texte_93.txt");
  return 0;
}
