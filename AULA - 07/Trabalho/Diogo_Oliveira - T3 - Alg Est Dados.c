#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct Banco {
int numero;
struct Banco *anterior;
struct Banco *proximo;
};
typedef struct Banco node;


// [ ] Menu (1- Exibir lista\n2- Adicionar node\n3- Remove node da lista\n0- Sair)
// [x] Função "aloca()"
// [x] Função "vazia()"
// [x] Função "imprime()"
// [x] Função "insere_inicio()"
// [ ] Função "remove_node()"


node* aloca(){
    // Função para verificar a possibilidade de criar um novo node e encerrar caso ocorra estouro de memória
    node *novo_item = (node *)malloc(sizeof(node));
    if (!novo_item) {
        printf("Erro: falha na alocação de memória.\n");
        exit(1);
    }
    novo_item->anterior = NULL;
    novo_item->proximo = NULL;
    return novo_item;
}

node* cadastro(){
    int novo_numero;
    // Separei a parte de cadastro da alocação de memória para poder alocar o espaço sem necessariamente cadastrar alguma conta
    // Função para cadastrar novo item para possível inserção na lista
    node* novo_item = aloca();
    novo_item->anterior = NULL;
    novo_item->proximo = NULL;
    printf("Insira o número da conta:");
    scanf("%d", &novo_numero);
    novo_item->numero = novo_numero;
    printf("Cadastrado.\n");
    return novo_item;
}

int vazia(node* CABECA_LISTA){
    // Função para verificar se a lista está vazia
    if (CABECA_LISTA->proximo == NULL){
        printf("Lista vazia...\n");
        return 1;
    }else return 0;
}

void insere_inicio(node* CABECA){
    // Função para inserir no início da lista
    node* novo = cadastro();
    node* temp = CABECA->proximo;
    if (temp != NULL){
        temp->anterior = novo;
    }
    CABECA->proximo = novo;
    novo->proximo = temp;
}

void imprime(node* CABECA_LISTA){
    // Função para imprimir todos os itens da lista, informa quando estiver vazia
    if(!vazia(CABECA_LISTA)){
        node* aux = CABECA_LISTA->proximo;
        while(aux != NULL){
            printf("\n-----------------------------------------");
            printf("\nEnd node: %d\n", aux);
            printf("Numero da conta: %d\n", aux->numero);
            printf("End do prox: %d\n", aux->proximo);
            printf("\n-----------------------------------------\n");
            aux = aux->proximo;
        }
    }
}

void remove_node(node* CABECA_LISTA){
    // Função para remover um nó com base no número da conta (considero que seja o melhor dos três atributos para busca)
    int numero_para_remover;
    printf("Insira o número da conta a ser Removida: ");
    scanf("%d", &numero_para_remover);
    printf("Buscando conta...\n");
    if (!vazia(CABECA_LISTA)){
        node* to_remove = CABECA_LISTA->proximo;
        int encontrou = 0;
        do{
            if (to_remove->numero == numero_para_remover){
                printf("Encontrou\n");
                encontrou = 1;
                break;
            }
            else{
                to_remove = to_remove->proximo;
            }
        }while(to_remove->proximo != NULL);
        if(encontrou){
            printf("\nNode a ser removido\n");
            printf("Conta do Cliente: %d\n", to_remove->numero);
            printf("Endereço do node ant: %d | Endereço do node: %d | Endereço do próximo node: %d\n", to_remove->anterior, to_remove, to_remove->proximo);
            node* ant = to_remove->anterior;
            node* prox = to_remove->proximo;
            if(ant != NULL){
                ant->proximo = prox;
            }
            if(prox != NULL){
                prox->anterior = ant;
            }
            free(to_remove);
        }else{
            printf("\n\nNão encontrou %d.\n\n", numero_para_remover);
        }
    }
}

void menu(){
    printf("1- Exibir lista\n2- Adicionar node\n3- Remove node da lista\n0- Sair\n");
}

int main(){
	setlocale(LC_ALL, "");
    node* CABECA = aloca();
    int opcao;
    do{
        menu();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\n\nImprimindo Lista...\n\n");
            imprime(CABECA);
            break;
        case 2:
            printf("\n\nAdicionando node...\n\n");
            insere_inicio(CABECA);
            break;
        case 3:
            printf("\n\nRemovendo node...\n\n");
            remove_node(CABECA);
            break;
        case 0:
            printf("\n\nEncerrando Programa...");
            break;
        default:
            printf("\n\nFavor inserir opção Válida.\n\n");
            break;
        }

    } while (opcao != 0);
    return 0;
}

