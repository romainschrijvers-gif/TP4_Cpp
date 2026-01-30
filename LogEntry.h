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
    std::string GetIP() const;
    // Mode d'emploi :
    // Retourne l'adresse IP du client
    // Contrat : Aucun
    
    DateTime GetDateTime() const;
    // Mode d'emploi :
    // Retourne l'objet DateTime de la requête
    // Contrat : Aucun
    
    std::string GetMethod() const;
    // Mode d'emploi :
    // Retourne la méthode HTTP (GET, POST, etc.)
    // Contrat : Aucun
    
    std::string GetURL() const;
    // Mode d'emploi :
    // Retourne l'URL demandée
    // Contrat : Aucun
    
    std::string GetProtocol() const;
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
    
    std::string GetReferer() const;
    // Mode d'emploi :
    // Retourne l'URL de provenance (referer)
    // Contrat : Aucun
    
    std::string GetUserAgent() const;
    // Mode d'emploi :
    // Retourne le User Agent
    // Contrat : Aucun
    
    bool IsStaticResource() const;
    // Mode d'emploi :
    // Détermine si l'URL pointe vers une ressource statique
    // (image, CSS, JS, etc.)
    // Contrat : Aucun

//-------------------------------------------- Constructeurs - destructeur
    LogEntry(const std::string & ipAddr, const DateTime & dt, 
             const std::string & meth, const std::string & url,
             const std::string & proto, int code, int sz,
             const std::string & ref, const std::string & ua);
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
    std::string ip;
    DateTime dateTime;
    std::string method;
    std::string url;
    std::string protocol;
    int statusCode;
    int size;
    std::string referer;
    std::string userAgent;
};

//-------------------------------- Autres définitions dépendantes de <LogEntry>

#endif // LOGENTRY_H
