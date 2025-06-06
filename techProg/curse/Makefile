all: main

main.o: src/main.cpp
	g++ -Wall -Werror -Iinclude -c src/main.cpp -o main.o

model.o: src/model.cpp
	g++ -Wall -Werror -Iinclude -c src/model.cpp -o model.o

database.o: src/database.cpp
	g++ -Wall -Werror -Iinclude -c src/database.cpp -o database.o

search.o: src/search.cpp
	g++ -Wall -Werror -Iinclude -c src/search.cpp -o search.o

sqlite3.o: src/sqlite3.c
	gcc -Wall -Iinclude -c src/sqlite3.c -o sqlite3.o

main: main.o model.o database.o search.o sqlite3.o
	g++ -Wall -Werror -Iinclude main.o model.o database.o search.o sqlite3.o -o main -lsqlite3

run: main
	./main
