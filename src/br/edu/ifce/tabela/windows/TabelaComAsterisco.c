#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

TCHAR getch() {
    DWORD mode, cc;
    HANDLE h = GetStdHandle(STD_INPUT_HANDLE);
    if (h == NULL) {
        return 0;
    }
    GetConsoleMode(h, &mode);
    SetConsoleMode(h, mode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT));
    TCHAR c = 0;
    ReadConsole(h, &c, 1, &cc, NULL);
    SetConsoleMode(h, mode);

    return c;
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
    system("@cls||clear");
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
