/*************************************************************************
                    GraphGenerator  -  Génère un fichier GraphViz
                             -------------------
    début                : 13/01/2026
    copyright            : (C) 2026 par Équipe TP
*************************************************************************/

//------ Interface de la classe <GraphGenerator> (fichier GraphGenerator.h) -
#if ! defined ( GRAPHGENERATOR_H )
#define GRAPHGENERATOR_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include <map>
#include <set>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef pair<string, string> Transition;

//------------------------------------------------------------------------
// Rôle de la classe <GraphGenerator>
// Génère un fichier GraphViz (.dot) représentant le graphe de navigation
// des utilisateurs entre les pages web.
//------------------------------------------------------------------------

class GraphGenerator
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool GenerateGraph(const string & filename);
    // Mode d'emploi :
    // Génère le fichier .dot avec le graphe
    // Retourne true si le fichier a été créé avec succès, false sinon
    // Contrat : filename doit être un chemin valide et accessible en écriture
    
    void AddTransition(const string & source, const string & dest, int count);
    // Mode d'emploi :
    // Ajoute une transition au graphe avec son nombre d'occurrences
    // Contrat : count doit être > 0

//-------------------------------------------- Constructeurs - destructeur
    GraphGenerator();
    // Mode d'emploi :
    // Constructeur par défaut
    // Contrat : Aucun

    virtual ~GraphGenerator();
    // Mode d'emploi :
    // Destructeur
    // Contrat : Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    string EscapeQuotes(const string & str) const;
    // Mode d'emploi :
    // Échappe les guillemets dans une chaîne pour le format DOT
    // Contrat : Aucun

//----------------------------------------------------- Attributs protégés
    map<Transition, int> transitions;
    set<string> nodes;
};

//-------------------------- Autres définitions dépendantes de <GraphGenerator>

#endif // GRAPHGENERATOR_H
