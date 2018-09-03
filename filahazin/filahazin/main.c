//
//  main.c
//  filahazin
//
//  Created by Thiago Moraes on 02/09/2018.
//  Copyright © 2018 Thiago Moraes. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa_na_fila{
    int num;
    struct pessoa_na_fila *prox;
}pessoa;

typedef struct fila_de_pessoas{
    int ntotal;
    pessoa *primeiro;
    pessoa *ultimo;
}fila;

struct fila_de_pessoas *criarfila(){
    fila *temporaria = (fila*)malloc(sizeof(fila));
    temporaria->primeiro = NULL;
    temporaria->ultimo = NULL;
    temporaria->ntotal = 0;
    return temporaria;
}

void entrarfila(fila *filatemp, int valor){
    pessoa *novapessoa = (pessoa*)malloc(sizeof(pessoa));
    novapessoa->num = valor;
    novapessoa->prox = NULL;
    if(filatemp->ntotal == 0){
        filatemp->primeiro = novapessoa;
        filatemp->ultimo = novapessoa;
    }
    filatemp->ultimo->prox = novapessoa;
    filatemp->ultimo = novapessoa;
    filatemp->ntotal = (filatemp->ntotal) + 1;
    
}

void sairdafila(fila *filatemp, int valor){
    pessoa *pessoatemp = filatemp->primeiro;
    pessoa *anterior = NULL;
    while (pessoatemp != NULL) {
        if (pessoatemp->num == valor){
            if (anterior == NULL) {
                filatemp->primeiro = pessoatemp->prox;
            }
            else{
                anterior->prox = pessoatemp->prox;
            }
            filatemp->ntotal = (filatemp->ntotal) - 1;
            return;
        }
        anterior = pessoatemp;
        pessoatemp = pessoatemp->prox;
    }
    return;
}

int main(void) {
    fila *filacopa = criarfila();
    int n = 0, m = 0, i, j;
    int identificador;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%d",&identificador);
        entrarfila(filacopa, identificador);
    }
    scanf("%d", &m);
    for (j = 0; j < m; j++) {
        scanf("%d", &identificador);
        sairdafila(filacopa, identificador);
    }
    pessoa *filafinal = filacopa->primeiro;
    int fim = n - m;
    for (i = 0; i < fim; i++) {
        if(filafinal->prox == NULL){
            printf("%d", filafinal->num);
        }else{
            printf("%d ", filafinal->num);
            filafinal = filafinal->prox;
        }
    }
    return 0;
}
