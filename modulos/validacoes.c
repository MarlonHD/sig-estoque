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