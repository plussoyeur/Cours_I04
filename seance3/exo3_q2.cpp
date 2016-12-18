# include <iostream>
# include <cmath>

/* Fonctions utilisees */
using std::cout;
using std::endl;
using std::cin;

int main()
{
  /* Declaration de variable */
  int j = 0, i = 0, n = 0, n_1 = 0, n_max = 100, n_g = n_max/20;
  float S = 0, S_n = 0, S_tot = 0;

  /*cout << "Donner une valeur pour l'entier n" << endl;
  cin >> n_max;
  cout << endl;*/

  /* Calcul de S/S_n */
  for (i = 1; i <= 20; i++)
    {
      n = n_g*i;
      if ( i == 1)
        S_n = .5*n*(n+1);
      else
        n_1 = n_g*(i-1);
        S_n = .5*n*(n+1) - .5*n_1*(n_1+1);
      S = 0;
      cout << n << endl;
      for (j = n - n_g +1; j <= n; j++)
        {
          cout << j << endl;
          S += j/S_n;
          cout << S << "      " << S_n << endl;
        }
      S_tot += S;
      cout << "n = " << n << endl;
      cout << "Fraction courante : " << S << endl;
      cout << "Somme : " << S_tot << endl;
      cout << "Pourcentage d'erreur : " << (1-S_tot)*100 << "%" << endl;
      cout << endl;
    }

  return 0;
}

