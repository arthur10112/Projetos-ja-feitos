#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "restaurante.h"
#define N 2

void cadastra_restaurante(struct restaurante *r, int *qtd_rest,FILE *arquivo){
	int i,achou,codigo;
	
	achou = 0;
	codigo =1;
	for(i=0; i<*qtd_rest &&!achou; i++)
			if(r[i].codigo==codigo){
				printf("Codigo ja cadastrado.\n");
				achou = 1;
			}
	if(!achou) {
		(codigo)++;
		r[*qtd_rest].codigo = codigo;
		fflush(stdin);
		printf("Digite o nome do restaurante: ");
		gets(r[*qtd_rest].nomerestaurante);
		printf("Digite o nome do dono do restaurante: ");
		gets(r[*qtd_rest].dono);
		printf("Digite o endereco do restaurante: ");
		gets(r[*qtd_rest].endereco);
		printf("Digite a quantidade de entregadores: ");
		scanf("%d",&r[*qtd_rest].entregadores);
		(*qtd_rest)++;
	}
}

void lista_restaurante(struct restaurante *r, int qtd_rest, FILE *arquivo){
	int i;
	
	if(qtd_rest == 0)
		printf("Nao existem restaurantes cadastrados");
	else{
		printf("Restaurantes cadastrados: \n");
		for(i = 0; i < qtd_rest; i++)
			printf("\n%d  %s  %s  %s  %d  ",r[i].codigo, r[i].nomerestaurante, r[i].dono, r[i].endereco, r[i].entregadores);
			printf("\n");
	}
}

void atualiza_dados(struct restaurante *r, int qtd_rest,FILE *arquivo){
	
	int i, codigo, operacao;
	printf("Informe o codigo para atualizacao : ");
	scanf("%d",&codigo);
	for(i = 0 ; r[i].codigo != codigo && i < qtd_rest ; i++);
	if(i == qtd_rest)
		printf("Restaurante nao encontrado");
	else{//Tentar colocar o nome do restaurante aqui//
			printf("Dados atuais do restaurante: \n Dono: %s\n Endereco: %s\n Entregadores: %d\n",r[i].dono,r[i].endereco,r[i].entregadores);
			do{
				printf("Digite 1 para atualizar o endereco ou 2 para atualizar a quantidade de entregadores: \n");
				scanf("%d",&operacao);
				if(operacao !=1 && operacao !=2)
					printf("Operacao invalida.\n");					
			}while(operacao !=1 && operacao !=2);
			if(operacao = 1){
				fflush(stdin);
				printf("Digite o novo endereco do restaurante: ");
				gets(r[i].endereco);
			}
			else{
				printf("Digite o novo numero de entregadores: ");
				scanf("%d",&r[i].entregadores);
			}
	}
}
