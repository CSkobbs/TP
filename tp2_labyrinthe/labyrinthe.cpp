#include "labyrinthe.h"

// Construit un labyrinthe sur la base du nom de fichier
// appelle directement le constructeur de la classe m�re
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
    // La m�me chose avec des accesseurs et une boucle for in (selon votre pr�f�rence)
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

