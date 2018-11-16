CXX = g++
cc = gcc

LIB = -lpthread -ldl -std=c++14
BIN = sqlite BDtest

BDcreate: BDcreate.cpp sqlite3.o
		$(CXX) -o $@ $^ $(LIB) 

sqlite3.o : sqlite3.c
		$(cc) -o $@ -c $^

clean :
		rm -f $(BIN)

.PHONY: clean
