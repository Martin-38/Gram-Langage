# Nom de l'exécutable
EXEC = programme

# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -Wextra -std=c++11 -g

# Liste des fichiers sources et des fichiers objets
SRCS = automate.cpp etat.cpp expression.cpp lexer.cpp main.cpp symbole.cpp
OBJS = $(SRCS:.cpp=.o)

# Règle principale : génération de l'exécutable
$(EXEC): $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS)

# Règle de compilation des fichiers .cpp en .o
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJS) $(EXEC)

# Nettoyage complet, y compris les fichiers de sauvegarde (~)
cleanall: clean
	rm -f *~ *.swp
