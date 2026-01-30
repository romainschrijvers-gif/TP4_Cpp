/*************************************************************************
                           DateTime  -  Gestion de date/heure
                             -------------------
    début                : 13/01/2026
    copyright            : (C) 2026 par Équipe TP
*************************************************************************/

//---------- Interface de la classe <DateTime> (fichier DateTime.h) -------
#if ! defined ( DATETIME_H )
#define DATETIME_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DateTime>
// Représente une date et heure extraite d'un log Apache.
// Format attendu : [08/Sep/2012:11:16:02 +0200]
//------------------------------------------------------------------------

class DateTime
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    int GetHour() const;
    // Mode d'emploi :
    // Retourne l'heure (0-23)
    // Contrat : Aucun
    
    std::string ToString() const;
    // Mode d'emploi :
    // Retourne la date/heure sous forme de chaîne formatée
    // Contrat : Aucun

//-------------------------------------------- Constructeurs - destructeur
    DateTime(const std::string & dateTimeStr);
    // Mode d'emploi :
    // Construit un objet DateTime à partir d'une chaîne au format
    // [08/Sep/2012:11:16:02 +0200]
    // Contrat : La chaîne doit être au format Apache

    DateTime();
    // Mode d'emploi :
    // Constructeur par défaut
    // Contrat : Aucun

    virtual ~DateTime();
    // Mode d'emploi :
    // Destructeur
    // Contrat : Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    int day;
    std::string month;
    int year;
    int hour;
    int minute;
    int second;
    std::string timezone;
};

//-------------------------------- Autres définitions dépendantes de <DateTime>

#endif // DATETIME_H
