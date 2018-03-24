#include "labyrinthe.h"

# include <algorithm>
# include <queue>
# include <stack>
# include <vector>

// Construit un labyrinthe sur la base du nom de fichier
// appelle directement le constructeur de la classe mère
Labyrinthe::Labyrinthe(const std::string& nom_fichier) :
    Labybase(nom_fichier)
{   }

// Exemple de parcours de tous les sommets du graphe dans l'ordre de leur indice
void Labyrinthe::affichage_donnees()
{
    std::cout << std::endl;

    std::cout << "Le labyrinthe a " << m_ordre << " sommets" << std::endl;

    std::cout << "Le sommet entree est a l'indice " << m_entree
                  << " coords" << coords(m_entree) << std::endl;

    std::cout << "Le sommet sortie est a l'indice " << m_sortie
                  << " coords" << coords(m_sortie) << std::endl;

    std::cout << std::endl << "Liste de tous les sommets : " << std::endl;
    for (int idx=0; idx<m_ordre; ++idx)
    {
        Sommet& s = m_sommets[idx];

        std::cout << "sommet indice " << idx << " coords" << coords(idx)
                    << (s.m_marque ? " X" : "  ") << (s.m_carac ? s.m_carac : ' ') << " adjacents: ";

        /// POUR REALISER LES ALGORITHMES DE PARCOURS VOUS DEVEZ BIEN COMPRENDRE CES 3 LIGNES
        for (int a=0; a<s.m_nbadjacents; ++a)
        {
            int ida = s.m_adjacents[a];
            std::cout << ida << " ";
        }

        if (s.m_nbadjacents==0)
            std::cout << "Aucun";

        std::cout << std::endl;
    }
    std::cout << std::endl;

    /**
    // La même chose avec des accesseurs et une boucle for in (selon votre préférence)
    std::cout << std::endl << "Liste de tous les sommets : " << std::endl;
    for (int idx=0; idx<get_ordre(); ++idx)
    {
        Sommet& s = get_sommet(idx);

        std::cout << "sommet indice " << idx << " coords" << coords(idx)
                    << (s.est_marque() ? " X" : "  ") << (s.get_carac() ? s.get_carac() : ' ') << " adjacents: ";

        for ( auto ida : s.get_adjacents() )
            std::cout << ida << " ";

        if ( s.get_adjacents().size()==0 )
            std::cout << "Aucun";

        std::cout << std::endl;
    }
    std::cout << std::endl;
    */

}


/// ICI VOS METHODES ...
// fonctionne comme un dfs...
void Labyrinthe::BFS(int s)
    {
        reset_marquages();
        std::queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            s = q.front();
            std::cout<<s<<" ";
            q.pop();
            for (int i = 0; i < m_sommets[s].m_adjacents.size(); ++i)
            {
                if(!m_sommets[m_sommets[s].get_adjacents()[i]].est_marque())
                {
                    m_sommets[m_sommets[s].get_adjacents()[i]].set_marque(true); ///on le marque visité
                    q.push(m_sommets[s].get_adjacents()[i]);
                }
            }    
        }
}

void Labyrinthe::DFS(int s){

    reset_marquages();
    std::stack<int> q;
    q.push(s);
    while (!q.empty())
    {
        s = q.top();
        std::cout<<s<<" ";
        q.pop();
        for (int i = 0; i < m_sommets[s].m_adjacents.size(); ++i)
        {
            if(!m_sommets[m_sommets[s].get_adjacents()[i]].est_marque())
            {
                m_sommets[m_sommets[s].get_adjacents()[i]].set_marque(true); ///on le marque visité
                q.push(m_sommets[s].get_adjacents()[i]);
            }
        }    
    }
}

void Labyrinthe::cc() 
{
    reset_marquages(); 

    char couleur = 'A';

    for (int i= 0; i< m_sommets.size(); i++)
    {
        if (m_sommets[i].get_carac() == '\0')
        {
            DFS(i);                             /// dfs pour trouver toutes les composantes possibles
                                                //  fin dfs == nouvelle couleur
            for (int j = 0; j< m_sommets.size(); j++)
            {
                if (m_sommets[j].est_marque())  
                    m_sommets[j].set_carac(couleur); 
            }
            couleur += 1;                    
            reset_marquages();                  
            std::cout << std::endl <<"new color : " << couleur << std::endl;
        }
    }


}

