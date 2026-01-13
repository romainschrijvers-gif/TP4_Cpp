/*************************************************************************
                           Analyzer  -  Analyse les logs et génère les stats
                             -------------------
    début                : 13/01/2026
    copyright            : (C) 2026 par Équipe TP
*************************************************************************/

//---------- Réalisation de la classe <Analyzer> (fichier Analyzer.cpp) ---

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <algorithm>

//------------------------------------------------------ Include personnel
#include "Analyzer.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Analyzer::Analyze(const std::vector<LogEntry> & entries)
// Algorithme :
// 1. Pour chaque entrée valide selon les filtres :
//    - Incrémenter le hit count du document
//    - Si referer local, incrémenter la transition
{
    for (const LogEntry& entry : entries) {
        if (!ShouldIncludeEntry(entry)) {
            continue;
        }
        
        string url = entry.GetURL();
        
        // Créer ou récupérer le document
        if (documents.find(url) == documents.end()) {
            documents[url] = new Document(url);
        }
        documents[url]->IncrementHits();
        
        // Gérer les transitions
        string referer = entry.GetReferer();
        if (!referer.empty() && referer != "-" && IsLocalReferer(referer)) {
            // Extraire l'URL du referer (partie après le domaine)
            size_t domainEnd = referer.find('/', 8); // Après "http://"
            if (domainEnd != string::npos) {
                string refererURL = referer.substr(domainEnd);
                
                // Ne pas compter les transitions vers/depuis ressources statiques
                bool refererIsStatic = false;
                if (excludeStatic) {
                    // Vérifier si le referer est une ressource statique
                    LogEntry tempEntry("", DateTime(), "", refererURL, "", 0, 0, "", "");
                    refererIsStatic = tempEntry.IsStaticResource();
                }
                
                if (!refererIsStatic) {
                    Transition t(refererURL, url);
                    transitions[t]++;
                }
            }
        }
    }
} //----- Fin de Analyze

std::vector<Document*> Analyzer::GetTopDocuments(int n) const
// Algorithme :
// 1. Copier tous les documents dans un vecteur
// 2. Trier le vecteur par ordre décroissant de hits
// 3. Retourner les n premiers
{
    vector<Document*> docList;
    for (const auto& pair : documents) {
        docList.push_back(pair.second);
    }
    
    sort(docList.begin(), docList.end(), 
         [](const Document* a, const Document* b) {
             return *a < *b; // Utilise l'opérateur < de Document
         });
    
    // Limiter à n éléments
    if (docList.size() > static_cast<size_t>(n)) {
        docList.resize(n);
    }
    
    return docList;
} //----- Fin de GetTopDocuments

const std::map<Transition, int>& Analyzer::GetTransitions() const
// Algorithme : Retourne la référence à transitions
{
    return transitions;
} //----- Fin de GetTransitions

void Analyzer::SetExcludeStatic(bool exclude)
// Algorithme : Définit excludeStatic
{
    excludeStatic = exclude;
} //----- Fin de SetExcludeStatic

void Analyzer::SetHourFilter(int h)
// Algorithme : Définit hourFilter
{
    hourFilter = h;
} //----- Fin de SetHourFilter

void Analyzer::SetBaseURL(const std::string & base)
// Algorithme : Définit baseURL
{
    baseURL = base;
} //----- Fin de SetBaseURL

//-------------------------------------------- Constructeurs - destructeur
Analyzer::Analyzer()
    : documents(), transitions(), excludeStatic(false), hourFilter(-1), baseURL("")
// Algorithme : Initialisation par défaut
{
#ifdef MAP
    cout << "Appel au constructeur de <Analyzer>" << endl;
#endif
} //----- Fin de Analyzer

Analyzer::~Analyzer()
// Algorithme : Libère la mémoire allouée pour les documents
{
#ifdef MAP
    cout << "Appel au destructeur de <Analyzer>" << endl;
#endif
    
    for (auto& pair : documents) {
        delete pair.second;
    }
} //----- Fin de ~Analyzer

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool Analyzer::ShouldIncludeEntry(const LogEntry & entry) const
// Algorithme :
// Vérifie si l'entrée passe tous les filtres actifs
{
    // Filtre par heure
    if (hourFilter != -1 && entry.GetDateTime().GetHour() != hourFilter) {
        return false;
    }
    
    // Filtre ressources statiques
    if (excludeStatic && entry.IsStaticResource()) {
        return false;
    }
    
    return true;
} //----- Fin de ShouldIncludeEntry

bool Analyzer::IsLocalReferer(const std::string & referer) const
// Algorithme :
// Vérifie si le referer commence par l'URL de base
{
    if (baseURL.empty()) {
        return true; // Si pas d'URL de base, accepter tous les referers
    }
    return referer.find(baseURL) == 0;
} //----- Fin de IsLocalReferer
