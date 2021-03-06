#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>

#include "arete.h"

#ifndef INFINI
#define INFINI 1000.0
#endif

Arete::Arete()
	:m_s1(0),m_s2(0),m_poids(0)
{}
Arete::Arete(int a, int b, int c)
	:m_s1(a),m_s2(b),m_poids(c)
{}
Arete::~Arete()
{}



void remplissage_matrice(std::string nom_fichier,int ** matrix)
{
	int lg,cols;
	std::ifstream fic(nom_fichier.c_str());
    if ( !fic.is_open() )
        throw "Probleme ouverture fichier !";
	
	if ( fic.good())
    {
        fic >> lg >> cols;
    	for(int i = 0; i < lg; ++i) {
    	    matrix[i] = new int[cols];
    	    for(int j = 0; j < cols; ++j) {
    	        fic >> matrix[i][j];
    	    }
    	}
    }
}

void remplissage_graphe(std::string nom_fichier, std::vector<Arete> & graphe){
	int ordre,nb_aretes, tmp1, tmp2, tmp3;
	std::ifstream fic(nom_fichier.c_str());
    if ( !fic.is_open() )
        throw "Probleme ouverture fichier !";
    /// Construction du vecteur d'aretes
    // std::vector<Arete> arete;
    if ( fic.good())
    {
        fic >> ordre >> nb_aretes;
        for (int i = 0; i < nb_aretes; ++i)
        {
            Arete t;
            tmp1 = 0, tmp2 = 0, tmp3 = 0;
            fic >> tmp1 >> tmp2 >> tmp3 ;
            graphe.push_back(Arete(tmp1,tmp2,tmp3));
        }
    }
    
}

// A FAIRE : FINIR IMPLEMENTER LE GRAPHE AVEC LA LISTE DES ARETES
// COMMUNIQUER LE GRAPHE REMPLI DANS ALGO DE PRIM


void prim(int ** adjacencePoids, int ordre, std::vector<Arete> & arbre, std::vector<Arete> & graphe){
	
	int indiceA = 0;
	std::vector<int> marques;
	int s,ymin;
	int min;


	for (int i = 0; i < ordre; ++i)
	{
		marques.push_back(0);
	}
	// on choisit arbitrairement le sommet 0 mais fonctionne avec n'importe quel autre sommet
	s = 0;

	marques[s] = 1;


	while(indiceA<ordre-1){
		min = INFINI;

		for (int x = 0; x < ordre; ++x)
		{
			if (marques[x] == 1)
			{
				for (int y = 0; y < ordre; ++y)
				{
					if (adjacencePoids[x][y] && marques[y] == 0 && adjacencePoids[x][y]<min)
					{
						min = adjacencePoids[x][y];
						ymin = y;
					}
				}
			}
		}
		marques[ymin]=1;
		arbre.push_back(graphe[ymin]);
		indiceA++;
	}
}

int main(int argc, char const *argv[])
{
	int ** mat;
	std::vector<Arete> Graphe;
	std::vector<Arete> Prim;
	remplissage_graphe("liste_aretes.txt",Graphe);
	remplissage_matrice("mat.txt", mat);
	prim(mat,9,Prim,Graphe);

	std::cout << "Arbre couvrant de poids minimum avec Prim" << std::endl;
	for (int i = 0; i < Prim.size(); ++i)
	{
		std::cout << Prim[i].m_s1 << " " << Prim[i].m_s2  <<  std::endl;
	}

	return 0;
}


