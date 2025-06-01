#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0};
    int tamanhoNavio = 3;

    // Coordenadas dos navios
    int l1 = 2, c1 = 4; // Navio 1 em horizontal
    int l2 = 5, c2 = 7; // Navio 2 em Vertical

    // Posicao navio horizontal
    if (c1 + tamanhoNavio <= 10) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[l1][c1 + i] != 0) {
                printf("Sobreposição no navio horizontal.\n");
                return 1;
            }
        }
        for (int i = 0; i < tamanhoNavio; i++)
            tabuleiro[l1][c1 + i] = 3;
    } else {
        printf("Navio horizontal fora do tabuleiro.\n");
        return 1;
    }

    // Posicao navio vertical
    if (l2 + tamanhoNavio <= 10) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[l2 + i][c2] != 0) {
                printf("Sobreposição no navio vertical.\n");
                return 1;
            }
        }
        for (int i = 0; i < tamanhoNavio; i++)
            tabuleiro[l2 + i][c2] = 3;
    } else {
        printf("Navio vertical fora do tabuleiro.\n");
        return 1;
    }

    // Exibe o tabuleiro
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}