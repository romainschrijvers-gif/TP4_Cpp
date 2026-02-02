/*************************************************************************
                           DateTime  -  Gestion de date/heure
                             -------------------
    début                : 13/01/2026
    copyright            : (C) 2026 par Équipe TP
*************************************************************************/

//---------- Réalisation de la classe <DateTime> (fichier DateTime.cpp) ---

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "DateTime.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int DateTime::GetHour() const
// Algorithme : Retourne simplement l'attribut hour
{
    return hour;
} //----- Fin de GetHour

string DateTime::ToString() const
// Algorithme : Formate la date/heure en chaîne
{
    ostringstream oss;
    oss << day << "/" << month << "/" << year << ":" 
        << hour << ":" << minute << ":" << second << " " << timezone;
    return oss.str();
} //----- Fin de ToString

//-------------------------------------------- Constructeurs - destructeur
DateTime::DateTime(const string & dateTimeStr)
// Algorithme :
// Parse la chaîne au format [08/Sep/2012:11:16:02 +0200]
{
#ifdef MAP
    cout << "Appel au constructeur de <DateTime>" << endl;
#endif
    
    // Extraction des valeurs depuis la chaîne
    // Format : [08/Sep/2012:11:16:02 +0200]
    size_t pos = 1; // Sauter le '['
    
    // Jour
    day = stoi(dateTimeStr.substr(pos, 2));
    pos += 3; // Jour + '/'
    
    // Mois
    month = dateTimeStr.substr(pos, 3);
    pos += 4; // Mois + '/'
    
    // Année
    year = stoi(dateTimeStr.substr(pos, 4));
    pos += 5; // Année + ':'
    
    // Heure
    hour = stoi(dateTimeStr.substr(pos, 2));
    pos += 3; // Heure + ':'
    
    // Minute
    minute = stoi(dateTimeStr.substr(pos, 2));
    pos += 3; // Minute + ':'
    
    // Seconde
    second = stoi(dateTimeStr.substr(pos, 2));
    pos += 3; // Seconde + ' '
    
    // Timezone
    timezone = dateTimeStr.substr(pos, 5);
} //----- Fin de DateTime (constructeur avec paramètre)

DateTime::DateTime()
    : day(0), month(""), year(0), hour(0), minute(0), second(0), timezone("")
// Algorithme : Initialisation par défaut
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <DateTime>" << endl;
#endif
} //----- Fin de DateTime (constructeur par défaut)

DateTime::~DateTime()
// Algorithme : Aucune ressource dynamique à libérer
{
#ifdef MAP
    cout << "Appel au destructeur de <DateTime>" << endl;
#endif
} //----- Fin de ~DateTime
