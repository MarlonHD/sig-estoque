///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///               Projeto Sistema de Controle de Estoques                   ///
///   Developed by Cleomar Junior and Marlon Silva -- since Aug, 2022       ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 12                                 ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modulos/produto.h"
#include "modulos/estoque.h"
#include "modulos/fornecedor.h"
#include "modulos/relatorios.h"
#include "modulos/validacoes.h"
#include "modulos/auxiliar.h"



int main(void){
    const char SAIR = '0';
    char op;
    char op1 = '0';
    NoFornecedor* lista;
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
                        alterarEstoque('i');
                        break;
                    case '2':
                        telaProcurarEstoque();
                        procurarEstoque();
                        break;
                    case '3':
                        telaRetirarEstoque();
                        alterarEstoque('o');
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
            case '4':
                moduloRelatorios();
                op1 = escolherOpcao();
                switch(op1){
                    case '1':
                        estoqueCompleto();
                        break;
                    case '2':
                        produtosCat();
                        break;
                    case '3':
                        fornecedoresCad();
                        break;
                    case '4':
                        histRegistros();
                        break;
                    case '5':
                        prod_filtro(1);
                        break;
                    case '6':
                        prod_filtro(2);
                        break; 
                    case '7':
                        forneAlfab();
                        break;
                    case '8':
                        prodAlfab();
                        break;
                    case '9':
                    //lista = listaOrdenadaForne();
                    //exibeLista(lista);
                    break;        
                    case '0':
                        break;
                    default:
                        if(op1 >= '1' && op1 <= '9'){
                            printf("\n\n\t\t\tEM DESENVOLVIMENTO!\n\n");
                            printf("\t\tPressione <ENTER> para continuar...\n");
                            getchar();
                        }else{
                            printf("Opção inválida!");
                        }
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