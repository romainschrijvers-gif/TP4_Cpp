# Makefile pour le projet analog
# TP C++ n°4 - Analyse de logs Apache

# Compilateur et options
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -g
LDFLAGS =

# Nom de l'exécutable
EXEC = analog

# Fichiers sources et objets
SOURCES = analog.cpp DateTime.cpp LogEntry.cpp Document.cpp LogParser.cpp Analyzer.cpp GraphGenerator.cpp Options.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Cible par défaut
all: $(EXEC)

# Règle de compilation de l'exécutable
$(EXEC): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

# Règle de compilation des fichiers objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Dépendances des fichiers objets
analog.o: analog.cpp Options.h LogParser.h Analyzer.h GraphGenerator.h
DateTime.o: DateTime.cpp DateTime.h
LogEntry.o: LogEntry.cpp LogEntry.h DateTime.h
Document.o: Document.cpp Document.h
LogParser.o: LogParser.cpp LogParser.h LogEntry.h DateTime.h
Analyzer.o: Analyzer.cpp Analyzer.h LogEntry.h Document.h
GraphGenerator.o: GraphGenerator.cpp GraphGenerator.h
Options.o: Options.cpp Options.h

# Règle de nettoyage
clean:
	rm -f $(OBJECTS) $(EXEC)

# Règle pour nettoyer tout (incluant les fichiers générés)
mrproper: clean
	rm -f *.dot *.png

# Cible pour tester avec le petit exemple
test-mini: $(EXEC)
	./$(EXEC) court.log

# Cible pour tester avec le gros fichier
test-full: $(EXEC)
	./$(EXEC) anonyme.log

# Cible pour tester avec génération de graphe
test-graph: $(EXEC)
	./$(EXEC) -g graph.dot court.log
	@if command -v dot > /dev/null; then \
		dot -Tpng graph.dot -o graph.png; \
		echo "Graphe généré : graph.png"; \
	else \
		echo "GraphViz (dot) n'est pas installé, impossible de générer l'image"; \
	fi

# Cible pour tester avec options
test-options: $(EXEC)
	@echo "=== Test sans options ==="
	./$(EXEC) court.log
	@echo ""
	@echo "=== Test avec exclusion ressources statiques ==="
	./$(EXEC) -e court.log
	@echo ""
	@echo "=== Test avec filtre heure 11 ==="
	./$(EXEC) -t 11 anonyme.log
	@echo ""
	@echo "=== Test avec toutes les options ==="
	./$(EXEC) -g graph-complet.dot -e -t 11 anonyme.log

# Aide
help:
	@echo "Makefile pour le projet analog"
	@echo ""
	@echo "Cibles disponibles :"
	@echo "  all           : Compile le projet (défaut)"
	@echo "  clean         : Supprime les fichiers objets et l'exécutable"
	@echo "  mrproper      : Nettoyage complet (clean + fichiers générés)"
	@echo "  test-mini     : Test avec le petit fichier d'exemple"
	@echo "  test-full     : Test avec le fichier complet anonyme.log"
	@echo "  test-graph    : Test avec génération de graphe"
	@echo "  test-options  : Test de toutes les options"
	@echo "  help          : Affiche cette aide"

.PHONY: all clean mrproper test-mini test-full test-graph test-options help
