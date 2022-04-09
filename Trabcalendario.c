#include <stdio.h>                      //arrumando

int i; //mesreferencial
int j; //diareferencial
int cont = 0; 
int y, mes, dia, bis;
int g, c, x, z, e, d, n;
int mesDias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *months[]=
{
    "Janeiro",
    "Fevereiro",
    "Março",
    "Abril",
    "Maio",
    "Junho",
    "Julho",
    "Agosto",
    "Setembro",
    "Outubro",
    "Novembro",
    "Dezembro"
};

int main(int argc, char *argv[]) {//argc sugestao qude deu certo
scanf("%d",&y);                  
g = (y%19)+1;                             //%para pegar o resto
c = (y/100)+1;
x = ((3*c)/4)-12;
z = (((8*c)+5)/25)-5;
e =((11*g) + 20+z-x)%30;
if((e==25 && g>11)||(e==24)) 
e++;
n = 44-e;
if(n<21)
n=n+30;
d = ((5 * y)/4) - (x+10);                            
n = (n+7)-((d+n) % 7);
if(n>31){
    n = n -31;

    mes = 4;
    
}
    else{
    mes = 3;
        
    }
//algoritimo para saber se eh bissexto ou nao
if(y%100==0){
y=y/100;
}
    else if(y%4 == 0){
    bis = 1;
    mesDias[1] = 29;//Fevereiro(?)//
}
else {

    bis = 0;
}
//1 de janeiro
    if(mes == 4){
        dia = 8 - ((n + bis + 31 + 28 + 31 ) % 7) ; 
    }
    else if(mes == 3){
        dia = 8 - ((n + bis + 31 + 28) % 7) ;
    }
    if(dia > 6) dia -= 7;

    dia++;

    //Calendario
     printf("Calendario do ano %d\n", y);
for (i = 0; i < 12; i++) { // para cada mês
    int diaDaSemana = 0; // sttart domingo

    printf("|-----------------------------|\n");
    printf("|%-29s|\n", months[i]);
    printf("|-----------------------------|\n");
    printf("| dom seg ter qua qui sex sab |\n");
    printf("|");

    int linhasImpressas = 1; // quantidade de linhas que já foram impressas

    for (j = 0; j < dia - 1; j++) {
        printf("  --");
        diaDaSemana++;
    }

    // dias do mês
    for (int diaDoMes = 1; diaDoMes <= mesDias[i]; diaDoMes++) {
        printf("  %02d", diaDoMes);
        if (diaDaSemana >= 6) { // chegou no sábado, começar nova linha
            printf(" |\n|");
            diaDaSemana = 0;
            linhasImpressas++;
        } else diaDaSemana++;
    }
    dia = diaDaSemana + 1;

    if (linhasImpressas == 5) {    
        // preencher o que falta na quinta linha
        while (diaDaSemana <= 6) {
            printf("  --");
            diaDaSemana++;
        }
        // imprimir a sexta linha
        printf(" |\n|  --  --  --  --  --  --  -- |\n");
    } else if (linhasImpressas == 6) {
        // preencher o que falta na sexta linha
        for (int x = dia - 1; x <= 6; x++)
            printf("  --");
        printf(" |\n");
    }
}

    for(j = 1; j < mesDias[i] + 1; j++){

        if(j <= 9){

            if(cont >= 6){
                printf(" %d |\n|  ", j);
                cont = 0;
            }else{
                printf(" %d  ", j);
                cont++;
            }

        }else{
            if(j == 10){
                printf("%d", j);
                cont++;
            }else{
                printf("  %d", j);
                cont++;
            }           

            if(cont > 6){
                printf(" |\n|");
                cont = 0;
            }
        }

        if(cont > 6){
            printf("\n|  ");
            cont = 0;
        }
    }
    printf("|-----------------------------|");
    printf("\n");

    return 0;
}

