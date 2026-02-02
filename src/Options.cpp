/*************************************************************************
                           Options  -  Gestion des options CLI
                             -------------------
    début                : 13/01/2026
    copyright            : (C) 2026 par Équipe TP
*************************************************************************/

//---------- Réalisation de la classe <Options> (fichier Options.cpp) -----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstdlib>

//------------------------------------------------------ Include personnel
#include "Options.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Options::ParseCommandLine(int argc, char* argv[])
// Algorithme :
// Parse les arguments en cherchant -g, -e, -t
// Le dernier argument doit être le fichier de log
{
    if (argc < 2) {
        PrintUsage();
        return false;
    }
    
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        
        if (arg == "-g") {
            if (i + 1 >= argc) {
                cerr << "Erreur : l'option -g nécessite un argument" << endl;
                return false;
            }
            graphFile = argv[++i];
            generateGraph = true;
        }
        else if (arg == "-e") {
            excludeStatic = true;
        }
        else if (arg == "-t") {
            if (i + 1 >= argc) {
                cerr << "Erreur : l'option -t nécessite un argument" << endl;
                return false;
            }
            int hour = atoi(argv[++i]);
            if (hour < 0 || hour > 23) {
                cerr << "Erreur : l'heure doit être entre 0 et 23" << endl;
                return false;
            }
            hourFilter = hour;
        }
        else if (i == argc - 1) {
            // Dernier argument : fichier de log
            logFile = arg;
        }
        else {
            cerr << "Erreur : option inconnue '" << arg << "'" << endl;
            PrintUsage();
            return false;
        }
    }
    
    if (logFile.empty()) {
        cerr << "Erreur : aucun fichier de log spécifié" << endl;
        PrintUsage();
        return false;
    }
    
    return true;
} //----- Fin de ParseCommandLine

string Options::GetLogFile() const
// Algorithme : Retourne logFile
{
    return logFile;
} //----- Fin de GetLogFile

string Options::GetGraphFile() const
// Algorithme : Retourne graphFile
{
    return graphFile;
} //----- Fin de GetGraphFile

bool Options::IsExcludeStatic() const
// Algorithme : Retourne excludeStatic
{
    return excludeStatic;
} //----- Fin de IsExcludeStatic

int Options::GetHourFilter() const
// Algorithme : Retourne hourFilter
{
    return hourFilter;
} //----- Fin de GetHourFilter

bool Options::IsGenerateGraph() const
// Algorithme : Retourne generateGraph
{
    return generateGraph;
} //----- Fin de IsGenerateGraph

void Options::PrintUsage() const
// Algorithme : Affiche l'aide
{
    cout << "Usage : analog [options] fichier.log" << endl;
    cout << "Options :" << endl;
    cout << "  -g <fichier.dot>  Génère un fichier GraphViz" << endl;
    cout << "  -e                Exclut les ressources statiques (.jpg, .css, .js, etc.)" << endl;
    cout << "  -t <heure>        Filtre les logs sur une heure spécifique (0-23)" << endl;
    cout << endl;
    cout << "Exemples :" << endl;
    cout << "  analog anonyme.log" << endl;
    cout << "  analog -g graph.dot anonyme.log" << endl;
    cout << "  analog -e -t 11 anonyme.log" << endl;
    cout << "  analog -g graph.dot -e -t 11 anonyme.log" << endl;
} //----- Fin de PrintUsage

//-------------------------------------------- Constructeurs - destructeur
Options::Options()
    : logFile(""), graphFile(""), excludeStatic(false), 
      hourFilter(-1), generateGraph(false)
// Algorithme : Initialisation par défaut
{
#ifdef MAP
    cout << "Appel au constructeur de <Options>" << endl;
#endif
} //----- Fin de Options

Options::~Options()
// Algorithme : Aucune ressource dynamique à libérer
{
#ifdef MAP
    cout << "Appel au destructeur de <Options>" << endl;
#endif
} //----- Fin de ~Options
