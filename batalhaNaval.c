#include <stdio.h>

#define TAM 10
#define HABI 5

int tabuleiro[TAM][TAM];

// ---------- Funções Básicas ----------
void inicializarTabuleiro() {
    for (int i = 0; i < TAM; ++i)
        for (int j = 0; j < TAM; ++j)
            tabuleiro[i][j] = 0;
}

void exibirTabuleiro() {
    printf("\nTabuleiro (0 = água, 3 = navio, 5 = habilidade):\n");
    for (int i = 0; i < TAM; ++i) {
        for (int j = 0; j < TAM; ++j) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int absoluto(int x) {
    return x < 0 ? -x : x;
}

// ---------- Posicionamento de Navios ----------
void posicionarNavios() {
    int tamanho = 3;

    // Navio 1 - horizontal
    int l1 = 2, c1 = 4;
    for (int i = 0; i < tamanho; ++i)
        tabuleiro[l1][c1 + i] = 3;

    // Navio 2 - vertical
    int l2 = 5, c2 = 7;
    for (int i = 0; i < tamanho; ++i)
        tabuleiro[l2 + i][c2] = 3;

    // Navio 3 - diagonal 1
    int l3 = 0, c3 = 0;
    for (int i = 0; i < tamanho; ++i)
        tabuleiro[l3 + i][c3 + i] = 3;

    // Navio 4 - diagonal 2
    int l4 = 0, c4 = 9;
    for (int i = 0; i < tamanho; ++i)
        tabuleiro[l4 + i][c4 - i] = 3;
}

// ---------- Geração de Habilidades ----------
void gerarCone(int cone[HABI][HABI]) {
    for (int i = 0; i < HABI; ++i) {
        for (int j = 0; j < HABI; ++j) {
            if (j >= (HABI / 2 - i) && j <= (HABI / 2 + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

void gerarCruz(int cruz[HABI][HABI]) {
    for (int i = 0; i < HABI; ++i) {
        for (int j = 0; j < HABI; ++j) {
            if (i == HABI / 2 || j == HABI / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

void gerarOctaedro(int oct[HABI][HABI]) {
    for (int i = 0; i < HABI; ++i) {
        for (int j = 0; j < HABI; ++j) {
            if (absoluto(i - HABI / 2) + absoluto(j - HABI / 2) <= HABI / 2)
                oct[i][j] = 1;
            else
                oct[i][j] = 0;
        }
    }
}

// ---------- Aplicação de Habilidade ao Tabuleiro ----------
void aplicarHabilidade(int habilidade[HABI][HABI], int linha, int coluna) {
    int offset = HABI / 2;

    for (int i = 0; i < HABI; ++i) {
        for (int j = 0; j < HABI; ++j) {
            int x = linha - offset + i;
            int y = coluna - offset + j;

            if (x >= 0 && x < TAM && y >= 0 && y < TAM && habilidade[i][j] == 1) {
                if (tabuleiro[x][y] == 0)
                    tabuleiro[x][y] = 5;
            }
        }
    }
}

// ---------- Função Principal ----------
int main() {
    inicializarTabuleiro();
    posicionarNavios();

    // Habilidade 1: Cone
    int cone[HABI][HABI];
    gerarCone(cone);
    aplicarHabilidade(cone, 4, 4);

    // Habilidade 2: Cruz
    int cruz[HABI][HABI];
    gerarCruz(cruz);
    aplicarHabilidade(cruz, 6, 2);

    // Habilidade 3: Octaedro
    int octaedro[HABI][HABI];
    gerarOctaedro(octaedro);
    aplicarHabilidade(octaedro, 5, 5);

    exibirTabuleiro();
    return 0;
}