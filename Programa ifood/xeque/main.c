#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "restaurante.h"
#include "cliente.h"

#define N 2

int main() {
	struct restaurante *rest;//declaracao de variavel do tipo struct restaurante//
	struct cliente *clien;
	int opcao, qtd_rest, qtd_memoria;
	
	rest = (struct restaurante *)malloc(N * sizeof(struct restaurante));
	FILE *restaurante;
	restaurante = fopen("restaurante.dat" , "rb");
	if(restaurante != NULL) {
					fread(&qtd_rest, sizeof(int),1,restaurante);
					fread(rest, sizeof(struct restaurante),qtd_rest, restaurante);
					fclose(restaurante);					
					} 
	
	else{
			qtd_rest = 0 ;
	}
	if(!rest)
	printf("Memoria insuficiente.\n");
	
	else{
			qtd_memoria = N;
			qtd_rest = 0;//A principio nao existem mercadorias cadastradas//
		do{
			
			printf("Escolha uma opcao: \n");
			printf("1. Cadastrar restaurante \n");
			printf("2. Listar restaurantes \n");
			printf("3. Atualizar dados \n");
			printf("4. Sair\n");
			scanf("%d", &opcao);
			switch(opcao) {
				
				case 1:
					   if(qtd_rest == qtd_memoria) { //caso memoria insuficiente,necessario realocar//
					   	qtd_memoria = qtd_memoria + N;
					   	rest = (struct restaurante *)realloc(rest, qtd_memoria * sizeof(struct restaurante));
					   	if(!rest)
					   	printf("Memoria insuficiente.\n");
					   	else
					   		cadastra_restaurante(rest, &qtd_rest,restaurante);
					   } else
					   		cadastra_restaurante(rest,&qtd_rest,restaurante);
				break;
				case 2:
					lista_restaurante(rest,qtd_rest,restaurante);
				break;
				case 3:
					  atualiza_dados(rest,qtd_rest,restaurante);
				break;
				default:
						if(opcao != 4)
							printf("Opcao invalida.\n ");
			}
		}while(opcao!=4);
		restaurante = fopen("restaurante.dat","wb");
		if(restaurante ==NULL)
			printf("Erro na criacao do arquivo.Nao foi possivel gravar os registros.");
			else{
				fwrite(&qtd_rest,sizeof(int),1,restaurante);
				fwrite(rest,sizeof(struct restaurante),qtd_rest,restaurante);
				fclose(restaurante);//Libera a memoria//
			}
	}
	free(rest);
}
