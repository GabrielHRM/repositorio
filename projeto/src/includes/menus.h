#ifndef MENUS_H
#define MENUS_H

void menuprincipal();
char *operacoesbasicas(char *hist, double *resultado, int *espacousado, int *tamanho);
char *potenciaseraizes(char *hist, double *resultado, int *espacousado, int *tamanho);
char *trigonometricos(char *hist, double *resultado, int *espacousado, int *tamanho);
char *logaritimos(double *resultado2, double *resultado, char *hist, int *espacousado, int *tamanho);
char *fatorial(double *resultado2, double *resultado, char *hist, int *espacousado, int *tamanho);
char *operacao_com_matrizes(char *hist, int *espacousado, int *tamanho);
char *fatoracao_em_primos(char *hist, int *espacousado, int *tamanho);
char *operacoes_estatisticas(char *hist, int *espacousado, int *tamanho);

#endif