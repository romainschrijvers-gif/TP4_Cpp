/*************************************************************************
                           Document  -  Représente un document web
                             -------------------
    début                : 13/01/2026
    copyright            : (C) 2026 par Équipe TP
*************************************************************************/

//---------- Interface de la classe <Document> (fichier Document.h) -------
#if ! defined ( DOCUMENT_H )
#define DOCUMENT_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Document>
// Représente un document web avec son URL et son compteur de hits.
// Permet de suivre le nombre de fois qu'un document a été consulté.
//------------------------------------------------------------------------

class Document
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    string GetURL() const;
    // Mode d'emploi :
    // Retourne l'URL du document
    // Contrat : Aucun
    
    int GetHitCount() const;
    // Mode d'emploi :
    // Retourne le nombre de hits du document
    // Contrat : Aucun
    
    void IncrementHits();
    // Mode d'emploi :
    // Incrémente le compteur de hits
    // Contrat : Aucun

//------------------------------------------------- Surcharge d'opérateurs
    bool operator<(const Document & other) const;
    // Mode d'emploi :
    // Compare deux documents selon leur nombre de hits (ordre décroissant)
    // Utile pour le tri
    // Contrat : Aucun

//-------------------------------------------- Constructeurs - destructeur
    Document(const string & urlStr);
    // Mode d'emploi :
    // Construit un document avec une URL donnée
    // Le compteur de hits est initialisé à 0
    // Contrat : Aucun

    Document();
    // Mode d'emploi :
    // Constructeur par défaut
    // Contrat : Aucun

    virtual ~Document();
    // Mode d'emploi :
    // Destructeur
    // Contrat : Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    string url;
    int hitCount;
};

//-------------------------------- Autres définitions dépendantes de <Document>

#endif // DOCUMENT_H
