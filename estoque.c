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
                        break;
                    case '2':
                        telaProcurarEstoque();
                        break;
                    case '3':
                        telaEditarEstoque();
                        break;
                    case '4':
                        telaDeletarEstoque();
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
                        break;
                    case '2':
                        telaProcurarFornecedor();
                        break;
                    case '3':
                        telaEditarFornecedor();
                        break;
                    case '4':
                        telaDeletarFornecedor();
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
}

void moduloProdutos(void) {
    //char op;
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
    char op;
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
    printf("###                                                                     ###\n");
    printf("###            Digite sua opção: ");
    scanf("%[0-9]", &op);
    getchar();
    printf("\n");
}

void moduloFornecedor(void) {
    char op;
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
    printf("###                                                                     ###\n");
    printf("###            Digite sua opção: ");
    scanf("%[0-9]", &op);
    getchar();
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
    printf("###                       = Cadastrar Estoque =                         ###\n");
    printf("###                                                                     ###\n");
    printf("###            Nome do Item:                                            ###\n");
    printf("###            Quantidade:                                              ###\n");
    printf("###            Fornecedor:                                              ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}

void telaProcurarEstoque(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                        = Procurar Estoque =                         ###\n");
    printf("###                                                                     ###\n");
    printf("###            Digite o nome do item ('0' para listar todos):           ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}

void telaEditarEstoque(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                         = Editar Estoque =                          ###\n");
    printf("###                                                                     ###\n");
    printf("###            Digite o nome do item do estoque:                        ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}

void telaDeletarEstoque(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                        = Deletar Estoque =                          ###\n");
    printf("###                                                                     ###\n");
    printf("###            Digite o nome do item:                                   ###\n");
    printf("###                                                                     ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}

void telaCadastrarFornecedor(void){   
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                    = Cadastrar Fornecedor =                         ###\n");
    printf("###                                                                     ###\n");
    printf("###            Nome:                                                    ###\n");
    printf("###            E-mail:                                                  ###\n");
    printf("###            CNPJ:                                                    ###\n");
    printf("###            Telefone:                                                ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}

void telaProcurarFornecedor(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                       = Buscar Fornecedor =                         ###\n");
    printf("###                                                                     ###\n");
    printf("###      Digite o nome do Fornecedor ('0' para listar todos):           ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}

void telaEditarFornecedor(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                      = Editar Fornecedor =                          ###\n");
    printf("###                                                                     ###\n");
    printf("###            Digite o nome do fornecedor:                             ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}

void telaDeletarFornecedor(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                       = Deletar Fornecedor =                        ###\n");
    printf("###                                                                     ###\n");
    printf("###            Digite o nome do fornecedor:                             ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}

//funções módulo fornecedor
void cadastrarFornecedor(void){    
    
    char nome[20];
    char email[60];
    char cnpj[20];
    char numero[12];
    
    printf("Insira o nome: \n");
    scanf("%s",nome);
    printf("E-mail: \n");
    scanf("%s", email);
    printf("Insira o cnpj: \n");
    scanf("%s", cnpj);
    printf("Insira o numero: \n");
    scanf("%s", numero);

}   

void editarFornecedor(void){
    
    char editarFornecedor[20];
       printf("Nome do fornecedor:\n ");
       scanf("%s", editarFornecedor);

}

void procurarFornecedor(void){
    
    char procurarFornecedor[20];
    printf("Nome do fornecedor: \n");
    scanf("%s", procurarFornecedor);
}

void deletarFornecedor(void) {

    char deletarFornecedor[20];
    printf("Nome do fornecedor: \n");
    scanf("%s", deletarFornecedor);
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
    
    char nomeProd[20];
    int quantidade;
    char fornecedor[20];
    
    printf("Insira o nome do produto: \n");
    scanf("%s",nomeProd);
    printf("Quantidade de itens: \n");
    scanf("%d", &quantidade);
    printf("Insira o nome do fornecedor: \n");
    scanf("%s", fornecedor);
    
}  

void editarEstoque(void){
       
    char editarEstoque[20];
    printf("Nome do Estoque:\n ");  //provisório
    scanf("%s", editarEstoque);

}

void procurarEstoque(void){
    
    char procurarEstoque[20];
    printf("Nome do Estoque: \n");
    scanf("%s", procurarEstoque);
}

void deletarEstoque(void) {

    char produto[20];
    printf("Nome do Estoque a ser deletado: \n");
    scanf("%s", produto);
}


char escolherOpcao(void){
    char opcao;
    printf("\tDigite sua opção: ");
    scanf("%[0-9]",&opcao);
    getchar();
    return opcao;
}