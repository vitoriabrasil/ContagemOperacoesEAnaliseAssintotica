#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanhos[] = {1000, 50000, 100000, 500000, 1000000};  //entradas determinadas pelo trabalho
    int qtd_tamanhos = 5;

    printf("Gerar teste para qual opcao? \n(2, 3 ou 4): ");
    int opcao;
    scanf("%d",&opcao);

    for (int t = 0; t < qtd_tamanhos; t++) {
        int n = tamanhos[t]; //atribuindo a n o tamanho da entrada
        int valor_ausente = n + 1; // o valor ausente sempre vai ser n + 1

        // --- Arquivo para testar buscas (pior caso: elemento ausente) ---
        char nome_busca[100];
        sprintf(nome_busca, "%d_entrada_busca_%d.txt", opcao,n);  //criando nome do arquivo com base na entrada
        FILE *fb = fopen(nome_busca, "w");

        fprintf(fb, "%d\n", n);              //registrando N no .txt
        for (int i = 0; i < n; i++) {
            fprintf(fb, "%d ", i * 2);       // registrando vetor ordenado, só pares, no .txt
        }
        fprintf(fb, "\n");
        fprintf(fb, "%d\n",opcao);           // registrando opcao no .txt
        fprintf(fb, "%d\n", valor_ausente);  //registrando valor ausente
        fprintf(fb, "5\n");                  //registrando a saída do programa no .txt
        fclose(fb);                          //fechando o arquivo

    }

    return 0;
}