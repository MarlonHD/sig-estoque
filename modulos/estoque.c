#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "estoque.h"
#include "produto.h"
#include "validacoes.h"

typedef struct estoque Estoque;

void moduloEstoque(void) {
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                           = Módulo Estoque =                             ###\n");
    printf("###                                                                          ###\n");
    printf("###               1. Cadastrar no Estoque                                    ###\n");
    printf("###               2. Procurar no Estoque                                     ###\n");
    printf("###               3. Retirar do Estoque                                      ###\n");
    printf("###               0. Voltar                                                  ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void telaCadastrarEstoque(void){
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                          = Adicionar Estoque =                           ###\n");
    printf("###                                                                          ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void telaProcurarEstoque(void){
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                            = Buscar Estoque =                            ###\n");
    printf("###                                                                          ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void telaRetirarEstoque(void){
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                           = Retirar Estoque =                            ###\n");
    printf("###                                                                          ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

int quantidade(char *codigo){
    FILE* fp;
    Estoque* est;
    est = (Estoque*)malloc(sizeof(Estoque));
     // corretor de bug    
    fp = fopen("./arquivos/estoque.dat", "ab");
    fclose(fp);

    fp = fopen("./arquivos/estoque.dat","rb");
    if(fp == NULL){
        printf("404! \nErro na abertura do arquivo!");
        exit(1);
    }
    while(fread(est, sizeof(Estoque), 1, fp)){
        if(strcmp(est->codProduto, codigo)){
            return est->quantidade;
        }
    }
    return -1;
}

Registro* preencheRegistro(char tipo){ //tipo == 'i' ? input : output
    Registro* reg;
    time_t tempo;
    time(&tempo);

    reg = (Registro*)malloc(sizeof(Registro));
    reg->tempo = tempo;
    reg->conteudo = preencheEstoque();
    reg->tipo = tipo;

    return reg;
}

void gravaRegistro(Registro *reg){
    FILE* fp;
    fp = fopen("./arquivos/registros.dat", "ab");
    if(fp == NULL){
        printf("Erro ao criar o arquivo!");
        exit(1);
    }
    if(gravaEstoque(reg)){
        fwrite(reg, sizeof(Registro), 1, fp);
        fclose(fp);
    }else{
        fclose(fp);
    }
}

void exibeRegistro(Registro *reg){
    printf("\n\t#############\n");
    
    if(reg->tipo == 'i'){
        printf("\tTipo: Entrada");
    }else if(reg->tipo == 'o'){
        printf("\tTipo: Saída");
    }
    printf("\n\tProduto: %s", reg->conteudo->codProduto);
    printf("\tQuantidade: %d", reg->conteudo->quantidade);
    printf("\n\tHorário: %s", ctime(&reg->tempo));
}

Estoque* preencheEstoque(void){
    Estoque* est;
    est = (Estoque*) malloc(sizeof(Estoque));

    char cancel = '1';
    char quant[10];

    do{
        printf("\tInforme o codigo do produto: \n\t");
        fgets(est->codProduto, 20, stdin);
        if(!isProdutoCad(est->codProduto)){
            printf("\n\tProduto não cadastrado no sistema!\n");
            printf("\tDeseja cancelar a ação? (Digite: 0)\n\t");
            scanf("%c", &cancel);
        }
    }while((!isProdutoCad(est->codProduto)) && (cancel!='0'));
    
    if(cancel == '0'){
        return NULL;
    }
    do{
        printf("\tInforme a quantidade de produtos(apenas números): \n\t");
        fgets(quant, 10, stdin);
    }while(!isNumValid(quant));

    est->quantidade = atoi(quant);
    
    return est;
}

int isOnEstoque(char *codigo){
    FILE* fp;
    Estoque* est;
    int finded = 0;

    //correção de bug
    fp = fopen("./arquivos/estoque.dat", "ab");
    fclose(fp);

    est = (Estoque*)malloc(sizeof(Estoque));

    limpaTexto(codigo);
    fp = fopen("./arquivos/estoque.dat","rb");
    if(fp == NULL){
        printf("404! \nErro na abertura do arquivo!");
        exit(1);
    }
    while((!finded) && fread(est, sizeof(Estoque), 1, fp)){
        if((strcmp(est->codProduto, codigo) == 0)){
            finded = 1;
        }
    }
    fclose(fp);
    free(est);

    return finded;
}

int gravaEstoque(Registro *reg){
    FILE* fp;

    Estoque *est;
    est = (Estoque*)malloc(sizeof(Estoque));
    int ok = 1;


    if(isOnEstoque(reg->conteudo->codProduto)){
        int finded = 0;
        fp = fopen("./arquivos/estoque.dat", "r+b");
        if(fp == NULL){
            printf("Erro ao abrir o arquivo!");
            exit(1);
        }
        while((!finded) && fread(est, sizeof(Estoque), 1, fp)){
            if((strcmp(est->codProduto, reg->conteudo->codProduto) == 0)){
                finded = 1;
            }
        }
        if(reg->tipo == 'i'){
            est->quantidade = est->quantidade + reg->conteudo->quantidade;
        }else if(reg->tipo == 'o'){
            if(est->quantidade < reg->conteudo->quantidade){
                ok = 0;
            }else{
                est->quantidade = est->quantidade - reg->conteudo->quantidade;
            }   
        }
        if(ok){
            fseek(fp, (-1)*sizeof(Estoque), SEEK_CUR);
            fwrite(est, sizeof(Estoque), 1, fp);
            fclose(fp);
        }else{
            fclose(fp);
            return 0;
        }
        
    }else{
        fp = fopen("./arquivos/estoque.dat", "ab");
        if(fp == NULL){
            printf("404! \nErro na abertura do arquivo!");
            exit(1);
        }
        if(reg->tipo == 'i'){
            est->quantidade = est->quantidade + reg->conteudo->quantidade;
        }else if(reg->tipo == 'o'){
            if(est->quantidade < reg->conteudo->quantidade){
                ok = 0;
            }else{
                est->quantidade = est->quantidade - reg->conteudo->quantidade;
            }   
        }
        if(ok){
            fwrite(est, sizeof(Estoque), 1, fp);
            fclose(fp);
        }else{
            fclose(fp);
            return 0;
        }
    }
    return 1;
}

void exibeEstoque(Estoque *est){
    printf("\t########################\n");
    printf("\tcodigo: %s", est->codProduto);
    printf("\tquantidade: %d \n", est->quantidade);
}

void cadastrarEstoque(void){    //Função cadastrar estoque
    Registro *reg;

    //gravaEstoque(est);

    reg = preencheRegistro('i');
    if(reg != NULL){
        gravaRegistro(reg);
        exibeRegistro(reg);
        getchar();
    }
    free(reg);
}
void procurarEstoque(void){
    
    int idProduto;
    printf("\tInforme o ID do Produto: \n\t");
    scanf("%d", &idProduto);
    getchar();
}

void retirarEstoque(void) {

    int codProduto;
    printf("\tCódigo do produto a ser deletado: \n\t");
    scanf("%d", &codProduto);
    getchar();
}
