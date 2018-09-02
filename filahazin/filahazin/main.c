//
//  main.c
//  filahazin
//
//  Created by Thiago Moraes on 02/09/2018.
//  Copyright © 2018 Thiago Moraes. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct fila_de_pessoas{
    int ntotal;
    struct pessoa *primeiro;
    struct pessoa *ultimo;
} fila;

typedef struct pessoa_na_fila{
    int num;
    struct pessoa_na_fila *prox;
} pessoa;

struct fila_de_pessoas *criarfila(){
    fila *temporaria = (fila*)malloc(sizeof(fila));
    temporaria->primeiro = NULL;
    temporaria->ultimo = NULL;
    temporaria->ntotal = 0;
    return temporaria;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
