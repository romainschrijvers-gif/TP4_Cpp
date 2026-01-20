/*************************************************************************
                           LogEntry  -  Représente une ligne de log
                             -------------------
    début                : 13/01/2026
    copyright            : (C) 2026 par Équipe TP
*************************************************************************/

//---------- Réalisation de la classe <LogEntry> (fichier LogEntry.cpp) ---

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>

//------------------------------------------------------ Include personnel
#include "LogEntry.h"

//------------------------------------------------------------- Constantes
static const vector<string> STATIC_EXTENSIONS = {
    ".jpg", ".jpeg", ".png", ".gif", ".bmp", ".svg", ".ico", ".webp",
    ".css", ".js", ".woff", ".woff2", ".ttf", ".eot"
};

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string LogEntry::GetIP() const
// Algorithme : Retourne l'attribut ip
{
    return ip;
} //----- Fin de GetIP

DateTime LogEntry::GetDateTime() const
// Algorithme : Retourne l'attribut dateTime
{
    return dateTime;
} //----- Fin de GetDateTime

string LogEntry::GetMethod() const
// Algorithme : Retourne l'attribut method
{
    return method;
} //----- Fin de GetMethod

string LogEntry::GetURL() const
// Algorithme : Retourne l'attribut url
{
    return url;
} //----- Fin de GetURL

string LogEntry::GetProtocol() const
// Algorithme : Retourne l'attribut protocol
{
    return protocol;
} //----- Fin de GetProtocol

int LogEntry::GetStatusCode() const
// Algorithme : Retourne l'attribut statusCode
{
    return statusCode;
} //----- Fin de GetStatusCode

int LogEntry::GetSize() const
// Algorithme : Retourne l'attribut size
{
    return size;
} //----- Fin de GetSize

string LogEntry::GetReferer() const
// Algorithme : Retourne l'attribut referer
{
    return referer;
} //----- Fin de GetReferer

string LogEntry::GetUserAgent() const
// Algorithme : Retourne l'attribut userAgent
{
    return userAgent;
} //----- Fin de GetUserAgent

bool LogEntry::IsStaticResource() const
// Algorithme :
// Vérifie si l'URL se termine par une extension de ressource statique
{
    for (const auto& ext : STATIC_EXTENSIONS) {
        if (url.length() >= ext.length() &&
            url.compare(url.length() - ext.length(), ext.length(), ext) == 0) {
            return true;
        }
    }
    return false;
} //----- Fin de IsStaticResource

//-------------------------------------------- Constructeurs - destructeur
LogEntry::LogEntry(const string & ipAddr, const DateTime & dt, 
                   const string & meth, const string & urlStr,
                   const string & proto, int code, int sz,
                   const string & ref, const string & ua)
    : ip(ipAddr), dateTime(dt), method(meth), url(urlStr), protocol(proto),
      statusCode(code), size(sz), referer(ref), userAgent(ua)
// Algorithme : Initialisation par liste d'initialisation
{
#ifdef MAP
    cout << "Appel au constructeur de <LogEntry>" << endl;
#endif
} //----- Fin de LogEntry (constructeur avec paramètres)

LogEntry::LogEntry()
    : ip(""), dateTime(), method(""), url(""), protocol(""),
      statusCode(0), size(0), referer(""), userAgent("")
// Algorithme : Initialisation par défaut
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <LogEntry>" << endl;
#endif
} //----- Fin de LogEntry (constructeur par défaut)

LogEntry::~LogEntry()
// Algorithme : Aucune ressource dynamique à libérer
{
#ifdef MAP
    cout << "Appel au destructeur de <LogEntry>" << endl;
#endif
} //----- Fin de ~LogEntry
