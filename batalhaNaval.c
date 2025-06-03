
int main() {
    int tabuleiro[10][10] = {0};
    int tamanhoNavio = 3;

    // Coordenadas dos navios
    int l1 = 2, c1 = 4; // Navio 1 - horizontal
    int l2 = 5, c2 = 7; // Navio 2 - vertical
    int l3 = 0, c3 = 0; // Navio 3 - diagonal 1
    int l4 = 0, c4 = 9; // Navio 4 - diagonal 2

    // Navio horizontal
    if (c1 + tamanhoNavio <= 10) {
        for (int i = 0; i < tamanhoNavio; ++i) {
            if (tabuleiro[l1][c1 + i] != 0) {
                printf("Sobreposição no navio horizontal.\n");
                return 1;
            }
        }
        for (int i = 0; i < tamanhoNavio; ++i)
            tabuleiro[l1][c1 + i] = 3;
    } else {
        printf("Navio horizontal fora do tabuleiro.\n");
        return 1;
    }

    // Navio vertical
    if (l2 + tamanhoNavio <= 10) {
        for (int i = 0; i < tamanhoNavio; ++i) {
            if (tabuleiro[l2 + i][c2] != 0) {
                printf("Sobreposição no navio vertical.\n");
                return 1;
            }
        }
        for (int i = 0; i < tamanhoNavio; ++i)
            tabuleiro[l2 + i][c2] = 3;
    } else {
        printf("Navio vertical fora do tabuleiro.\n");
        return 1;
    }

    // Navio diagonal 1
    if (l3 + tamanhoNavio <= 10 && c3 + tamanhoNavio <= 10) {
        for (int i = 0; i < tamanhoNavio; ++i) {
            if (tabuleiro[l3 + i][c3 + i] != 0) {
                printf("Sobreposição no navio diagonal principal.\n");
                return 1;
            }
        }
        for (int i = 0; i < tamanhoNavio; ++i)
            tabuleiro[l3 + i][c3 + i] = 3;
    } else {
        printf("Navio diagonal principal fora do tabuleiro.\n");
        return 1;
    }

    // Navio diagonal 2
    if (l4 + tamanhoNavio <= 10 && c4 - tamanhoNavio + 1 >= 0) {
        for (int i = 0; i < tamanhoNavio; ++i) {
            if (tabuleiro[l4 + i][c4 - i] != 0) {
                printf("Sobreposição no navio diagonal inversa.\n");
                return 1;
            }
        }
        for (int i = 0; i < tamanhoNavio; ++i)
            tabuleiro[l4 + i][c4 - i] = 3;
    } else {
        printf("Navio diagonal inversa fora do tabuleiro.\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}