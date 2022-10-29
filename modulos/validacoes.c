#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacoes.h"

int validBarCode(char *codigo){
    limpaTexto(codigo);
    int tam = 13;
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

    verif = code[12];

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


void validacnpj(void){
    char cnpj[14];// Variável cnpj
    int cnpjInt[14]; // Vetor inteiro cnpj
    int somaDV1 , somaDV2, divisao1, divisao2, DV1, DV2;
   
    printf("Cnpj (Apenas numeros): "); 
    scanf("%s", &cnpj);  // Pega o cnpj

    for(int i = 0; i < 14; i++){  // Converte o cnpj pra int
        cnpjInt[i] = cnpj[i] - 48;
    }

somaDV1 =((cnpjInt[0] * 5) + (cnpjInt[1] * 4) +(cnpjInt[2] * 3) +  // Contas do Dígito Verificador 1
         (cnpjInt[3] * 2) + (cnpjInt[4] * 9) + (cnpjInt[5] * 8) +
         (cnpjInt[6] * 7) + (cnpjInt[7] * 6) +  (cnpjInt[8] * 5) +
         (cnpjInt[9] * 4) + (cnpjInt[10] * 3) + (cnpjInt[11] * 2));
    

    divisao1 = (somaDV1 % 11); //resto

    if (divisao1 < 2) 
        DV1 = 0;
    else
        DV1 = (11 - divisao1);


somaDV2 =((cnpjInt[0] * 6) + (cnpjInt[1] * 5) +(cnpjInt[2] * 4) +  // Contas do Dígito Verificador 2
        (cnpjInt[3] * 3) + (cnpjInt[4] * 2) + (cnpjInt[5] * 9) +
        (cnpjInt[6] * 8) + (cnpjInt[7] * 7) +  (cnpjInt[8] * 6) +
        (cnpjInt[9] * 5) + (cnpjInt[10] * 4) + (cnpjInt[11] * 3) + (DV1 * 2));
    divisao2 = (somaDV2 % 11); //resto

    if (divisao2 < 2) 
        DV2 = 0;
    else
        DV2 = (11 - divisao2);
    

    if (DV1 == cnpjInt[12] && DV2 == cnpjInt[13])
        printf("CNPJ Válido!");
    else
        printf("CNPJ Inválido!");
}


//---| Validações String |---
int isDigit(char n){
    if(n >= '0' && n <= '9'){
        return 1;
    }else{
        return 0;
    }
}

int isLetra(char c){
    if((c >= 'a' && c<= 'z') || (c >= 'A' && c <= 'Z')){
        return 1;
    }else{
        return 0;
    }
}


int contChar(char *texto, char c){
    int tam = strlen(texto);
    int cont = 0;
    for(int i = 0; i<tam; i++){
        if(texto[i] == c){
            cont++;
        }
    }
    return cont;
}

int contnChar(char *texto, char c, int n){
    int tam = strlen(texto);
    int cont = 0;
    for(int i = n; i<tam; i++){
        if(texto[i] == c){
            cont++;
        }
    }
    return cont;
}

int findChar(char *texto, char c){
    int tam = strlen(texto);
    for(int i = 0; i<tam; i++){
        if(texto[i] == c){
            return i;
        }
    }
    return -1;

}

int isNumValid(char *num){
    int tam = strlen(num);

    for(int i = 0; i<tam; i++){
        if(isLetra(num[i])){
            return 0;
        }
    }
    return 1;
}

int isNomeValid(char *nome){
    int tam = strlen(nome);

    for(int i = 0; i<tam; i++){
        if(isDigit(nome[i])){
            return 0;
        }
    }
    return 1;
}

int isCharValid(char *c, char filtro[]){
    int tamF = strlen(filtro);
    int tamC = strlen(c);
    int cont = 0;


    for(int i = 0; i<tamC-1; i++){
        if(!(isDigit(c[i]) || isLetra(c[i]))){
            cont = 0;
            for(int j = 0; j < tamF; j++){
                if(c[i] == filtro[j]){
                    cont++;
                }
            }
            if(cont == 0){
                return 0;
            }
        }
    }
    return 1;
}

int isEmailValid(char *email){
    if(contChar(email, '@') == 1){
        int x = findChar(email, '@');
        if(x != 0 && contnChar(email, '.', x) == 1){
            if(findChar(email, '.') != 0){
                if(isCharValid(email, "@._")){
                    return 1;
                }
            }
        }
    }
    return 0;
}

void limpaTexto(char *texto){
    int tam = strlen(texto);
    char copyC[tam];
    int cont = 0;
    for(int i = 0; i < tam; i++){
        if(isDigit(texto[i]) || isLetra(texto[i]) || texto[i] == '\n'){
            copyC[i-cont] = texto[i];
        }else{
            cont++;
        }
        if(i == tam-1){
            copyC[i-cont+1] = '\0';
        }
    }
    strcpy(texto, copyC);
}