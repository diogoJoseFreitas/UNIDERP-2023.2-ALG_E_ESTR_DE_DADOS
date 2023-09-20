#include<stdio.h>
#include<stdlib.h>

struct Banco { 
    int numero_conta;  
    char nome_cliente[30]; 
    float saldo; 
    struct Banco *proximo; 
}; 
typedef struct Banco node;  


void inserir_fim(node* CABECA_LISTA)
{
    //TODO
}


void remover(node* CABECA_LISTA)
{
    //TODO
}


void imprime(node* CABECA_LISTA)
{
    if(CABECA_LISTA->proximo == NULL)
    {
        printf("Lista vazia...\n");
    }else
    {
        node* aux = CABECA_LISTA->proximo;
        while(aux != NULL)
        {
            printf("\nEnd node: %d\n", aux);
            printf("Numero da conta: %d\n", aux->numero_conta);
            printf("Saldo da conta: %f\n", aux->saldo);
            printf("Nome cliente: %s\n", aux->nome_cliente);
            printf("End do prox: %d\n\n", aux->proximo);
            aux = aux->proximo;
        }
    }
}


int main()
{
    node* CABECA_LISTA = (node *) malloc(sizeof(node));
    CABECA_LISTA->proximo = NULL;

    int opt;
    do
    {
        printf("\nDigite 1 para Listar\n");
        printf("Digite 2 para Inserir\n");
        printf("Digite 3 para Remover\n");
        printf("Digite 0 para Sair\n");
        scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                printf("Listando...\n");
                imprime(CABECA_LISTA);
                break;
            case 2:
                printf("Inserindo...\n");
                inserir_fim(CABECA_LISTA);
                break;
            case 3:
                printf("Removendo...\n");
                remover(CABECA_LISTA);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida...\n");
        }
    }while(opt > 0);
    return 0;
}
