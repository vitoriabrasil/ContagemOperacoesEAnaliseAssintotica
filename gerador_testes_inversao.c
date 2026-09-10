#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanhos[] = {1000, 50000, 100000, 500000, 1000000};  //entradas determinadas pelo trabalho
    int qtd_tamanhos = 5;

    for (int t = 0; t < qtd_tamanhos; t++) {
        int n = tamanhos[t]; //atribuindo a n o tamanho da entrada

        // --- Arquivo para testar inversão ---
        char nome_inv[100];
        sprintf(nome_inv, "entrada_inversao_%d.txt", n);  //criando nome do arquivo com base na entrada
        FILE *fi = fopen(nome_inv, "w");

        fprintf(fi, "%d\n", n);              //registrando N no .txt
        for (int i = 0; i < n; i++) {
            fprintf(fi, "%d ", i * 2);       //registrando vetor ordenado, só pares, no .txt
        }
        fprintf(fi, "\n");                   
        fprintf(fi, "1\n");                  //registrando opcao de inversao
        fprintf(fi, "5\n");                  //registrando a saída do programa no .txt
        fclose(fi);                          //fechando o arquivo
    }

    return 0;
}