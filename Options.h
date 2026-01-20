/*************************************************************************
                           Options  -  Gestion des options CLI
                             -------------------
    début                : 13/01/2026
    copyright            : (C) 2026 par Équipe TP
*************************************************************************/

//---------- Interface de la classe <Options> (fichier Options.h) ---------
#if ! defined ( OPTIONS_H )
#define OPTIONS_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Options>
// Parse et stocke les options de la ligne de commande.
// Format : analog [options] fichier.log
// Options : -g fichier.dot, -e, -t heure
//------------------------------------------------------------------------

class Options
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool ParseCommandLine(int argc, char* argv[]);
    // Mode d'emploi :
    // Parse les arguments de la ligne de commande
    // Retourne true si les arguments sont valides, false sinon
    // Contrat : argc et argv doivent provenir du main
    
    string GetLogFile() const;
    // Mode d'emploi :
    // Retourne le nom du fichier de log
    // Contrat : ParseCommandLine doit avoir été appelé avec succès
    
    string GetGraphFile() const;
    // Mode d'emploi :
    // Retourne le nom du fichier graphe (vide si non spécifié)
    // Contrat : ParseCommandLine doit avoir été appelé avec succès
    
    bool IsExcludeStatic() const;
    // Mode d'emploi :
    // Retourne true si l'option -e est active
    // Contrat : ParseCommandLine doit avoir été appelé avec succès
    
    int GetHourFilter() const;
    // Mode d'emploi :
    // Retourne l'heure de filtrage (0-23) ou -1 si non spécifié
    // Contrat : ParseCommandLine doit avoir été appelé avec succès
    
    bool IsGenerateGraph() const;
    // Mode d'emploi :
    // Retourne true si un fichier graphe doit être généré
    // Contrat : ParseCommandLine doit avoir été appelé avec succès
    
    void PrintUsage() const;
    // Mode d'emploi :
    // Affiche l'aide d'utilisation du programme
    // Contrat : Aucun

//-------------------------------------------- Constructeurs - destructeur
    Options();
    // Mode d'emploi :
    // Constructeur par défaut
    // Contrat : Aucun

    virtual ~Options();
    // Mode d'emploi :
    // Destructeur
    // Contrat : Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    string logFile;
    string graphFile;
    bool excludeStatic;
    int hourFilter;
    bool generateGraph;
};

//-------------------------------- Autres définitions dépendantes de <Options>

#endif // OPTIONS_H
