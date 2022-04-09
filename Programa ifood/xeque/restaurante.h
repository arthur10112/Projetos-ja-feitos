#ifndef _RESTAURANTE_H
#define _RESTAURANTE_H
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct restaurante {
	int codigo;
	char nomerestaurante[50];
	char endereco[50];
	char dono[50];
	int entregadores;
};

void cadastra_restaurante(struct restaurante *, int * , FILE *arquivo);
void lista_restaurante(struct restaurante*, int ,FILE *arquivo);
void atualiza_dados(struct restaurante *,  int ,FILE *arquivo);

#endif

