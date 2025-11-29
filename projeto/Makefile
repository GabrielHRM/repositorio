# ==============================================================================
# VARIÁVEIS DE CONFIGURAÇÃO
# ==============================================================================
CC = gcc
# -g é crucial para o Valgrind. -Werror trata warnings como erros.
CFLAGS = -Wall -Wextra -Werror -g -std=c99
# -I: Indica o diretório para procurar arquivos de cabeçalho (.h)
INCLUDES = -Isrc/includes
# Diretório onde estão todos os arquivos .c (incluindo o main2.c)
SRCDIR = src/output
# Diretório para arquivos .o
OBJDIR = obj
# Nome do executável final
EXEC = main2.exe

# Lista de TODOS os arquivos C em src/output (sem o caminho)
SRCS = $(notdir $(wildcard $(SRCDIR)/*.c))

# Lista de arquivos objeto (.o) que serão gerados na pasta 'obj'
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

# ==============================================================================
# ALVOS PRINCIPAIS
# ==============================================================================

# 1. Alvo Padrão: cria o diretório de objetos e o executável
all: $(OBJDIR) $(EXEC)

# Cria o diretório de objetos, se não existir
$(OBJDIR):
	mkdir -p $(OBJDIR)

# 2. Cria o executável 'main2.exe'
# Depende de todos os arquivos objeto.
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# 3. Regra Genérica para criar arquivos .o (Cria módulos)
# Transforma .c (da pasta $(SRCDIR)) em .o (na pasta $(OBJDIR))
# O $< é o nome do arquivo .c que está sendo compilado.
# O $(INCLUDES) garante que os arquivos .h sejam encontrados.
$(OBJDIR)/%.o: $(SRCDIR)/%.c src/includes/*.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ==============================================================================
# ALVOS AUXILIARES E DE DEBUG
# ==============================================================================

# Regras que não geram arquivos físicos
.PHONY: all clean run valgrind

# Limpeza: remove executável e a pasta de objetos
clean:
	rm -rf $(OBJDIR) $(EXEC)
	@echo "Limpeza concluída! Arquivos objeto e executável removidos."

# Compila e roda o programa
run: $(EXEC)
	@echo "Executando $(EXEC):"
	./$(EXEC)

# Compila e roda o programa sob o Valgrind (verificação de vazamento de memória)
valgrind: $(EXEC)
	@echo "Executando sob Valgrind (Memcheck):"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(EXEC)