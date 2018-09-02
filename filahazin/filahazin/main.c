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
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
