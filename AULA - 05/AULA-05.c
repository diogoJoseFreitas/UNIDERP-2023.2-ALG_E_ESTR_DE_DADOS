#include <stdio.h>
#include <stdlib.h>


struct Lista
{
    int num;
    struct Lista *prox;
};
typedef struct Lista node;


int menu(){
    printf("1 - Imprimir\n");
    printf("2 - Inserir\n");
    printf("3 - Remover\n");
    printf("0 - Finalizar\n");
    int opcao;
    scanf("%d", &opcao);
    return opcao;
}

bool verificaLista(node* list_head){
    if (list_head->prox == NULL){
        printf("Lista Vazia! \n");
        return false;
    }
    else{
        return true;
    }
}

void imprimir(node* list_head){
    if (verificaLista(list_head))
    {
        node *aux = list_head->prox;
        do
        {
            printf("Valor: %d", aux->num);
        }while (aux->prox != NULL);
        
    }
    

}

void adicionar(node* list_head){
    node aux = *list_head;
    while (aux.prox != NULL)
    {
        printf("entrou aq");
        aux = *aux.prox;
    }
    node novo;
    aux.prox = &novo;
    novo.num = 10;
    novo.prox = NULL;
}


int main(int argc, char const *argv[])
{
    node cabeca;
    cabeca.prox = NULL;
    
    while (true){
        switch (menu())
        {
        case 1:
            printf("Opcao 1 selecionada\n");
            imprimir(&cabeca);
            break;
        case 2:
            printf("Opcao 2 selecionada\n");
            adicionar(&cabeca);
            break;
        case 3:
            printf("Opcao 3 selecionada\n");
            break;
        case 0:
            printf("Opcao 0 selecionada (Cadu quem fez)\n");
            return 0;
            break;
        default:
            printf("Opcao Invalida.\n");
            break;
        }
    }
    return 0;
}
