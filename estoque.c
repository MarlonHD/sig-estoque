///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///               Projeto Sistema de Controle de Estoques                   ///
///   Developed by Cleomar Junior and Marlon Silva -- since Aug, 2022       ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 5                                 ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Assinatura
void telaPrincipal(void);
void tela_sobre(void);
void moduloEstoque(void);
void moduloProdutos(void);
void moduloFornecedor(void);
void telaCatalogarProduto(void);
void telaBuscarProduto(void);
void telaEditarProduto(void);
void telaDeletarProduto(void);
void telaCadastrarEstoque(void);
void telaProcurarEstoque(void);
void telaEditarEstoque(void);
void telaDeletarEstoque(void);
void telaCadastrarFornecedor(void);
void telaProcurarFornecedor(void);
void telaEditarFornecedor(void);
void telaDeletarFornecedor(void);
//Funções de entrada de dados do fornecedor
void cadastrarFornecedor(void); 
void editarFornecedor(void);
void procurarFornecedor(void);
void deletarFornecedor(void);
//Funções módulo produtos
void cadastrarProduto(void);
void editarProduto(void);
void procurarProduto(void);
void deletarProduto(void);
//Funções módulo estoque
void cadastrarEstoque(void);
void editarEstoque(void);
void procurarEstoque(void);
void deletarEstoque(void);


char escolherOpcao(void);


int main(void){
    setlocale(LC_ALL,"Portuguese_Brazil");
    const char SAIR = '0';
    char op;
    char op1 = '0';

    do{
        (op1 == '0') ? telaPrincipal() : 1;
        op = (op1 == '0') ? escolherOpcao() : op;
        switch (op){
            case '1':        
                moduloProdutos();
                op1 = escolherOpcao();
                switch (op1){
                    case '1':
                        telaCatalogarProduto();
                        cadastrarProduto();
                        break;
                    case '2':
                        telaBuscarProduto();
                        procurarProduto();
                        break;
                    case '3':
                        telaEditarProduto();
                        editarProduto();
                        break;
                    case '4':
                        telaDeletarProduto();
                        deletarProduto();
                        break;
                    case '0':
                        break;
                    default:
                        printf("Opção Inválida!!");
                        break;
                }
                break;
            case '2':
                moduloEstoque();
                op1 = escolherOpcao();
                switch (op1){
                    case '1':
                        telaCadastrarEstoque();
                        cadastrarEstoque();
                        break;
                    case '2':
                        telaProcurarEstoque();
                        procurarEstoque();
                        break;
                    case '3':
                        telaEditarEstoque();
                        editarEstoque();
                        break;
                    case '4':
                        telaDeletarEstoque();
                        deletarEstoque();
                        break;
                    case '0':
                        break;
                    default:
                        printf("Opção Inválida!!");
                        break;
                }
                break;
            case '3':
                moduloFornecedor();
                op1 = escolherOpcao();
                switch (op1){
                    case '1':
                        telaCadastrarFornecedor();
                        cadastrarFornecedor();
                        break;
                    case '2':
                        telaProcurarFornecedor();
                        procurarFornecedor();
                        break;
                    case '3':
                        telaEditarFornecedor();
                        editarFornecedor();
                        break;
                    case '4':
                        telaDeletarFornecedor();
                        deletarFornecedor();
                        break;
                    case '0':
                        break;
                    default:
                        printf("Opção Inválida!");
                        break;
                }
                break;
            case '5':
                tela_sobre();
                break;
            case '0':
                break;
            default:
                printf("Opção Inválida!!");
                break;
        }
    }while(op != SAIR);
    return 0;
}

