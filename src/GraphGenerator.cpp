/*************************************************************************
                    GraphGenerator  -  Génère un fichier GraphViz
                             -------------------
    début                : 13/01/2026
    copyright            : (C) 2026 par Équipe TP
*************************************************************************/

//---- Réalisation de la classe <GraphGenerator> (fichier GraphGenerator.cpp) -

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "GraphGenerator.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool GraphGenerator::GenerateGraph(const std::string & filename)
// Algorithme :
// 1. Ouvrir le fichier en écriture
// 2. Écrire l'en-tête "digraph {"
// 3. Écrire tous les nœuds
// 4. Écrire toutes les transitions avec labels
// 5. Fermer avec "}"
{
    ofstream file(filename.c_str());
    if (!file.is_open()) {
        cerr << "Erreur : impossible de créer le fichier '" << filename << "'" << endl;
        return false;
    }
    
    file << "digraph {" << endl;
    
    // Écrire les nœuds
    for (const string& node : nodes) {
        file << "\"" << EscapeQuotes(node) << "\";" << endl;
    }
    
    // Écrire les transitions
    for (const auto& trans : transitions) {
        const string& source = trans.first.first;
        const string& dest = trans.first.second;
        int count = trans.second;
        
        file << "\"" << EscapeQuotes(source) << "\" -> \"" 
             << EscapeQuotes(dest) << "\" [label=\"" << count << "\"];" << endl;
    }
    
    file << "}" << endl;
    
    file.close();
    return true;
} //----- Fin de GenerateGraph

void GraphGenerator::AddTransition(const string & source, 
                                    const string & dest, int count)
// Algorithme :
// Ajoute la transition et enregistre les nœuds source et destination
{
    transitions[Transition(source, dest)] = count;
    nodes.insert(source);
    nodes.insert(dest);
} //----- Fin de AddTransition

//-------------------------------------------- Constructeurs - destructeur
GraphGenerator::GraphGenerator()
    : transitions(), nodes()
// Algorithme : Initialisation par défaut
{
#ifdef MAP
    cout << "Appel au constructeur de <GraphGenerator>" << endl;
#endif
} //----- Fin de GraphGenerator

GraphGenerator::~GraphGenerator()
// Algorithme : Aucune ressource dynamique à libérer
{
#ifdef MAP
    cout << "Appel au destructeur de <GraphGenerator>" << endl;
#endif
} //----- Fin de ~GraphGenerator

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
std::string GraphGenerator::EscapeQuotes(const string & str) const
// Algorithme :
// Remplace les guillemets par des guillemets échappés
{
    string result;
    for (char c : str) {
        if (c == '"') {
            result += "\\\"";
        } else {
            result += c;
        }
    }
    return result;
} //----- Fin de EscapeQuotes
