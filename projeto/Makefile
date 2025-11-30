CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -std=c99
INCLUDES = -Isrc/includes
LIBS = -lm
EXEC = main2.exe

# Lista APENAS dos arquivos que EXISTEM
SRCS = src/main2.c src/estatistica.c src/historico.c src/fatorial.c src/matriz.c src/menus.c
OBJS = $(SRCS:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXEC)

.PHONY: all clean run valgrind