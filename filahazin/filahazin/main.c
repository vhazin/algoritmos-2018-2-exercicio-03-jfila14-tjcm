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
    struct pessoa_na_fila *ant;
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
        novapessoa->ant = NULL;
        filatemp->primeiro = novapessoa;
        filatemp->ultimo = novapessoa;
    }
    novapessoa->ant = filatemp->ultimo;
    filatemp->ultimo->prox = novapessoa;
    filatemp->ultimo = novapessoa;
    
}

void sairdafila(fila *filatemp, int valor){
    pessoa *pessoatemp = filatemp->primeiro;
    if (pessoatemp == NULL) {
        return;
    }
    while (pessoatemp->prox != NULL) {
        if (pessoatemp->num == valor && pessoatemp == filatemp->primeiro) {
            filatemp->primeiro = filatemp->primeiro->prox;
            filatemp->primeiro->ant = NULL;
            filatemp->ntotal = filatemp->ntotal - 1;
            return;
        }
        else if (pessoatemp->num == valor){
            pessoatemp->ant->prox = pessoatemp->prox;
            filatemp->ntotal = filatemp->ntotal - 1;
            return;
        }
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
