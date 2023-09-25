#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

struct Banco { 
    int numero_conta;  
    char nome_cliente[30]; 
    float saldo; 
    struct Banco *proximo; 
}; 
typedef struct Banco node;

int eh_vazia(node* CABECA_LISTA){
    // Função para verificar se a lista está vazia
    if (CABECA_LISTA->proximo == NULL)
    {
        printf("Lista vazia...\n");
        return 1;
    }else{return 0;}
}

node* cadastro(){
    // Função para cadastrar uma nova conta (Serve para facilitar a reusabilidade do código)
    node *novo_item = (node *)malloc(sizeof(node));
    if (novo_item == NULL) {
        fprintf(stderr, "Erro: falha na alocação de memória.\n");
        exit(1);
    }
    novo_item->proximo = NULL;
    printf("Insira o número da conta:");
    scanf("%d", &novo_item->numero_conta);
    printf("Insira o nome do Cliente(Máx 30 caracteres): ");
    scanf("%30s", &novo_item->nome_cliente);
    printf("Insira o valor do slado do cliente: R$");
    scanf("%f", &novo_item->saldo);
    return novo_item;
}

void inserir_fim(node* CABECA_LISTA, node* novo_item)
{
    // Função para inserir um nó no final da lista
    node* ultimo = CABECA_LISTA;
    while (ultimo->proximo != NULL)
    {
        ultimo = ultimo->proximo;
    }
    ultimo->proximo = novo_item;

    
}


void remover(node* CABECA_LISTA, int conta_to_remove)
{
    // Função para remover um nó com base no número da conta (considero que seja o melhor dos três atributos para busca)
    if (!eh_vazia(CABECA_LISTA))
    {
        node* anterior = CABECA_LISTA;
        node* to_remove = CABECA_LISTA->proximo;
        int encontrou = 0;
        while(to_remove->proximo != NULL)
        {
            if (to_remove->numero_conta == conta_to_remove)
            {
                encontrou = 1;
                break;
            }
            else
            {
                anterior = to_remove;
                to_remove = to_remove->proximo;
            }
        }
        if (encontrou)
        {
            printf("\nRemovendo %s...", to_remove->nome_cliente);
            anterior->proximo = to_remove->proximo;
            free(to_remove);

        }else{
            printf("Não encontrou");
        }
    }
    
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
            printf("\n-----------------------------------------");
            printf("\nEnd node: %d\n", aux);
            printf("Numero da conta: %d\n", aux->numero_conta);
            printf("Saldo da conta: %f\n", aux->saldo);
            printf("Nome cliente: %s\n", aux->nome_cliente);
            printf("End do prox: %d\n\n", aux->proximo);
            printf("\n-----------------------------------------");
            aux = aux->proximo;
        }
    }
}

int menu(int* opcao){
    printf("\nDigite 1 para Listar\n");
    printf("Digite 2 para Inserir no fim\n");
    printf("Digite 3 para Remover\n");
    printf("Digite 0 para Sair\n");
    scanf("%d", opcao);
    return *opcao;
}


int main()
{
	setlocale(LC_ALL, "");
    node* CABECA_LISTA = (node *) malloc(sizeof(node));
    CABECA_LISTA->proximo = NULL;
    int opt;
    int numero_conta;
    do
    {
        menu(&opt);
        switch(opt)
        {
            case 1:
                printf("Listando...\n");
                imprime(CABECA_LISTA);
                break;
            case 2:
                printf("Inserindo...\n");
                inserir_fim(CABECA_LISTA, cadastro());
                break;
            case 3:
                printf("Insira o número da conta a remover: ");
                scanf("%d", &numero_conta);
                remover(CABECA_LISTA, numero_conta);
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
