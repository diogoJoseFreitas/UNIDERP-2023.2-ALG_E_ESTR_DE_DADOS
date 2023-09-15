#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Lista
{
    int num;
    struct Lista *prox;
};
typedef struct Lista node;


void adicionaNode (node* cabeca)
{
    node *temp = cabeca;
    node *noh = (node*) malloc(sizeof(node));

    if (!noh){
        printf("Sem memoria suficiente");
        exit(1);
    }

    printf("Informe o valor Inteiro: ");
    scanf("%d", &noh->num);
    noh->prox = NULL;

    while(temp->prox != NULL){
        temp = temp->prox;
    }

    temp->prox = noh;
}

void imprimeNode(node* cabeca)
{
    node *temp = cabeca;
    while (temp->prox != NULL)
    {
        temp = temp->prox;
        printf(" - %d\n", temp->num);
    }
    
}

int main(int argc, char const *argv[])
{
    int i;
    node cab;
    cab.prox = NULL;

    printf("Quantos números você deseja inserir? ");
    scanf("%d", &i);


    for(i; i<10; i++){
        adicionaNode(&cab);
    }
    imprimeNode(&cab);

    

    return 0;
}

