/*************************************************************************
                           Analyzer  -  Analyse les logs et génère les stats
                             -------------------
    début                : 13/01/2026
    copyright            : (C) 2026 par Équipe TP
*************************************************************************/

//---------- Interface de la classe <Analyzer> (fichier Analyzer.h) -------
#if ! defined ( ANALYZER_H )
#define ANALYZER_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include <map>
#include <vector>
#include "LogEntry.h"
#include "Document.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef pair<string, string> Transition;

//------------------------------------------------------------------------
// Rôle de la classe <Analyzer>
// Analyse une liste de logs pour :
// - Calculer le top des documents les plus consultés
// - Identifier les transitions entre pages (referer -> url)
// - Appliquer des filtres (heure, ressources statiques)
//------------------------------------------------------------------------

class Analyzer
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Analyze(const vector<LogEntry> & entries);
    // Mode d'emploi :
    // Analyse la liste d'entrées de log et construit les statistiques
    // en appliquant les filtres configurés
    // Contrat : Aucun
    
    vector<Document*> GetTopDocuments(int n) const;
    // Mode d'emploi :
    // Retourne les n documents les plus consultés
    // Contrat : n doit être positif
    
    const map<Transition, int>& GetTransitions() const;
    // Mode d'emploi :
    // Retourne la map des transitions (source, dest) -> compteur
    // Contrat : Aucun
    
    void SetExcludeStatic(bool exclude);
    // Mode d'emploi :
    // Active/désactive l'exclusion des ressources statiques
    // Contrat : Aucun
    
    void SetHourFilter(int h);
    // Mode d'emploi :
    // Définit le filtre d'heure (0-23, -1 pour désactiver)
    // Contrat : h doit être entre -1 et 23
    
    void SetBaseURL(const string & base);
    // Mode d'emploi :
    // Définit l'URL de base pour détecter les referers locaux
    // Contrat : Aucun

//-------------------------------------------- Constructeurs - destructeur
    Analyzer();
    // Mode d'emploi :
    // Constructeur par défaut
    // Contrat : Aucun

    virtual ~Analyzer();
    // Mode d'emploi :
    // Destructeur - libère la mémoire des documents
    // Contrat : Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    bool ShouldIncludeEntry(const LogEntry & entry) const;
    // Mode d'emploi :
    // Détermine si une entrée doit être incluse selon les filtres
    // Contrat : Aucun
    
    bool IsLocalReferer(const string & referer) const;
    // Mode d'emploi :
    // Vérifie si le referer provient du site local
    // Contrat : Aucun

//----------------------------------------------------- Attributs protégés
    map<string, Document*> documents;
    map<Transition, int> transitions;
    bool excludeStatic;
    int hourFilter;
    string baseURL;
};

//-------------------------------- Autres définitions dépendantes de <Analyzer>

#endif // ANALYZER_H
