/*************************************************************************
                           Document  -  Représente un document web
                             -------------------
    début                : 13/01/2026
    copyright            : (C) 2026 par Équipe TP
*************************************************************************/

//---------- Réalisation de la classe <Document> (fichier Document.cpp) ---

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Document.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
std::string Document::GetURL() const
// Algorithme : Retourne l'attribut url
{
    return url;
} //----- Fin de GetURL

int Document::GetHitCount() const
// Algorithme : Retourne l'attribut hitCount
{
    return hitCount;
} //----- Fin de GetHitCount

void Document::IncrementHits()
// Algorithme : Incrémente le compteur de hits
{
    hitCount++;
} //----- Fin de IncrementHits

//------------------------------------------------- Surcharge d'opérateurs
bool Document::operator<(const Document & other) const
// Algorithme :
// Compare les hitCount (ordre décroissant pour le tri)
{
    return hitCount > other.hitCount;
} //----- Fin de operator<

//-------------------------------------------- Constructeurs - destructeur
Document::Document(const std::string & urlStr)
    : url(urlStr), hitCount(0)
// Algorithme : Initialisation avec URL, hitCount à 0
{
#ifdef MAP
    cout << "Appel au constructeur de <Document>" << endl;
#endif
} //----- Fin de Document (constructeur avec paramètre)

Document::Document()
    : url(""), hitCount(0)
// Algorithme : Initialisation par défaut
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Document>" << endl;
#endif
} //----- Fin de Document (constructeur par défaut)

Document::~Document()
// Algorithme : Aucune ressource dynamique à libérer
{
#ifdef MAP
    cout << "Appel au destructeur de <Document>" << endl;
#endif
} //----- Fin de ~Document
