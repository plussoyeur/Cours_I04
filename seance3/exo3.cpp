# include <iostream>
# include <cmath>

/* Fonctions utilisees */
using std::cout;
using std::endl;
using std::cin;

int main()
{
  /* Declaration de variable */
  int j = 0, n = 0, n_max = 0;
  float S = 0, S_n = 0;

  cout << "Donner une valeur pour l'entier n" << endl;
  cin >> n_max;
  cout << endl;

  /* Calcul de S/S_n */
  for (n = 1; n <= n_max; n = 10*n)
    {
      S_n = .5*n*(n+1);
      S = 0;
      for (j = 1; j <= n; j++)
        {
          S += 1.0*j/S_n;
        }
      cout << "n = " << n << endl;
      cout << "Denom : " << S_n << endl;
      cout << "1/Denom : " << 1/S_n << endl;
      cout << "n/Denom : " << n/S_n << endl;
      cout << "Somme : " << S << endl;
      cout << "Pourcentage d'erreur : " << (1-S)*100 << "%" << endl;
      cout << endl;
    }

  return 0;
}
