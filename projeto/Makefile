# ==============================================================================
# VARIÁVEIS DE CONFIGURAÇÃO
# ==============================================================================
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -std=c99
LIBS = -lm

# Caminhos corrigidos
INCLUDES = -I./src/includes
SRCDIR = ./src/output
OBJDIR = ./obj
EXEC = main2.exe

# Lista específica de arquivos - REMOVA main.c se não for usar
SRCS = main2.c estatistica.c historico.c fatorial.c matriz.c menus.c estrutura.c
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

# ==============================================================================
# ALVOS PRINCIPAIS
# ==============================================================================

all: $(OBJDIR) $(EXEC)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBS)

# Regra específica para cada arquivo
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all clean run valgrind

clean:
	rm -rf $(OBJDIR) $(EXEC)
	@echo "Limpeza concluída!"

run: $(EXEC)
	@echo "Executando $(EXEC):"
	./$(EXEC)

valgrind: $(EXEC)
	@echo "Executando sob Valgrind:"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXEC)