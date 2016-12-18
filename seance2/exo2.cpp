#include <iostream>
#include <vector>

/*Declaration des fonctions utilisees*/
using std::vector;
using std::cout;

vector<int> pair(int i_ini,int i_fin)
{
  /*Declaration des variables*/
  int i;
  int somme_pair = 0, somme_cimpair = 0;
  vector<int> R(2);

  /*Test sur la valeur initiale de la boucle*/
  if((i_ini%2)!=0)
    i_ini++;

  /*Boucle pour calculer la somme des entiers pairs et des carrés des impairs*/
  for(i = i_ini; i <=  i_fin; i++)
    {
      somme_pair += i++;
      somme_cimpair += i*i;
      cout<<"\n Pair"<<somme_pair<<"\n Impair"<<somme_cimpair<<std::endl;
    }
  R[0] = somme_pair;
  R[1] = somme_cimpair;
  return R;
}



int main()
{
  vector<int> sortie = pair(0,9);
  cout << "Somme des entiers pairs : \n" << sortie[0] << "\n Somme des carrés des entiers impairs : \n" << sortie[1] << "\n";
}



