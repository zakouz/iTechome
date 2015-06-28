#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

const int NB_NOEUD_MAX = 100;

vector <int> voisin[NB_NOEUD_MAX + 1];
bool dejaVu[NB_NOEUD_MAX + 1];

void initialiserGraphe(void)
{
   // Initialisation (à la main) de l'arbre donné comme premier exemple
   
   voisin[1].push_back(2);
   voisin[1].push_back(7);

   voisin[2].push_back(3);
   voisin[2].push_back(4);

   voisin[4].push_back(5);
   voisin[4].push_back(6);

   voisin[7].push_back(8);
   
   voisin[8].push_back(9);
   voisin[8].push_back(10);
}

void DFS(int depart)
{
   stack <int> pile;
   int actuel;
   int iVoisin;

   pile.push(depart);

   while( !pile.empty() ) {
      actuel = pile.top();
      pile.pop();

      if( dejaVu[actuel] )
         continue;
      dejaVu[actuel] = true;

      printf("%d\n", actuel);

      for( iVoisin = 0; iVoisin < voisin[actuel].size(); ++iVoisin )
         pile.push(voisin[actuel][iVoisin]);
   }
}

int main(void)
{
   initialiserGraphe();
   DFS(1);

   return 0;
}
