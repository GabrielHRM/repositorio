#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char *alocarhistorico(int tamanho);

char *adicionarhistorico(char *hist, char *entrada, int *espacousado, int *tamanho);

void mostrarhistorico(char *hist);