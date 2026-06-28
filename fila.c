#include <stdio.h>
#include <stdlib.h>
#include "main.c"

#define TAMANHO_MAX 5 // Define o tamanho máximo das filas

typedef struct {
    Processo itens[TAMANHO_MAX];
    int inicio;
    int fim;
    int totalItens;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->totalItens = 0;
}

int estaCheia(Fila *f) {
    return (f->totalItens == TAMANHO_MAX);
}

int estaVazia(Fila *f) {
    return (f->totalItens == 0);
}

void enfileirar(Fila *f, Processo p) {
    if (estaCheia(f)) {
        printf("Erro: A fila esta cheia! Nao foi possivel inserir o Processo P%d.\n", p.id);
        return;
    }
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % TAMANHO_MAX;
    f->totalItens++;
}

// Retorna o Processo inteiro ao invés de int
Processo desenfileirar(Fila *f) {
    if (estaVazia(f)) {
        printf("Erro: A fila esta vazia!\n");
        Processo erro = {-1, 0, 0, 0, 0, 0, SEM_IO};
        return erro;
    }
    Processo valorItem = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % TAMANHO_MAX;
    f->totalItens--;
    return valorItem;
}

void exibirFila(Fila *f) {
    if (estaVazia(f)) {
        printf("[ Fila Vazia ]\n");
        return;
    }
    printf("Fila de Prontos: ");
    int indice = f->inicio;
    for (int i = 0; i < f->totalItens; i++) {
        printf("P%d ", f->itens[indice].id);
        indice = (indice + 1) % TAMANHO_MAX;
    }
    printf("\n");
}