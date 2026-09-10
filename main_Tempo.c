#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define REP 100  //quantidade de repeticoes

int *inversao(int vetor[], int n);
void buscaSequencial(int vetor[], int n, int s);
void buscaBinaria(int vetor[], int n, int s);
void buscaBinariaRecursiva(int vetor[], int L, int R, int s);

int main() {

    LARGE_INTEGER frequencia, inicio, fim;  //variaveis necessarias para contar o tempo
    QueryPerformanceFrequency(&frequencia); //constante
    double tempo_medio = 0.0;
    char *nome_algoritmo = ""; //pra exibir no final, na hora de gerar o printf


    // entrada do tamanho do vetor.
    int n;
    scanf("%d", &n);
    int *V = malloc (n * sizeof(int));
    
    // Preenchimento do vetor
    for(int i = 0; i < n; i++){
        scanf("%d", &V[i]);
    }

    // Continuidade das operações até encerramento com do-while
    int opcao = 0;                                                     
    do{
        // Leitura da opção escolhida
        scanf("%d", &opcao);
        
        // Estrutura de Condição para decisão da operação
        if(opcao == 1){
            nome_algoritmo = "inversao";
            QueryPerformanceCounter(&inicio);

            for (int cont = 0; cont < REP; cont++){
                int *vetorInvertido = inversao(V, n);  
                free(vetorInvertido);
            }

            QueryPerformanceCounter(&fim);

        } else if(opcao == 2){                          
            nome_algoritmo = "busca_sequencial";
            QueryPerformanceCounter(&inicio);
  
            int s = 0;
            //entrada do valor procurado
            scanf("%d", &s);
            
            for (int cont = 0; cont < REP; cont++){
                buscaSequencial(V, n, s);
            }
        
            QueryPerformanceCounter(&fim);

        } else if(opcao == 3){                       
            nome_algoritmo = "busca_binairia_iterativa";
            QueryPerformanceCounter(&inicio);

            int s = 0;
            //entrada do valor procurado
            scanf("%d", &s);

            for (int cont = 0; cont < REP; cont++){
                buscaBinaria(V, n, s);
            }

            QueryPerformanceCounter(&fim);
           
        } else if(opcao == 4){                           
            nome_algoritmo = "busca_binairia_recursiva";
            QueryPerformanceCounter(&inicio);

            int s = 0;
            //entrada do valor procurado
            scanf("%d", &s);

            for (int cont = 0; cont < REP; cont++){
                buscaBinariaRecursiva(V, 0, n-1, s);
            }
            
            QueryPerformanceCounter(&fim);
        } 

    } while(opcao != 5);

    tempo_medio = (double)(fim.QuadPart - inicio.QuadPart)/frequencia.QuadPart/REP;
    printf("%s, %d, %.9f\n", nome_algoritmo, n, tempo_medio);
    
    free(V);
    return 0;
}

int *inversao(int vetor[], int n){

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
            return;
        }

    } 

    // Como função ainda não foi encerrada, o valor não está no vetor
    return;
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

    return;
}

void buscaBinariaRecursiva(int vetor[], int L, int R,int s){

    if(L > R) {
        return;
    }

    int meio = L + (R - L) / 2;

    if(vetor[meio] == s){
        return;
    }

    if(vetor[meio] > s){
        return buscaBinariaRecursiva(vetor, L, meio-1, s);
    } 
        return buscaBinariaRecursiva(vetor, meio+1, R, s);

}