SFML_PATH = ./sfml
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

bin/tic-tac-toe: obj/main.o obj/board.o
	g++ obj/main.o obj/board.o -o bin/tic-tac-toe -L$(SFML_PATH)/lib $(SFML_LIBS)
obj/main.o: src/main.cpp src/constants.h src/board.h
	g++ -c -I$(SFML_PATH)/include src/main.cpp -o obj/main.o
obj/board.o: src/board.cpp src/board.h src/constants.h
	g++ -c src/board.cpp -o obj/board.o