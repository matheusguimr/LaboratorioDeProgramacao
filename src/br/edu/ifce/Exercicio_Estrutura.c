#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flush_in() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

struct BANDAS {
    char nome[10];
    char estilo_musical[10];
    int numero_integrantes;
    int posicao_ranking;
};

void procurar_entre_favoritas(struct BANDAS bandas[5]) {
    printf("Digite o nome da banda:\n");
    char banda_temp[10];
    int comparador_temporario = 5;
    fgets(banda_temp, sizeof(banda_temp), stdin);
    flush_in();
    for (int i = 0; i < 5; ++i) {
        comparador_temporario = strcmp(banda_temp, bandas[i].estilo_musical);
        if (comparador_temporario == 0) { printf("A banda e uma de suas favoritas!\n"); }
    }
    if (comparador_temporario != 0) { printf("A banda nao e uma de suas favoritas!\n"); }
    printf("\n");
}

void escolher_banda_no_ranking(struct BANDAS *bandas) {
    printf("Escolha uma posicao no ranking:\n");
    int input;
    scanf("%d", &input);
    flush_in();
    for (int i = 0; i < 5; ++i) {
        if (bandas[i].posicao_ranking == input) {
            printf("Nome da banda: %s\n", bandas[i].nome);
            printf("Estilo musical: %s\n", bandas[i].estilo_musical);
            printf("Numero de integrantes: %d\n", bandas[i].numero_integrantes);
            printf("Posicao no Ranking: %d\n", bandas[i].posicao_ranking);
            printf("\n");
        }
    }
}

void comparar_estilo_musical(struct BANDAS bandas[5]) {
    printf("Digite estilo musical:\n");
    char banda_temp[10];
    int comparador_temporario;
    fgets(banda_temp, sizeof(banda_temp), stdin);
    flush_in();
    for (int i = 0; i < 5; ++i) {
        comparador_temporario = strcmp(banda_temp, bandas[i].estilo_musical);
        if (comparador_temporario == 0) {
            printf("%s\n", bandas[i].nome);
            printf("%s\n", bandas[i].estilo_musical);
            printf("%d\n", bandas[i].numero_integrantes);
            printf("%s\n", bandas[i].posicao_ranking);
        }
    }
    printf("\n");
}

void preencher_bandas(struct BANDAS bandas[5]) {
    for (int i = 0; i < 5; ++i) {
        printf("\n");
        printf("Digite o nome da banda %d:\n", i + 1);
        fgets(bandas[i].nome, sizeof(bandas[i].nome), stdin);
        flush_in();
        printf("Digite o estilo musical da banda %d:\n", i + 1);
        fgets(bandas[i].estilo_musical, sizeof(bandas[i].estilo_musical), stdin);
        flush_in();
        printf("Digite o numero de integrantes da banda %d:\n", i + 1);
        scanf("%d", &bandas[i].numero_integrantes);
        printf("Digite a posicao no ranking da banda %d:\n", i + 1);
        scanf("%d", &bandas[i].posicao_ranking);
        if (i == 4) { printf("\n"); }
    }
}

void navegar_interface() {
    struct BANDAS bandas[5];
    int input;
    printf("Bem vindo(a) ao programa!\n");
    do {
        printf("Para preencher novas bandas, digite: 1\n");
        printf("Para obter informacoes sua banda favorita, digite: 2\n");
        printf("Para obter informacoes bandas com o mesmo estilo, digite: 3\n");
        printf("Para saber se alguma banda esta entre suas favoritas, digite: 4\n");
        printf("Para encerrar o programa, digite: 0\n");
        scanf("%d", &input);
        flush_in();
        switch (input) {
            case 1:
                preencher_bandas(bandas);
                break;
            case 2:
                escolher_banda_no_ranking(bandas);
                break;
            case 3:
                comparar_estilo_musical(bandas);
                break;
            case 4:
                procurar_entre_favoritas(bandas);
                break;
            default:
                if (input != 0) { printf("Numero invalido!\n"); }
                else { printf("Programa encerrado, ate mais!\n"); }
                break;
        }
    } while (input != 0);
}

int main() {
    navegar_interface();
    return 0;
}

