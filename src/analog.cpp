/*************************************************************************
                                analog
                Analyse de logs Apache - Programme principal
                             -------------------
    début                : 13/01/2026
    copyright            : (C) 2026 par Équipe TP
*************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <iomanip>

//------------------------------------------------------ Include personnel
#include "Options.h"
#include "LogParser.h"
#include "Analyzer.h"
#include "GraphGenerator.h"

//------------------------------------------------------------- Constantes
const string BASE_URL = "http://intranet-if.insa-lyon.fr";
const int TOP_N = 10;

//------------------------------------------------------------------- Main
int main(int argc, char* argv[])
{
    // 1. Parser les options de ligne de commande
    Options options;
    if (!options.ParseCommandLine(argc, argv)) {
        return 1;
    }
    
    // 2. Parser le fichier de logs
    cout << "Lecture du fichier de logs..." << endl;
    LogParser parser;
    if (!parser.ParseFile(options.GetLogFile())) {
        return 1;
    }
    
    const vector<LogEntry>& entries = parser.GetEntries();
    cout << entries.size() << " entrées lues" << endl;
    
    // 3. Configurer et exécuter l'analyse
    Analyzer analyzer;
    analyzer.SetExcludeStatic(options.IsExcludeStatic());
    analyzer.SetHourFilter(options.GetHourFilter());
    analyzer.SetBaseURL(BASE_URL);
    
    cout << "Analyse des logs..." << endl;
    analyzer.Analyze(entries);
    
    // 4. Afficher le top des documents
    vector<Document*> topDocs = analyzer.GetTopDocuments(TOP_N);
    
    cout << endl;
    cout << "Top " << topDocs.size() << " des documents les plus consultés :" << endl;
    cout << "---------------------------------------------------" << endl;
    
    for (const Document* doc : topDocs) {
        cout << doc->GetURL() << " (" << doc->GetHitCount() << " hits)" << endl;
    }
    
    // 5. Générer le graphe si demandé
    if (options.IsGenerateGraph()) {
        cout << endl;
        cout << "Génération du graphe..." << endl;
        
        GraphGenerator generator;
        const map<Transition, int>& transitions = analyzer.GetTransitions();
        
        for (const auto& trans : transitions) {
            const string& source = trans.first.first;
            const string& dest = trans.first.second;
            int count = trans.second;
            generator.AddTransition(source, dest, count);
        }
        
        if (generator.GenerateGraph(options.GetGraphFile())) {
            cout << "Graphe généré dans le fichier '" 
                 << options.GetGraphFile() << "'" << endl;
        } else {
            cerr << "Erreur lors de la génération du graphe" << endl;
            return 1;
        }
    }
    
    cout << endl;
    cout << "Analyse terminée avec succès" << endl;
    
    return 0;
} //----- Fin de main
