all: main test

main: main.c
	gcc -o main_program main.c

test: test_main.c main.c
	gcc -o test_program test_main.c -lgtest -lgtest_main -pthread

clean:
	rm -f main_program test_program
