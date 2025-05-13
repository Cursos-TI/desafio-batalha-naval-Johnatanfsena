#include <stdio.h>
  
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração da matriz do tabuleiro (10x10)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas iniciais do navio horizontal
    int linhaH = 2;
    int colunaH = 4;

    // Coordenadas iniciais do navio vertical
    int linhaV = 5;
    int colunaV = 1;

    // Verificação se o navio horizontal cabe no tabuleiro
    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Verifica se há sobreposição com o navio vertical
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (linhaH == linhaV + i && colunaH + i == colunaV) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio horizontal no tabuleiro
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = 3;
            }
        } else {
            printf("Erro: sobreposição detectada!\n");
            return 1;
        }
    } else {
        printf("Erro: navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Verificação se o navio vertical cabe no tabuleiro
    if (linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Verifica se há sobreposição com o navio horizontal
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio vertical no tabuleiro
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        } else {
            printf("Erro: sobreposição detectada!\n");
            return 1;
        }
    } else {
        printf("Erro: navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("\nTABULEIRO:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
