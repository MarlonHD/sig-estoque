int validBarCode(char*);
int validaCnpj(char*);
int isDigit(char); // Verifica se o char é um numero
int isLetra(char); // verifica se o char é uma letra
int contChar(char*, char); // Conta quantos caracteres específicos há na cadeia de char
int contnChar(char*, char, int); // Conta quantos caracteres específicos há na cadeia de char a partir de uma posição n
int findChar(char*, char); // Retorna a possição da primeira ocorrência do char especifico na cadeia de char
int isNomeValid(char*); // Verifica se a cadeia de char é totalmente composta por letras
int isNumValid(char*); // Verifica se a cadeia de char é totalmente composta por numeros
int isCharValid(char*, char[]); // Verifica se a sequencia de char possui algum char fora do filtro
int isEmailValid(char*); // Verifica se o email é válido
void limpaTexto(char*); // Remove caracteres que não sejam números nem letras 