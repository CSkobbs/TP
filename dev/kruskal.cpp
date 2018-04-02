#include <vector>
#include <iostream>
#include "arete.h"

std::vector<t_arete> kruskal(std::vector<t_arete> graphe, int ordre, int s, int n){

	std::vector<t_arete> arbre;
	std::vector<int> connexe;
	int indiceA = 0, indiceG=0;
	int s1,s2;
	t_arete u;

	for (int i = 0; i < ordre -1 ; ++i)
	{
		// arbre[i] = x;
		// allocation de l'arbre des aretes
		t_arete t(0,0,0);
		arbre.push_back();
	}

	for (int i = 0; i < ordre ; ++i)
	{
		// allocation du tableau connexe
		if (graphe[i].m_s1 == )
		{
			/* code */
		}
	}

	for (int i = 0; i < ordre; ++i)
	{
		connexe.push_back(i);
	}

	for (int i = 0; i < ordre ; ++i)
	{
		// trier les n aretes du tableau connexe

	}
	sort(connexe);

	while (indiceA<ordre-1 && indiceG<n) {
		u = graphe[indiceG];
		s1 = connexe[u.m_s1];s2 = connexe[u.m_s2];

		if (s1 == s2)	
		{	
			indiceG ++;
		}
		else {
			arbre[indiceA] = u;

			indiceA++; indiceG++;

			for (int i = 0; i < ordre; ++i)
			{
				if (connexe[m_s1]==s1) connexe = s2;
			}
		}
	}
	if (indiceA<ordre-1){std::cout << "le graphe n'est pas connexe" << std::endl;}
}