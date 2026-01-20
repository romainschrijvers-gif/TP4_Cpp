/*************************************************************************
                           LogParser  -  Parse les fichiers de logs Apache
                             -------------------
    début                : 13/01/2026
    copyright            : (C) 2026 par Équipe TP
*************************************************************************/

//---------- Interface de la classe <LogParser> (fichier LogParser.h) -----
#if ! defined ( LOGPARSER_H )
#define LOGPARSER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>
#include "LogEntry.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogParser>
// Parse un fichier de logs Apache et crée une liste d'objets LogEntry.
// Gère les erreurs de parsing et ignore les lignes mal formées.
//------------------------------------------------------------------------

class LogParser
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool ParseFile(const string & filename);
    // Mode d'emploi :
    // Parse le fichier de logs spécifié et remplit la liste d'entrées
    // Retourne true si le fichier a pu être ouvert, false sinon
    // Contrat : Le fichier doit exister et être accessible en lecture
    
    const vector<LogEntry>& GetEntries() const;
    // Mode d'emploi :
    // Retourne la liste des entrées de log parsées
    // Contrat : ParseFile doit avoir été appelé au préalable

//-------------------------------------------- Constructeurs - destructeur
    LogParser();
    // Mode d'emploi :
    // Constructeur par défaut
    // Contrat : Aucun

    virtual ~LogParser();
    // Mode d'emploi :
    // Destructeur
    // Contrat : Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    LogEntry* ParseLine(const string & line);
    // Mode d'emploi :
    // Parse une ligne de log et retourne un LogEntry alloué dynamiquement
    // Retourne nullptr si la ligne est mal formée
    // Contrat : La ligne doit être au format Apache Combined Log

//----------------------------------------------------- Attributs protégés
    vector<LogEntry> logEntries;
};

//-------------------------------- Autres définitions dépendantes de <LogParser>

#endif // LOGPARSER_H