//Funções
void telaPrincipal(void) {
    //char op;
    setlocale(LC_ALL,"Portuguese_Brazil");
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             Universidade Federal do Rio Grande do Norte             ###\n");
    printf("###                 Centro de Ensino Superior do Seridó                 ###\n");
    printf("###               Departamento de Computação e Tecnologia               ###\n");
    printf("###                  Disciplina DCT1106 -- Programação                  ###\n");
    printf("###               Projeto Sistema de Controle de Estoques               ###\n");
    printf("###   Developed by Cleomar Junior and Marlon Silva -- since Aug, 2022   ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                                                                     ###\n");
    printf("###            1. Módulo Produtos                                       ###\n");
    printf("###            2. Módulo Estoque                                        ###\n");
    printf("###            3. Módulo Fornecedores                                   ###\n");
    printf("###            4. Módulo Relatórios                                     ###\n");
    printf("###            5. Sobre                                                 ###\n");
    printf("###            0. Sair                                                  ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    //printf("###                                                                     ###\n");
    //printf("###            Digite sua opção: ");
    //scanf("%[0-9]", &op);
    //getchar();
    printf("\n");
}

void tela_sobre(void) {
    system("clear||cls");
    printf("\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###             Universidade Federal do Rio Grande do Norte                 ###\n");
    printf("###                 Centro de Ensino Superior do Seridó                     ###\n");
    printf("###               Departamento de Computação e Tecnologia                   ###\n");
    printf("###                  Disciplina DCT1106 -- Programação                      ###\n");
    printf("###               Projeto Sistema de Controle de Estoques                   ###\n");
    printf("###      Developed by Cleomar Junior and Marlon Silva -- since Aug, 2022    ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###         = = = = = Sistema de Controle de Estoques = = = = =             ###\n");
    printf("###                                                                         ###\n");
    printf("###  Pojeto de um programa de controle de estoques, desenvolvido em C e     ###\n");
    printf("###  durante a disciplina DCT1106 - Programação, do curso de Bacharelado    ###\n");
    printf("###  em Sistemas de Informação da UFRN. O projeto tem como finalidade a     ###\n");
    printf("###  criação de um programa com as funcionalidades básicas para facilitar a ###\n");
    printf("###  administração/controle do inventário de uma empresa.                   ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir... \n");
    getchar();
}

void moduloProdutos(void) {
    //char op;
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             Universidade Federal do Rio Grande do Norte             ###\n");
    printf("###                 Centro de Ensino Superior do Seridó                 ###\n");
    printf("###               Departamento de Computação e Tecnologia               ###\n");
    printf("###                  Disciplina DCT1106 -- Programação                  ###\n");
    printf("###               Projeto Sistema de Controle de Estoques               ###\n");
    printf("###   Developed by Cleomar Junior and Marlon Silva -- since Aug, 2022   ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                        = Módulo Produtos =                          ###\n");
    printf("###                                                                     ###\n");
    printf("###            1. Catalogar Produto                                     ###\n");
    printf("###            2. Buscar Produto                                        ###\n");
    printf("###            3. Editar Produto                                        ###\n");
    printf("###            4. Deletar Produto                                       ###\n");
    printf("###            0. Sair                                                  ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    //printf("###                                                                     ###\n");
    //printf("###            Digite sua opção: ");
    //scanf("%[0-9]", &op);
    //getchar();
    printf("\n");
}

void moduloEstoque(void) {
    //char op;
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             Universidade Federal do Rio Grande do Norte             ###\n");
    printf("###                 Centro de Ensino Superior do Seridó                 ###\n");
    printf("###               Departamento de Computação e Tecnologia               ###\n");
    printf("###                  Disciplina DCT1106 -- Programação                  ###\n");
    printf("###               Projeto Sistema de Controle de Estoques               ###\n");
    printf("###   Developed by Cleomar Junior and Marlon Silva -- since Aug, 2022   ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                        = Módulo Estoque =                           ###\n");
    printf("###                                                                     ###\n");
    printf("###            1. Cadastrar Estoque                                     ###\n");
    printf("###            2. Procurar Estoque                                      ###\n");
    printf("###            3. Editar Estoque                                        ###\n");
    printf("###            4. Deletar Estoque                                       ###\n");
    printf("###            0. Sair                                                  ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    //printf("###                                                                     ###\n");
    //printf("###            Digite sua opção: ");
    //scanf("%[0-9]", &op);
    //getchar();
    printf("\n");
}

void moduloFornecedor(void) {
    //char op;
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             Universidade Federal do Rio Grande do Norte             ###\n");
    printf("###                 Centro de Ensino Superior do Seridó                 ###\n");
    printf("###               Departamento de Computação e Tecnologia               ###\n");
    printf("###                  Disciplina DCT1106 -- Programação                  ###\n");
    printf("###               Projeto Sistema de Controle de Estoques               ###\n");
    printf("###   Developed by Cleomar Junior and Marlon Silva -- since Aug, 2022   ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                       = Módulo Fornecedor =                         ###\n");
    printf("###                                                                     ###\n");
    printf("###            1. Cadastrar Fornecedor                                  ###\n");
    printf("###            2. Procurar Fornecedor                                   ###\n");
    printf("###            3. Editar Fornecedor                                     ###\n");
    printf("###            4. Deletar Fornecedor                                    ###\n");
    printf("###            0. Sair                                                  ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    //printf("###                                                                     ###\n");
    //printf("###            Digite sua opção: ");
    //scanf("%[0-9]", &op);
    //getchar();
    printf("\n");
}

void telaCatalogarProduto(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                       = Catalogar Produto =                         ###\n");
    printf("###                                                                     ###\n");
    //printf("###            Nome do Item:                                            ###\n");
    //printf("###            CNPJ do Fornecedor:                                      ###\n");
    //printf("###            Categoria:                                               ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    //printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    //getchar();
}

void telaBuscarProduto(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                         = Buscar Produto =                          ###\n");
    printf("###                                                                     ###\n");
    //printf("###            Digite o nome do item ('0' para listar todos):           ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    //printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    //getchar();
}

void telaEditarProduto(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                         = Editar Produto =                          ###\n");
    printf("###                                                                     ###\n");
    //printf("###            Digite o ID do item:                                     ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    //printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    //getchar();
}

void telaDeletarProduto(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                        = Deletar Produto =                          ###\n");
    printf("###                                                                     ###\n");
    //printf("###            Digite o ID do item:                                     ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    //printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    //getchar();
}

void telaCadastrarEstoque(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                       = Adicionar Estoque =                         ###\n");
    printf("###                                                                     ###\n");
    //printf("###            Nome do Item:                                            ###\n");
    //printf("###            Quantidade:                                              ###\n");
    //printf("###            Fornecedor:                                              ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    //printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    //getchar();
}

void telaProcurarEstoque(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                         = Buscar Estoque =                          ###\n");
    printf("###                                                                     ###\n");
    //printf("###            Digite o nome do item ('0' para listar todos):           ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    //printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    //getchar();
}

void telaEditarEstoque(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                         = Editar Estoque =                          ###\n");
    printf("###                                                                     ###\n");
    //printf("###            Digite o nome do item do estoque:                        ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    //printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    //getchar();
}

void telaDeletarEstoque(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                        = Retirar Estoque =                          ###\n");
    printf("###                                                                     ###\n");
    //printf("###            Digite o nome do item:                                   ###\n");
    printf("###                                                                     ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    //printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    //getchar();
}

void telaCadastrarFornecedor(void){   
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                    = Cadastrar Fornecedor =                         ###\n");
    printf("###                                                                     ###\n");
    //printf("###            Nome:                                                    ###\n");
    //printf("###            E-mail:                                                  ###\n");
    //printf("###            CNPJ:                                                    ###\n");
    //printf("###            Telefone:                                                ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    //printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    //getchar();
}

void telaProcurarFornecedor(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                       = Buscar Fornecedor =                         ###\n");
    printf("###                                                                     ###\n");
    //printf("###      Digite o nome do Fornecedor ('0' para listar todos):           ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    //printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    //getchar();
}

void telaEditarFornecedor(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                      = Editar Fornecedor =                          ###\n");
    printf("###                                                                     ###\n");
    //printf("###            Digite o nome do fornecedor:                             ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    //printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    //getchar();
}

void telaDeletarFornecedor(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                       = Deletar Fornecedor =                        ###\n");
    printf("###                                                                     ###\n");
    //printf("###            Digite o nome do fornecedor:                             ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    //printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    //getchar();
}

//funções módulo fornecedor
void cadastrarFornecedor(void){    
    
    char nome[30];
    char email[45];
    char cnpj[20]; //char || int (A definir)
    char numero[13];
    
    printf("\tInsira o nome: \n\t");
    scanf("%s",nome);
    getchar();
    printf("\tE-mail: \n\t");
    scanf("%s", email);
    getchar();
    printf("\tInsira o cnpj: \n\t");
    scanf("%s", cnpj);
    getchar();
    printf("\tInsira o numero: \n\t");
    scanf("%s", numero);
    getchar();

}   

void editarFornecedor(void){
    
    char cnpj[20];
    char nome[30];
    char email[45];
    char numero[13];
    
    printf("\tCNPJ do fornecedor:\n\t");
    scanf("%s", cnpj);
    getchar();

    //validação
    //se validação = ok
        printf("\tInsira o novo nome: \n\t");
        scanf("%s",nome);
        getchar();
        printf("\tNovo E-mail: \n\t");
        scanf("%s", email);
        getchar();
        printf("\tInsira o novo numero: \n\t");
        scanf("%s", numero);
        getchar();

}

void procurarFornecedor(void){
    
    char nomeFornecedor[30];
    printf("\tNome do fornecedor: \n\t");
    scanf("%s", nomeFornecedor);
    getchar();
}

void deletarFornecedor(void) {

    char cnpj[20];
    printf("\tInforme o CNPJ do fornecedor: \n\t");
    scanf("%s", cnpj);
    getchar();
}

/* Funções do módulo produtos */

void cadastrarProduto(void){
    
    char nomeProduto[30];
    int cnpjFornecedor;
    char categoria[100];  //Criação das variáveis 

    printf ("\tDigite o nome do produto: \n\t");
    scanf("%s",nomeProduto);
    getchar();
    printf("\tDigite o CNPJ do fornecedor (apenas números): \n\t");
    scanf("%d", &cnpjFornecedor);
    getchar();
    printf("\tDigite a categoria do produto: \n\t");
    scanf("%s",categoria);
    getchar();
}

void editarProduto(void){
       
    int idProduto;
    printf("\tID do Produto:\n\t");
    scanf("%d", &idProduto);
    getchar();

}

void procurarProduto(void){
    
    char nomeProduto[30];
    printf("\tNome do Produto: \n\t");
    scanf("%s", nomeProduto);
    getchar();
}

void deletarProduto(void) {

    int idProduto;
    printf("\tID do Produto: \n\t");
    scanf("%d", &idProduto);
    getchar();
}

// Funções do módulo estoque

void cadastrarEstoque(void){    //Função cadastrar estoque
    
    int idProduto;
    int quantidade;
    
    printf("\tFUNÇÃO BIP EM DESENVOLVIMENTO!\n\n");

    printf("\tInsira o ID do produto: \n\t");
    scanf("%d", &idProduto);
    getchar();
    printf("\tQuantidade de itens: \n\t");
    scanf("%d", &quantidade);
    getchar();

    
}  

void editarEstoque(void){
       
    int codProduto;
    int idProduto;
    printf("\tCódigo do Produto:\n\t ");  //provisório
    scanf("%d", &codProduto);
    getchar();
    printf("\tInforme o novo ID do Produto:\n\t");
    scanf("%d", &idProduto);
    getchar();

}

void procurarEstoque(void){
    
    int idProduto;
    printf("\tInforme o ID do Produto: \n\t");
    scanf("%d", &idProduto);
    getchar();
}

void deletarEstoque(void) {

    int codProduto;
    printf("\tCódigo do produto a ser deletado: \n\t");
    scanf("%d", &codProduto);
    getchar();
}


char escolherOpcao(void){
    char opcao;
    printf("\tDigite sua opção: ");
    scanf("%[0-9]",&opcao);
    getchar();
    return opcao;
}