# Makefile pour le projet analog
# TP C++ n°4 - Analyse de logs Apache

# Compilateur et options
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -g -Isrc
LDFLAGS =

# Répertoires
SRCDIR = src
BINDIR = bin
OBJDIR = $(BINDIR)

# Nom de l'exécutable
EXEC = $(BINDIR)/analog

# Fichiers sources et objets
SOURCES = analog.cpp DateTime.cpp LogEntry.cpp Document.cpp LogParser.cpp Analyzer.cpp GraphGenerator.cpp Options.cpp
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))

# Cible par défaut
all: $(BINDIR) $(EXEC)

# Création du répertoire bin
$(BINDIR):
	mkdir -p $(BINDIR)

# Règle de compilation de l'exécutable
$(EXEC): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

# Règle de compilation des fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(BINDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Dépendances des fichiers objets
$(OBJDIR)/analog.o: $(SRCDIR)/analog.cpp $(SRCDIR)/Options.h $(SRCDIR)/LogParser.h $(SRCDIR)/Analyzer.h $(SRCDIR)/GraphGenerator.h
$(OBJDIR)/DateTime.o: $(SRCDIR)/DateTime.cpp $(SRCDIR)/DateTime.h
$(OBJDIR)/LogEntry.o: $(SRCDIR)/LogEntry.cpp $(SRCDIR)/LogEntry.h $(SRCDIR)/DateTime.h
$(OBJDIR)/Document.o: $(SRCDIR)/Document.cpp $(SRCDIR)/Document.h
$(OBJDIR)/LogParser.o: $(SRCDIR)/LogParser.cpp $(SRCDIR)/LogParser.h $(SRCDIR)/LogEntry.h $(SRCDIR)/DateTime.h
$(OBJDIR)/Analyzer.o: $(SRCDIR)/Analyzer.cpp $(SRCDIR)/Analyzer.h $(SRCDIR)/LogEntry.h $(SRCDIR)/Document.h
$(OBJDIR)/GraphGenerator.o: $(SRCDIR)/GraphGenerator.cpp $(SRCDIR)/GraphGenerator.h
$(OBJDIR)/Options.o: $(SRCDIR)/Options.cpp $(SRCDIR)/Options.h

# Règle de nettoyage
clean:
	rm -f $(OBJECTS) $(EXEC)

# Règle pour nettoyer tout (incluant les fichiers générés)
mrproper: clean
	rm -rf $(BINDIR) *.dot *.png

# Aide
help:
	@echo "Makefile pour le projet analog"
	@echo ""
	@echo "Cibles disponibles :"
	@echo "  all       : Compile le projet (défaut)"
	@echo "  clean     : Supprime les fichiers objets et l'exécutable"
	@echo "  mrproper  : Nettoyage complet (clean + bin/ + fichiers .dot/.png)"
	@echo "  help      : Affiche cette aide"
	@echo ""
	@echo "Tests :"
	@echo "  cd Tests && ./mktest.sh              : Exécute tous les tests"
	@echo "  cd Tests && ./test.sh <TestName>     : Exécute un test spécifique"

.PHONY: all clean mrproper help
