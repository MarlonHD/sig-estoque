#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorios.h"
#include "estoque.h"
#include "produto.h"
#include "fornecedor.h"
#include "validacoes.h"

void moduloRelatorios(void) {
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                         = Lista de Relatórios =                          ###\n");
    printf("###                                                                          ###\n");
    printf("###               1. Estoque Completo                                        ###\n");
    printf("###               2. Produtos Catalogados                                    ###\n");
    printf("###               3. Fornecedores Cadastrados                                ###\n");
    printf("###               4. Histórico de Registros                                  ###\n");
    printf("###               5. Produtos por Fornecedor                                 ###\n");
    printf("###               6. Produtos por Categoria                                  ###\n");
    printf("###               7. Fornecedores em ordem alfabética                        ###\n");
    printf("###               8. Produtos em ordem alfabética                            ###\n");
    printf("###               9. Estoque em ordem de quantidade                          ###\n");
    printf("###               0. Voltar                                                  ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void estoqueCompleto(void){
    system("clear||cls");
    printf("\n");

    FILE* fp;
    Estoque* est;
    est = (Estoque*)malloc(sizeof(Estoque));
    int cont = 0;

    fp = fopen("./arquivos/estoque.dat", "ab");
    fclose(fp);

    fp = fopen("./arquivos/estoque.dat", "rb");
    while(fread(est, sizeof(Estoque), 1, fp)==1){
        exibeEstoque(est);
        cont++;
    }
    if(!cont){
        printf("\n\tNão há elementos a serem exibidos!");
        printf("\n\tPressione qualquer tecla para continuar...");
    }
    getchar();
    fclose(fp);
    free(est);
}

void histRegistros(void){
    system("clear||cls");
    printf("\n");

    FILE* fp;
    Registro* reg;
    reg = (Registro*)malloc(sizeof(Registro));
    int cont = 0;

    fp = fopen("./arquivos/registros.dat", "ab");
    fclose(fp);

    fp = fopen("./arquivos/registros.dat", "rb");
    if(fp == NULL){
        printf("\n\tFalha na abertura do arquivo!");
        getchar();
        exit(1);
    }
    while(fread(reg, sizeof(Registro), 1, fp)==1){
        exibeRegistro(reg);
        cont++;
    }
    if(!cont){
        printf("\n\tNão há elementos a serem exibidos!");
        printf("\n\tPressione qualquer tecla para continuar...");
    }
    getchar();
    fclose(fp);
    free(reg);
}

void produtosCat(void){
    system("clear||cls");
    printf("\n");

    FILE* fp;
    Produto* prod;
    prod = (Produto*)malloc(sizeof(Produto));
    int cont = 0;

    fp = fopen("./arquivos/produtos.dat", "ab");
    fclose(fp);

    fp = fopen("./arquivos/produtos.dat", "rb");
    if(fp == NULL){
        printf("\n\tFalha na abertura do arquivo!");
        getchar();
        exit(1);
    }
    while(fread(prod, sizeof(Produto), 1, fp)==1){
        exibeProduto(prod);
        cont++;
    }
    if(!cont){
        printf("\n\tNão há elementos a serem exibidos!");
        printf("\n\tPressione qualquer tecla para continuar...");
    }
    getchar();
    fclose(fp);
    free(prod);
}

void fornecedoresCad(void){
    system("clear||cls");
    printf("\n");

    FILE* fp;
    Fornecedor* forn;
    forn = (Fornecedor*)malloc(sizeof(Fornecedor));
    int cont = 0;

    fp = fopen("./arquivos/fornecedores.dat", "ab");
    fclose(fp);

    fp = fopen("./arquivos/fornecedores.dat", "rb");
    if(fp == NULL){
        printf("\n\tFalha na abertura do arquivo!");
        getchar();
        exit(1);
    }
    while(fread(forn, sizeof(Fornecedor), 1, fp)==1){
        exibeFornecedor(forn);
        cont++;
    }
    if(!cont){
        printf("\n\tNão há elementos a serem exibidos!");
        printf("\n\tPressione qualquer tecla para continuar...");
    }
    getchar();
    fclose(fp);
    free(forn);
}

char* getFiltro(int op){
    char* filtro;
    filtro = (char*)malloc(sizeof(char)*30);
    char cancel = '1';
    if(op == 1){
        do{
            printf("\tDigite o CNPJ do fornecedor (apenas números): \n\t");
            fgets(filtro, 30, stdin);
            limpaTexto(filtro);
            if(!isFornecedorCad(filtro)){
                printf("\tCNPJ não cadastrado (0 para cancelar ação):\n\t");
                scanf("%c",&cancel);
            }
        }while(!isFornecedorCad(filtro) && cancel!='0');
    }else if(op == 2){
        do{
            printf("\tDigite a categoria do produto: \n\t");
            fgets(filtro, 30, stdin);
        }while(!isNomeValid(filtro));
    }else{
        return NULL;
    }
    return filtro;
}

void prod_filtro(int op){
    FILE* fp;
    Produto* prod;
    prod = (Produto*)malloc(sizeof(Produto));

    fp = fopen("./arquivos/produtos.dat", "ab");
    fclose(fp);
    fp = fopen("./arquivos/produtos.dat", "rb");
    if(fp == NULL){
        printf("\n\tFalha na abertura do arquivo!");
        getchar();
        exit(1);
    }

    char* filtro = getFiltro(op);
    if(op == 1){
        while((fread(prod, sizeof(Produto), 1, fp)==1)){
            if(strcmp(prod->cnpjFornecedor,filtro)==0){
                exibeProduto(prod);
                if(isOnEstoque(prod->codProduto)){
                    printf("###\tQuantidade:.............%d\n", quantidade(prod->codProduto));
                }else{
                    printf("###\tQuantidade:.............0\n");
                }
                printf("###\n################################################################################\n");
            }
        }
    }else if(op == 2){
        while (fread(prod, sizeof(Produto),1, fp)==1){
            if(strcmp(prod->categoria, filtro)==0){
                exibeProduto(prod);
                if(isOnEstoque(prod->codProduto)){
                    printf("###\tQuantidade:.............%d\n", quantidade(prod->codProduto));
                }else{
                    printf("###\tQuantidade:.............0\n");
                }
                printf("###\n################################################################################\n");
            }
        }
    }

    getchar();
    fclose(fp);
    free(filtro);
}

void forneAlfab(void){
    int cont = 0;
  Fornecedor* forn;
  FILE* fp;
  forn = (Fornecedor*) malloc(sizeof(Fornecedor));
  for(int i = 0; i <= 25; i++){
    fp = fopen("./arquivos/fornecedores.dat", "r+b");
    while((fread(forn, sizeof(Fornecedor), 1, fp))){
      if(forn->nome[0] == 65+i || forn->nome[0] == 97+i){
        cont++;
        printf("\n"
        "////////////////////////////////////////////////////////////////////////////////\n"
        "///  FORNECEDOR %6i                                                       ///\n", cont);
        exibeFornecedor(forn);
        printf("\n");
      }
    }
    fclose(fp);
    }
    if(cont == 0){
    printf("\n"
      "////////////////////////////////////////////////////////////////////////////////\n"
      "///                                                                          ///\n"
      "///                       Nenhum Fornecedor Cadastrado                       ///\n"
      "///                                                                          ///\n"
      "////////////////////////////////////////////////////////////////////////////////\n");
  }
    
  free(forn);
  getchar();
  system("clear || cls");
}

void prodAlfab(void){
    int cont = 0;
  Produto* prod;
  FILE* fp;
  prod = (Produto*) malloc(sizeof(Produto));
  for(int i = 0; i <= 25; i++){
    fp = fopen("./arquivos/produtos.dat", "r+b");
    while((fread(prod, sizeof(Produto), 1, fp))){
      if(prod->nomeProduto[0] == 65+i || prod->nomeProduto[0] == 97+i){
        cont++;
        printf("\n"
        "////////////////////////////////////////////////////////////////////////////////\n"
        "///  PRODUTO %6i                                                          ///\n", cont);
        exibeProduto(prod);
        printf("\n");
      }
    }
    fclose(fp);
    }
    if(cont == 0){
    printf("\n"
      "////////////////////////////////////////////////////////////////////////////////\n"
      "///                                                                          ///\n"
      "///                        Nenhum Produto Cadastrado                         ///\n"
      "///                                                                          ///\n"
      "////////////////////////////////////////////////////////////////////////////////\n");
  }
  free(prod);
  getchar();
  system("clear || cls");
}


EstDinKey* getEstDinKey(void){
    FILE* fp;
    Estoque* est;
    est = (Estoque*)malloc(sizeof(Estoque));
    fp = fopen("./arquivos/estoque.dat", "ab");
    fclose(fp);
    fp = fopen("./arquivos/estoque.dat", "rb");
    EstDinKey *key;
    EstDinKey *lista;

    lista = NULL;
    int tam;

    while(fread(est, sizeof(Estoque), 1, fp)==1){
        key = (EstDinKey*)malloc(sizeof(EstDinKey));
        tam = strlen(est->codProduto)+1;
        key->codigo = (char*)malloc(sizeof(char)*tam);
        strcpy(key->codigo, est->codProduto);
        key->quantidade = quantidade(est->codProduto);
        if(lista == NULL){
            lista = key;
            key->prox = NULL;
        }else if(key->quantidade < lista->quantidade){
            key->prox = lista;
            lista = key;
        }else{
            EstDinKey *anter = lista;
            EstDinKey *atual = lista->prox;
            while((atual != NULL) && (atual->quantidade < key->quantidade)){
                anter = atual;
                atual = atual->prox;
            }
            anter->prox = key;
            key->prox = atual;
        }

    }
    fclose(fp);
    return lista;
}

void estoqueByQuant(void){
    EstDinKey *key = getEstDinKey();
    EstoqueDin *listaEst = preencheEstDin(key);
    exibeEstDin(listaEst);
    limpaMemoriaEstDin(listaEst);
}


EstoqueDin* preencheEstDin(EstDinKey* keys){
    EstoqueDin* estDin;
    EstoqueDin* lista;
    FILE* prods;

    Produto* prod;
    prod = (Produto*)malloc(sizeof(Produto));

    prods = fopen("./arquivos/produtos.dat", "ab");
    fclose(prods);
    

    int tam;
    lista = NULL;

    while(keys != NULL){
        estDin = (EstoqueDin*)malloc(sizeof(EstoqueDin));
        prods = fopen("./arquivos/produtos.dat", "rb");
        while(fread(prod, sizeof(Produto), 1, prods)==1){
            if(strcmp(keys->codigo,prod->codProduto)==0){
                tam = strlen(prod->categoria)+1;
                estDin->categoria = (char*)malloc(sizeof(char)*tam);
                strcpy(estDin->categoria, prod->categoria);

                tam = strlen(prod->cnpjFornecedor)+1;
                estDin->cnpjFornecedor = (char*)malloc(sizeof(char)*tam);
                strcpy(estDin->cnpjFornecedor, prod->cnpjFornecedor);

                tam = strlen(prod->codProduto)+1;
                estDin->codProduto = (char*)malloc(sizeof(char)*tam);
                strcpy(estDin->codProduto, prod->codProduto);

                tam = strlen(prod->nomeProduto)+1;
                estDin->nomeProduto = (char*)malloc(sizeof(char)*tam);
                strcpy(estDin->nomeProduto, prod->nomeProduto);

                estDin->nomeFornecedor = getNomeFornByCNPJ(prod->cnpjFornecedor);
                estDin->quantidade = quantidade(prod->codProduto);
                ////////////
                estDin->prox = lista;
                lista = estDin;

            }
        }
        fclose(prods);
        keys = keys->prox;
    }
    free(prod);

    //while(estDin != NULL){
    //    printf("Prod->quant: %d\n", estDin->quantidade);
    //    estDin = estDin->prox;
    //}
    //getchar();
    return lista;
}

void exibeEstDin(EstoqueDin* lista){
    while(lista != NULL){
        printf("################################################################################\n###\n");
        printf("###\tCódigo do Produto:.......%s", lista->codProduto);
        printf("###\tNome do Produto:.........%s", lista->nomeProduto);
        printf("###\tQuantidade:..............%d\n", lista->quantidade);
        printf("###\tCategoria:...............%s",lista->categoria);
        printf("###\tNome do Fornecedor:......%s",lista->nomeFornecedor);
        printf("###\tCNPJ do Fornecedor:......%s",lista->cnpjFornecedor);
        printf("###\n");
        lista = lista->prox;
    }
    printf("################################################################################\n\t");
    getchar();
}

void limpaMemoriaEstDin(EstoqueDin* lista){
    EstoqueDin *aux;
    while(lista != NULL){
        aux = lista;
        free(aux->categoria);
        free(aux->cnpjFornecedor);
        free(aux->codProduto);
        free(aux->nomeFornecedor);
        free(aux->nomeProduto);
        free(aux);
        lista = lista->prox;
    }
}

/*void rela_ordem_alfa_ass(void){ //Adaptada de @FlaviusGorgonio
  FILE *fp;
  Fornecedor *novaAss;
  Fornecedor* lista;
  fp = fopen("arquivos/fornecedores.dat","r+b");
  if(fp == NULL){
    printf("Erro na abertura do arquivo!\n");
    exit(1);
  }
  lista = NULL;
  while(!feof(fp)){
    novaAss = (Fornecedor*) malloc(sizeof(Fornecedor));
    if(fread(novaAss, sizeof(Fornecedor), 1, fp)){
      if(novaAss->status == 'c'){
        if(lista == NULL){
          lista = novaAss;
          novaAss->prox = NULL;
        }else if(strcmp(novaAss->nome, lista->nome) < 0){
          novaAss->prox = lista;
          lista = novaAss;
        }else{
          Fornecedor* anter = lista;
          Fornecedor* atual = lista->prox;
          while((atual != NULL) && strcmp(atual->nome,novaAss->nome) < 0){
            anter = atual;
            atual = atual->prox;
          }
          anter->prox = novaAss;
          novaAss->prox = atual;
        }
      }
    }
  }
  fclose(fp);

  //limpa_exibe_lista_ass(novaAss,lista,'a'); resolver o problema dessa função linha 701 do gordin

  printf(">>> APERTE ENTER PARA CONTINUAR >>> ");
  getchar();
  system("clear || cls");
}*/

/*NoFornecedor* listaOrdenadaForne(void) {
  FILE* fp;
  Fornecedor* fornecedor;
  NoFornecedor* noFornecedor;
  NoFornecedor* lista;

  lista = NULL;
  fp = fopen("fornecedores.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  fornecedor = (Fornecedor*) malloc(sizeof(Fornecedor));
  while(fread(fornecedor, sizeof(Fornecedor), 1, fp)) {
    if (fornecedor->status == 'c') {
      noFornecedor = (NoFornecedor*) malloc(sizeof(NoFornecedor));
      strcpy(noFornecedor->nome, fornecedor->nome);
      strcpy(noFornecedor->cnpj, fornecedor->cnpj);
      strcpy(noFornecedor->email, fornecedor->email);
      strcpy(noFornecedor->telefone, fornecedor->telefone);
      noFornecedor->status = fornecedor->status;

      if (lista == NULL) {
        lista = noFornecedor;
        noFornecedor->prox = NULL;
      } else if (strcmp(noFornecedor->nome,lista->nome) < 0) {
        noFornecedor->prox = lista;
        lista = noFornecedor;
      } else {
        NoFornecedor* anter = lista;
        NoFornecedor* atual = lista->prox;
        while ((atual != NULL) && strcmp(atual->nome,noFornecedor->nome) < 0) {
          anter = atual;
          atual = atual->prox;
        }
        anter->prox = noFornecedor;
        noFornecedor->prox = atual;
      }
    }
  }
  fclose(fp);
  free(fornecedor);
  return lista;
}*/


/*void exibeLista(NoFornecedor* lista) {
  printf("\n\n");

  while (lista != NULL) {
    printf("Nome: %s\n", lista->nome);
    printf("CNPJ: %s\n", lista->cnpj);
    printf("E-mail: %s\n", lista->email);
    printf("Telefone: %s\n", lista->telefone);
    printf("Status: %c\n", lista->status);
    printf("\n");
    lista = lista->prox;
  }
}*/