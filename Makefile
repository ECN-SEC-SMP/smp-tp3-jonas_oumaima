# Makefile très simple et lisible pour un projet C++ (fichiers .cpp)
# Utilisation : dans le dossier contenant ce Makefile -> make    ou -> make clean

CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -O2

TARGET := smp-tp3-jonas_oumaima

# Tous les .cpp du répertoire
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

# Lie les objets en un exécutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile un .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	@echo "Nettoyage..."
	rm -f $(OBJS) $(TARGET) $(TARGET).exe