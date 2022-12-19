void moduloRelatorios(void);
void estoqueCompleto(void);
void histRegistros(void);
void produtosCat(void);
void fornecedoresCad(void);

char* getFiltro(int);
void prod_filtro(int);

void forneAlfab(void);
void prodAlfab(void);

void estoqueByQuant(void);

typedef struct estoqueDinKey EstDinKey;

struct estoqueDinKey{
    int quantidade;
    char *codigo;
    EstDinKey *prox;
};

typedef struct estoqueDinamico EstoqueDin;

struct estoqueDinamico{
    char *codProduto;
    char *nomeProduto;
    char *categoria;
    char *cnpjFornecedor;
    char *nomeFornecedor;
    int quantidade;
    EstoqueDin *prox;
};

EstDinKey* getEstDinKey(void);

EstoqueDin* preencheEstDin(EstDinKey*);
void exibeEstDin(EstoqueDin*);
void limpaMemoriaEstDin(EstoqueDin*);

void rela_ordem_alfa_ass(void);

//NoFornecedor* listaOrdenadaForne(void);
//void exibeLista(NoFornecedor*);