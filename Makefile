# Nombre del ejecutable
MAIN_EXEC = main_program
TEST_EXEC = test_program

# Archivos fuente
MAIN_SRC = main.c
TEST_SRC = test_main.c

# Flags de compilación
CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lcheck -pthread

all: $(MAIN_EXEC) $(TEST_EXEC)

$(MAIN_EXEC): $(MAIN_SRC)
	$(CC) $(CFLAGS) -o $(MAIN_EXEC) $(MAIN_SRC)

$(TEST_EXEC): $(TEST_SRC) $(MAIN_EXEC)
	$(CC) $(CFLAGS) -o $(TEST_EXEC) $(TEST_SRC) $(LDFLAGS)

clean:
	rm -f $(MAIN_EXEC) $(TEST_EXEC)
