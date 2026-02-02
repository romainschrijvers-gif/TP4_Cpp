/*************************************************************************
                           LogParser  -  Parse les fichiers de logs Apache
                             -------------------
    début                : 13/01/2026
    copyright            : (C) 2026 par Équipe TP
*************************************************************************/

//---------- Réalisation de la classe <LogParser> (fichier LogParser.cpp) -

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "LogParser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool LogParser::ParseFile(const string & filename)
// Algorithme :
// Ouvre le fichier, lit ligne par ligne, parse chaque ligne
{
    ifstream file(filename.c_str());
    if (!file.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier '" << filename << "'" << endl;
        return false;
    }
    
    string line;
    while (getline(file, line)) {
        LogEntry* entry = ParseLine(line);
        if (entry != nullptr) {
            logEntries.push_back(*entry);
            delete entry;
        }
        // Ignore les lignes mal formées
    }
    
    file.close();
    return true;
} //----- Fin de ParseFile

const vector<LogEntry>& LogParser::GetEntries() const
// Algorithme : Retourne la référence à logEntries
{
    return logEntries;
} //----- Fin de GetEntries

//-------------------------------------------- Constructeurs - destructeur
LogParser::LogParser()
    : logEntries()
// Algorithme : Initialisation par défaut
{
#ifdef MAP
    cout << "Appel au constructeur de <LogParser>" << endl;
#endif
} //----- Fin de LogParser

LogParser::~LogParser()
// Algorithme : Aucune ressource dynamique à libérer
{
#ifdef MAP
    cout << "Appel au destructeur de <LogParser>" << endl;
#endif
} //----- Fin de ~LogParser

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
LogEntry* LogParser::ParseLine(const string & line)
// Algorithme :
// Parse une ligne au format Apache Combined Log
// Format : IP - - [Date] "Method URL Protocol" Code Size "Referer" "UserAgent"
{
    try {
        // Variables pour extraire les champs
        string ip, dateTimeStr, method, url, protocol, referer, userAgent;
        int statusCode, size;
        
        // Position de parsing
        size_t pos = 0;
        
        // 1. Extraire IP (jusqu'au premier espace)
        size_t spacePos = line.find(' ', pos);
        if (spacePos == string::npos) return nullptr;
        ip = line.substr(pos, spacePos - pos);
        pos = spacePos + 1;
        
        // 2. Sauter "- - "
        pos = line.find('[', pos);
        if (pos == string::npos) return nullptr;
        
        // 3. Extraire DateTime (entre crochets)
        size_t endBracket = line.find(']', pos);
        if (endBracket == string::npos) return nullptr;
        dateTimeStr = line.substr(pos, endBracket - pos + 1);
        pos = endBracket + 2; // Sauter "] "
        
        // 4. Extraire la requête (entre guillemets)
        if (line[pos] != '"') return nullptr;
        pos++; // Sauter le guillemet
        size_t endQuote = line.find('"', pos);
        if (endQuote == string::npos) return nullptr;
        string request = line.substr(pos, endQuote - pos);
        pos = endQuote + 2; // Sauter '" '
        
        // Parser la requête : Method URL Protocol
        istringstream requestStream(request);
        requestStream >> method >> url >> protocol;
        
        // 5. Extraire le code de statut
        istringstream statusStream(line.substr(pos));
        statusStream >> statusCode;
        pos = line.find(' ', pos) + 1;
        
        // 6. Extraire la taille
        istringstream sizeStream(line.substr(pos));
        string sizeStr;
        sizeStream >> sizeStr;
        size = (sizeStr == "-") ? 0 : stoi(sizeStr);
        pos = line.find(' ', pos) + 1;
        
        // 7. Extraire le referer (entre guillemets)
        if (pos >= line.length() || line[pos] != '"') return nullptr;
        pos++;
        endQuote = line.find('"', pos);
        if (endQuote == string::npos) return nullptr;
        referer = line.substr(pos, endQuote - pos);
        pos = endQuote + 2;
        
        // 8. Extraire le user agent (entre guillemets)
        if (pos >= line.length() || line[pos] != '"') return nullptr;
        pos++;
        endQuote = line.find('"', pos);
        if (endQuote == string::npos) return nullptr;
        userAgent = line.substr(pos, endQuote - pos);
        
        // Créer l'objet DateTime
        DateTime dt(dateTimeStr);
        
        // Créer et retourner le LogEntry
        return new LogEntry(ip, dt, method, url, protocol, statusCode, size, referer, userAgent);
        
    } catch (...) {
        // En cas d'erreur de parsing, retourner nullptr
        return nullptr;
    }
} //----- Fin de ParseLine
