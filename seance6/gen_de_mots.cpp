#include <vector>
#include <iostream>
#include <string>
#include <map>

using std::string;
using std::cout;
using std::vector;
using std::endl;
using std::map;
using std::multimap;

int main(int argc, char * argv[]){

  vector <string> generateur; //contient le mot a afficher
  vector <char> caractere; //contient tous les caracteres de la chaine initiale
  map <int, char> collection; //contient les caracteres ainsi que leur position dans la chaine de caractere
  multimap <int, int> speciaux; //contient la position des caracteres speciaux avec 1 == {, 2 == }, 3 == (, 4 == ), 5 == -, 6 == [, 7 == ]
  string mot = argv[1];
  string chaine;

  int i = 0;

  //cout << mot << " de taille " << mot.size() << endl;

  for(char &c : mot){
    caractere.push_back(c);
    //cout << caractere[i] << endl;
    collection[i] = c;
    //cout << collection[i] << endl;
    i += 1;
  }
  i = 0;

  for(auto &t : collection){
    if(t.second == '{'){
      speciaux.insert(std::pair<int,int>(1,t.first));
    }
    if(t.second == '}'){
       speciaux.insert(std::pair<int,int>(2,t.first));
    }
    if(t.second == '('){
       speciaux.insert(std::pair<int,int>(3,t.first));
    }
    if(t.second == ')'){
      speciaux.insert(std::pair<int,int>(4,t.first));
    }
    if(t.second == '-'){
      speciaux.insert(std::pair<int,int>(5,t.first));
    }
    if(t.second == '['){
      speciaux.insert(std::pair<int,int>(6,t.first));
    }
    if(t.second == ']'){
      speciaux.insert(std::pair<int,int>(7,t.first));
    }
  }

  for(auto &t : speciaux){
    cout << "type : " << t.first << " position : " << t.second  << endl;
    cout << "caractere : " << caractere[t.second] << endl;
  }

  auto p1 = speciaux.find(3);
  auto p2 = speciaux.find(4);
  cout << p2->second << endl;
  cout << p1->second << endl;
  cout << p2->second - p1->second << endl;
  if(p2->second-p1->second == 2){
    int repetition = (p2->second + p1->second)/2;
    i = p2->second;
    while(caractere[i] != ';'){
      i += 1;
    }
    for(int k=1; k<=repetition; k++){
      for(int j=p2->second; j=i; j++){
        chaine += caractere[j];
      }
    }
  }
  cout << chaine << endl;

}

