#ifndef HISTORICO_H
#define HISTORICO_H

char* alocarhistorico(int tamanho);
char* adicionarhistorico(char* hist, char* entrada, int* espacousado, int* tamanho);
char *limparhistorico(char *hist);
void mostrarhistorico(char* hist);

#endif