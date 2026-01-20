/*************************************************************************
                           LogEntry  -  Représente une ligne de log
                             -------------------
    début                : 13/01/2026
    copyright            : (C) 2026 par Équipe TP
*************************************************************************/

//---------- Interface de la classe <LogEntry> (fichier LogEntry.h) -------
#if ! defined ( LOGENTRY_H )
#define LOGENTRY_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include "DateTime.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogEntry>
// Représente une entrée de log Apache avec tous ses champs.
// Format : IP - - [Date] "Method URL Protocol" Code Size "Referer" "UserAgent"
//------------------------------------------------------------------------

class LogEntry
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    string GetIP() const;
    // Mode d'emploi :
    // Retourne l'adresse IP du client
    // Contrat : Aucun
    
    DateTime GetDateTime() const;
    // Mode d'emploi :
    // Retourne l'objet DateTime de la requête
    // Contrat : Aucun
    
    string GetMethod() const;
    // Mode d'emploi :
    // Retourne la méthode HTTP (GET, POST, etc.)
    // Contrat : Aucun
    
    string GetURL() const;
    // Mode d'emploi :
    // Retourne l'URL demandée
    // Contrat : Aucun
    
    string GetProtocol() const;
    // Mode d'emploi :
    // Retourne le protocole HTTP
    // Contrat : Aucun
    
    int GetStatusCode() const;
    // Mode d'emploi :
    // Retourne le code de retour HTTP
    // Contrat : Aucun
    
    int GetSize() const;
    // Mode d'emploi :
    // Retourne la taille de la réponse en octets
    // Contrat : Aucun
    
    string GetReferer() const;
    // Mode d'emploi :
    // Retourne l'URL de provenance (referer)
    // Contrat : Aucun
    
    string GetUserAgent() const;
    // Mode d'emploi :
    // Retourne le User Agent
    // Contrat : Aucun
    
    bool IsStaticResource() const;
    // Mode d'emploi :
    // Détermine si l'URL pointe vers une ressource statique
    // (image, CSS, JS, etc.)
    // Contrat : Aucun

//-------------------------------------------- Constructeurs - destructeur
    LogEntry(const string & ipAddr, const DateTime & dt, 
             const string & meth, const string & url,
             const string & proto, int code, int sz,
             const string & ref, const string & ua);
    // Mode d'emploi :
    // Construit une entrée de log avec tous les paramètres
    // Contrat : Aucun

    LogEntry();
    // Mode d'emploi :
    // Constructeur par défaut
    // Contrat : Aucun

    virtual ~LogEntry();
    // Mode d'emploi :
    // Destructeur
    // Contrat : Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    string ip;
    DateTime dateTime;
    string method;
    string url;
    string protocol;
    int statusCode;
    int size;
    string referer;
    string userAgent;
};

//-------------------------------- Autres définitions dépendantes de <LogEntry>

#endif // LOGENTRY_H
