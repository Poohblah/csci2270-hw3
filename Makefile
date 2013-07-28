MAIN_OUT = bint.o
TEST_OUT = binttest.o
C++ = "g++ -Wall"

all:
	g++ -Wall bigInt.cpp main.cxx -o $(MAIN_OUT)

run: all
	./$(MAIN_OUT)

test:
	g++ -c bigInt.cpp -o bigInt.o
	g++ -Wall bigIntTest.cpp bigInt.o -o $(TEST_OUT)
	./$(TEST_OUT)

cstr:
	g++ -Wall cstrexamples.cxx -o cstrexamples.o && ./cstrexamples.o
