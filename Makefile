bin/main: obj/main.o obj/board.o obj/game.o
	g++ obj/main.o obj/board.o obj/game.o -o bin/main
obj/main.o: src/main.cpp
	g++ -c src/main.cpp -o obj/main.o
obj/board.o: src/board.cpp src/board.h
	g++ -c src/board.cpp -o obj/board.o
obj/game.o: src/game.cpp src/game.h
	g++ -c src/game.cpp -o obj/game.o
clean:
	rm obj/*.o bin/main.exe