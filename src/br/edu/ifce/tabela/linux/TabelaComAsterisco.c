#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <zconf.h>

char getch() {
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0) perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr ~ICANON");
    printf("%c\n", buf);

    return buf;
}

void imprimir_matriz(char matriz[4][6]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            printf("%c ", matriz[i][j]);
        }
        printf(" \n");
    }
}

void limitar_linha(int coordenadas[]) {
    if (coordenadas[0] < 0) {
        coordenadas[0] = 0;
    } else if (coordenadas[0] > 3) {
        coordenadas[0] = 3;
    }
}

void limitar_coluna(int coordenadas[]) {
    if (coordenadas[1] < 1) {
        coordenadas[1] = 1;
    } else if (coordenadas[1] > 4) {
        coordenadas[1] = 4;
    }
}

void criar_matriz(int coordenadas[]) {
    char matriz[4][6] = {{'|', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', '|'}};
    limitar_linha(coordenadas);
    limitar_coluna(coordenadas);
    matriz[coordenadas[0]][coordenadas[1]] = '*';
    system("clear");
    imprimir_matriz(matriz);
}

void inserir_comando() {
    int coordenadas[2] = {0, 1};
    char input;
    criar_matriz(coordenadas);
    do {
        input = getch();
        switch (input) {
            case 'w':
                coordenadas[0]--;
                criar_matriz(coordenadas);
                break;
            case 's':
                coordenadas[0]++;
                criar_matriz(coordenadas);
                break;
            case 'a':
                coordenadas[1]--;
                criar_matriz(coordenadas);
                break;
            case 'd':
                coordenadas[1]++;
                criar_matriz(coordenadas);
                break;
            case 'q':
                criar_matriz(coordenadas);
                continue;
            default:
                criar_matriz(coordenadas);
                printf("As teclas permitidas sao: W, S, A, D\n");
                printf("Para encerrar o programa: Q\n");
                break;
        }
    } while (input != 'q');
}

int main() {
    inserir_comando();

    return 0;
}
