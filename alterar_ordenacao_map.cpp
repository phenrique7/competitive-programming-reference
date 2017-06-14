#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;

typedef pair<string, int> psi;

struct compare{
   bool operator()(const string &a, const string &b) const{
      return a > b;
   }
};

map<string, int, compare> mp;
map<string, int, compare>::iterator it;

int main()
{    
   mp.insert(psi("alonso", 1));
   mp.insert(psi("abraao", -2));
   mp.insert(psi("pedro", 7));
   mp.insert(psi("soares", -5));
   mp.insert(psi("hidelbrando", 5));
   mp.insert(psi("caio", 3));   

   for(it = mp.begin(); it != mp.end(); it++){
      cout << it->first << ' ' << it->second << endl;
   }

   return 0;
}
