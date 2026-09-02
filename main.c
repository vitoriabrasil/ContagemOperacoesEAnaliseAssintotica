/*
PEQUENO MENU

CONTABILIZAR TEMPO MEDIO DE EXECUCAO PARA DIFERENTES ENTRADAS

CONSTRUIR UM GRAFICO A PARTIR DISSO

CONTABILIZAR EXPERIMENTALMENTE SUAS OPERAÇOES 

ANALISE ASSINTOTICA DOS CASOS: PIOR, MEDIO E MELHOR
*/


#include <stdio.h>
#include <stdlib.h>


int *inversao(int vetor[], int n);
void buscaSequencial(int vetor[], int n, int s);
void buscaBinaria(int vetor[], int n, int s);
void buscaBinariaRecursiva(int vetor[], int L, int R, int s);


int main() {

    

    printf("Entre com o tamanho do vetor: \n");
    // Declaração de Variáveis e entrada do tamanho do vetor.
    int n;
    scanf("%d", &n);
    int V[n];
    
    printf("Entre com o vetor: \n");
    // Preenchimento do vetor
    for(int i = 0; i < n; i++){
        scanf("%d", &V[i]);
    }

    // Continuidade das operações até encerramento com do-while

    int opcao = 0;

    do{

        // MENU 
        printf("\n(1) Inversao de ordem do vetor de entrada\n");
        printf("(2) Busca Sequencial no vetor de entrada\n");
        printf("(3) Busca Binaria Iterativa no vetor de entrada\n");
        printf("(4) Busca Binaria Recursiva no vetor de entrada\n");
        printf("(5) Encerrar o programa\n");
        printf("-> ");

        // Leitura da opção escolhida

        scanf("%d", &opcao);
        
        // Estrutura de Condição para decisão da operação
        if(opcao == 1){
            int *vetorInvertido = inversao(V, n);
            printf("Vetor invertido: \n");
            for(int i = 0; i < n; i++){
                printf("%d", vetorInvertido[i]);
            }
             printf("\n");

        } else if(opcao == 2){
            int s = 0;
            printf("Entre com o valor procurado: \n");
            scanf("%d", &s);
            buscaSequencial(V, n, s);

        } else if(opcao == 3){
            int s = 0;
            printf("Entre com o valor procurado: \n");
            scanf("%d", &s);
            buscaBinaria(V, n, s);

        } else if(opcao == 4){
            int s = 0;
            printf("Entre com o valor procurado: \n");
            scanf("%d", &s);
            buscaBinariaRecursiva(V, 0, n-1, s);
        } 

    } while(opcao != 5);



    
   
    return 0;

}

int *inversao(int vetor[], int n){

        /*
            Esta é a função pela qual ocorre a inversão do vetor. Começamos a percorrer o vetor inicial da direita
            para a esquerda, ao passo que o Vetor Invertido é preenchido, com os valores encontrados no vetor inicial, da esquerda para a direita.
        */
        int *vetorInvertido = malloc(sizeof(int)*n);
        int i = n - 1;
        int j = 0;
        while(i >= 0){
            vetorInvertido[j] = vetor[i];
            i--;
            j++;
        }
        return vetorInvertido;
}


void buscaSequencial(int vetor[], int n, int s){


    // Estrutura de busca sequencial: 
    for(int i = 0; i < n; i++){
        if(vetor[i] == s){
            // Função encerrada, caso valor seja encontrado
            printf("\nSIM. \n");
            return;
        }
    } 

    // Como função ainda não foi encerrada, o valor não está no vetor
    printf("\nNÃO.\n");
    return ;
}

void buscaBinaria(int vetor[], int n, int s){
    
    // Ponteiros para a direita e para a esquerda
    int L = 0;
    int R = n - 1;
    int meio = 0;

    while(L <= R){
        // Encontrando novo meio
         meio = L + (R - L) / 2;

        if(vetor[meio] == s){
            // Caso a posição cotenha o valor procurado, ela é encerrada
            printf("\nSIM. \n");
            return;
        }

        if(vetor[meio] > s){
            // Caso o meio seja maior que o valor a ser encontrado, é preciso ir para a esquerda,
            // Assim, o Right é decrementado (teto).
            R = meio - 1;
        } else {
            // Caso o meio seja menor que o valor a ser encontrado, é preciso andar para 
            // a direita, assim o valor de Left é incrementado (chao).
            L = meio + 1;
        }


    }

    printf("\nNÃO.\n");
    return;
}

void buscaBinariaRecursiva(int vetor[], int L, int R,int s){

    int meio = L + (R - L) / 2;

    if(L > R) {
        printf("\nNÃO.\n");
        return;
    }

    if(vetor[meio] == s){
        printf("\nSIM.\n");
        return;
    }

    if(vetor[meio] > s){
        return buscaBinariaRecursiva(vetor, L, meio-1, s);
    } 
        return buscaBinariaRecursiva(vetor, meio+1, R, s);


}