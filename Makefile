SFML_PATH = ./sfml
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

bin/main: obj/main.o obj/board.o obj/game.o
	g++ obj/main.o obj/board.o obj/game.o -o bin/main -L$(SFML_PATH)/lib $(SFML_LIBS)
obj/main.o: src/main.cpp
	g++ -c -I$(SFML_PATH)/include src/main.cpp -o obj/main.o
obj/board.o: src/board.cpp src/board.h
	g++ -c src/board.cpp -o obj/board.o
obj/game.o: src/game.cpp src/game.h
	g++ -c src/game.cpp -o obj/game.o
clean:
	rm obj/*.o bin/main.exe