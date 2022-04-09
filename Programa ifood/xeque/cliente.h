#ifndef _CLIENTE_H
#define _CLIENTE_H
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct cliente {
	int codigo;
	char nomecliente[50];
	int cpf;
	char endereco[50];
	int numcartao;
};

void cadastra_restaurante(struct cliente *, int * , FILE *arquivo);
void atualiza_dados(struct cliente *,  int ,FILE *arquivo);

#endif

