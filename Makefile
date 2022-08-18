SFML_PATH = ./sfml
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

bin/tic-tac-toe: obj/main.o
	g++ obj/main.o -o bin/tic-tac-toe -L$(SFML_PATH)/lib $(SFML_LIBS)
obj/main.o: src/main.cpp src/constants.h
	g++ -c -I$(SFML_PATH)/include src/main.cpp -o obj/main.o