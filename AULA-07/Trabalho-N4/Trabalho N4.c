#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


struct Compactador {
char letra;
int quantidade;
struct Compactador *proximo;
};
typedef struct Compactador node;


node* aloca(){
    // Função para verificar a possibilidade de criar um novo node e encerrar caso ocorra estouro de memória
    node *novo_item = (node *)malloc(sizeof(node));
    if (!novo_item) {
        printf("Erro: falha na alocação de memória.\n");
        exit(1);
    }
    novo_item->proximo = NULL;
    return novo_item;
}

node* novo(char caracter){
    // Inicializa novo item com o caracter indicado
    node* novo_item = aloca();
    novo_item->letra = caracter;
    novo_item->quantidade = 1;
    return novo_item;
}

node* ultimo(node* CABECA){
    // Retorna o último node da lista
    node* aux = CABECA;
    while (aux->proximo != NULL){
        aux = aux->proximo;
    }
    return aux;
}

void insere_fim(node* CABECA, node* novo_item){
    // Apenas para quando tiver certeza de insersção nova na lista
    node* aux = ultimo(CABECA);
    aux->proximo = novo_item;    
}

void adicionar(node* CABECA, char caractere){
    node* aux = ultimo(CABECA);
    if (caractere != aux->letra){
        insere_fim(CABECA, novo(caractere));
    }else{
        aux->quantidade++;
    }
}

int quant_digitos(int numero){
    int contador = 0;
    while (numero != 0){
        numero /= 10;
        contador++;
    }
    return contador;
}

int imprime(node* CABECA){
    // Função para imprimir o resultado da compressão
    node* aux = CABECA;
    int contador = 0;
    while (aux->proximo!=NULL){
        aux = aux->proximo;
        if (aux->quantidade>1){
            contador += quant_digitos(aux->quantidade);            
            printf("%d", aux->quantidade);
        }
        printf("%c", aux->letra);
        contador ++;
    }
    printf("\n");
    return contador;
}
int main(int argc, char const *argv[]){
    node* CABECA = aloca();
    float divisao;
    char original[100];
    // char original[100] = "BBBEAAAAFFHHHHHCBMMALLLCDDBBBBBBBCC";
    printf("Informe o texto a ser compactado:\n");
    scanf("%100s", &original);

    float peso_original = (float)strlen(original);
    int i;
    for(i = 0; i < peso_original; i++){
        // printf("%c", original[i]);
        adicionar(CABECA, original[i]);
    }


    printf("\nTexto apos a compactacao: \n");
    float peso_compactado = (float)imprime(CABECA);

    // printf("\nPeso Original %.2f\n", peso_original);
    // printf("Peso Compactado %.2f\n", peso_compactado);

    divisao = peso_compactado*100/peso_original;
    printf("\nApos a compactacao obteve-se uma reducao de %.2f%%", 100-divisao);

    return 0;
}
