SFML_PATH = ./sfml
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

bin/tic-tac-toe: obj/main.o obj/board.o obj/graphics.o obj/cell.o obj/statusbar.o
	g++ obj/main.o obj/board.o obj/graphics.o obj/cell.o obj/statusbar.o -o bin/tic-tac-toe -L$(SFML_PATH)/lib $(SFML_LIBS)

obj/main.o: src/main.cpp obj/board.o obj/statusbar.o
	g++ -c -I$(SFML_PATH)/include src/main.cpp -o obj/main.o

obj/board.o: src/board.cpp src/board.h obj/graphics.o obj/cell.o 
	g++ -c -I$(SFML_PATH)/include src/board.cpp -o obj/board.o

obj/cell.o: src/cell.cpp src/cell.h
	g++ -c -I$(SFML_PATH)/include src/cell.cpp -o obj/cell.o

obj/graphics.o: src/graphics.cpp src/graphics.h src/constants.h
	g++ -c -I$(SFML_PATH)/include src/graphics.cpp -o obj/graphics.o

obj/statusbar.o: src/statusbar.cpp src/statusbar.h obj/graphics.o
	g++ -c -I$(SFML_PATH)/include src/statusbar.cpp -o obj/statusbar.o

clean:
	rm bin/tic-tac-toe.exe obj/*.o