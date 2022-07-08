bin/main: obj/main.o obj/board.o
	g++ obj/main.o obj/board.o -o bin/main
obj/main.o: src/main.cpp
	g++ -c src/main.cpp -o obj/main.o
obj/board.o: src/board.cpp src/board.h
	g++ -c src/board.cpp -o obj/board.o
clean:
	rm obj/*.o bin/main.exe