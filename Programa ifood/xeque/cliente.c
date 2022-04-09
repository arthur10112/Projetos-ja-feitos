#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "cliente.h"
#define N 2

void cadastra_cliente(struct cliente *r, int *qtd_clien,FILE *arquivo){
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
		r[*qtd_clien].codigo = codigo;
		fflush(stdin);
		printf("Digite seu nome: ");
		gets(r[*qtd_clien].nomerestaurante);
		printf("Digite o seu cpf: ");
		gets(r[*qtd_clien].cpf);
		printf("Digite seu endereco: ");
		gets(r[*qtd_clien].endereco);
		printf("Digite o numero do seu cartao: ");
		scanf("%d",&r[*qtd_clien].numcartao);
		(*qtd_clien)++;
	}
}

void atualiza_dados(struct cliente *r, int qtd_clien,FILE *arquivo){
	
	int i, codigo, operacao;
	printf("Informe o codigo para atualizacao : ");
	scanf("%d",&codigo);
	for(i = 0 ; r[i].codigo != codigo && i < qtd_clien ; i++);
	if(i == qtd_clien)
		printf("Cliente nao encontrado");
	else{//Tentar colocar o nome do restaurante aqui//
			printf("Seus dados atuais: \n Nome: %s\n Cpf: %d\nEndereco: %s\n Numero do Cartao: %d\n",r[i].nomecliente,r[i].cpf,r[i].endereco,r[i].numcartao);
			do{
				printf("Digite 1 para atualizar o endereco ou 2 para atualizar a quantidade de entregadores: \n");
				scanf("%d",&operacao);
				switch (operacao)
				{
					case 1:
					fflush(stdin);
				printf("\nDigite o seu nome: ");
				gets(r[i].nomecliente);
				break	;
					
					case 2:
					printf("\nDigite o seu cpf: ");
				scanf("%d",r[i].cpf);
				break;
					
					case 3:
				    printf("\nDigite o seu endereco: ");
				gets(r[i].endereco);
				break;
				
				    case 4:
				    printf("\nDigite o numero do seu cartao: ");
				scanf("%d",r[i].numcartao);
				break;
						}		
			}while(operacao != 5);
			}
	}
}
