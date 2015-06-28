#include <cstdio>
#include <vector>
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

void DFS(int noeud)
{
   if( dejaVu[noeud] )
      return;
   dejaVu[noeud] = true;

   printf("%d\n", noeud);

   int iVoisin;

   for( iVoisin = 0; iVoisin < voisin[noeud].size(); ++iVoisin )
      DFS(voisin[noeud][iVoisin]);
}

int main(void)
{
   initialiserGraphe();
   DFS(1);

   return 0;
}
