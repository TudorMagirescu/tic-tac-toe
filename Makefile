SFML_PATH = ./sfml
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

bin/tic-tac-toe: obj/main.o obj/board.o obj/graphics.o
	g++ obj/main.o obj/board.o obj/graphics.o -o bin/tic-tac-toe -L$(SFML_PATH)/lib $(SFML_LIBS)
obj/main.o: src/main.cpp src/board.h src/constants.h src/graphics.h
	g++ -c -I$(SFML_PATH)/include src/main.cpp -o obj/main.o
obj/board.o: src/board.cpp src/board.h src/constants.h src/graphics.h
	g++ -c -I$(SFML_PATH)/include src/board.cpp -o obj/board.o
obj/graphics.o: src/graphics.cpp src/graphics.h
	g++ -c -I$(SFML_PATH)/include src/graphics.cpp -o obj/graphics.o
clean:
	rm bin/tic-tac-toe.exe obj/*.o