#include <stdio.h>
#include <stdlib.h>

int elementos;
int valores;
int deixaram;
int ident;
int tamanho;

 struct Node{
        int num;
        struct Node *prox
    };
    typedef struct Node node;

node *lista_cria(void){
    return NULL;
    tamanho = 0;
    }

node *lista_insere(node *lista, int valor){
    node *novo = (node*) malloc(sizeof(node));
    novo -> num = valor;
    novo -> prox = lista;
    return novo;
}
void lista_imprime(node* lista){
node* p;
for (p = lista; p!=NULL; p = p-> prox){
    printf("%d ", p-> num);
    }
}

node* lista_retira(node* lista, int valor){
    node* a = NULL;
    node* p = lista;

    while (p!= NULL && p->num != valor){
        a = p;
        p = p->prox;

        if (p == NULL)
            return lista;
        if (a == NULL)
            lista = p->prox;
        else
            a-> prox = p->prox;
        free(p);
        return lista;
    }
    if (lista->prox != NULL){
        node *tmp = lista-> prox;
        lista-> prox = tmp-> prox;
        tamanho--;
        return tmp;

        node *ultimo = lista -> prox, *penultimo = lista;
    while (ultimo -> prox !=NULL){
            penultimo = ultimo;
            ultimo = ultimo-> prox;
        }

        penultimo->prox = NULL;
        tamanho--;
        return ultimo;
    }
}

int main(){
    int i = 0;
    int j = 0;
    node *lista;
    lista = lista_cria();

    printf("Digite a quantidade de pessoas na fila");
    scanf("%i", &elementos);

    printf("Digite os identificadores dessas pessoas:");
    while (i < elementos){
    scanf("%i", &valores);
    lista = lista_insere(lista, valores);
    ++i;
    }
    lista_imprime(lista);

    printf("Quantas pessoas deixaram a fila?");
    scanf("%i", &deixaram);

    printf("Quais os identificadores dos que deixaram a fila?");
    while (j < deixaram){
    scanf("%i", &ident);
    lista = lista_retira(lista, ident);
    ++j;
    }
    lista_imprime(lista);
    return 0;
}
