#include <stdio.h>
#include <stdlib.h>
#include "validacoes.h"

int validBarCode(char *codigo){
    int tam = 14;
    int code[tam];
    int cont = -1;
    int verif, soma=0;
    do{
        cont++;
    }while(codigo[cont] >= '0' && codigo[cont] <= '9');

    if(cont>tam){
        return 0;
    }

    for(int i = 0; i<tam; i++){
        if(i < tam-cont){
            code[i] = 0;
        }else{
            code[i] = (codigo[i-tam+cont] - 48);
        }
    }

    verif = code[13];

    for(int i = 0; i<tam-1; i++){
        if(i%2 == 1){
            soma += (3*code[i]);
        }else{
            soma += code[i];
        }
    }

    if((10-soma%10) == verif){
        return 1;
    }else{
        return 0;
    //    printf("soma: %d \nverif: %d\n",soma, (10 - soma%10));
    }
    
}

/*
int main(void){

    char codigo[20];

    printf("Digite o codigo de barras:   ");
    scanf("%s",codigo);
    getchar();

    if(!validBarCode(codigo)){
        printf("Inválido");
    }else{
        printf("Valido\n");
    }

    return 0;
}*/


/* ----------------- EM DESENVOLVIMENTO -----------------*/
char cnpj[15];// Variável cnpj
int somaDV1 , somaDV2, divisao1, divisao2, DV1, DV2, i;

void validacnpj(void){
    printf("Cnpj (Apenas numeros): ");
    scanf("%s", &cnpj);

for ( i = 0; i < 15; i++)
{   (cnpj[i] - '0');
   
}

somaDV1 =((cnpj[0] * 5) + (cnpj[1] * 4) +(cnpj[2] * 3) +
    (cnpj[3] * 2) + (cnpj[4] * 9) + (cnpj[5] * 8) +
    (cnpj[6] * 7) + (cnpj[7] * 6) +  (cnpj[8] * 5) +
    (cnpj[9] * 4) + (cnpj[10] * 3) + (cnpj[11] * 2));
//calculos DV1
divisao1 = (somaDV1 % 11); //resto

if (divisao1 < 2) 
DV1 = 0;
else
DV1 = (11 - divisao1);


somaDV2 =((cnpj[0] * 6) + (cnpj[1] * 5) +(cnpj[2] * 4) +
    (cnpj[3] * 3) + (cnpj[4] * 2) + (cnpj[5] * 9) +
    (cnpj[6] * 8) + (cnpj[7] * 7) +  (cnpj[8] * 6) +
    (cnpj[9] * 5) + (cnpj[10] * 4) + (cnpj[11] * 3) + (DV1 * 2));
divisao2 = (somaDV2 % 11); //resto

if (divisao2 < 2) 
DV2 = 0;
else
DV2 = (11 - divisao2);
    
if (DV1 == cnpj[13] && DV2 == cnpj[14])
printf("CNPJ Válido!");
else
printf("CNPJ Inválido!");
}