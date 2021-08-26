#ifndef academiasys_h
#define academiasys_h

// Valores do tipo cliente
typedef struct clients clients;

// Valores do tipo produto
typedef struct product product;

// Valores do tipo venda
typedef struct sales sales;

// Função que verifica se um arquivo existe
int verificarquivo(char meuarquivo[]);

// Função para identificar a opção que o cliente quer realizar
int readOption();

// Função para salvar as vendas feitas na data
void saveSales(sales *salesToSave);

// Função para para criar um novo arquivo
void newFile(char fileName[], char action[]);

// Função para editar um arquivo
void updateFile();

// Gera o nome do arquivo ".pvf"
void gerarPvf(char *fileName);

// Função que realiza uma venda
void sell(sales *venda);

// Verifica se o cliente está com débito em aberto
void verifyDebt(char *path);

// Lista as vendas feitas na data
void listSales();

// Zera ou diminui a divida do cliente
void quitarDivida();

//Cadastrar o aluno
void cadastrarAluno();

//Cadastrar o professor
void cadastrarProfessor();

//Cadastrar a turma
void cadastrarTurma();

//Inscrever aluno
void inscreveAluno();

//Cancelar turma
void cancelarturma();

//Cancelar inscrição do aluno de uma turma
void cancelarinscri(); 

//Função de Fechar Turma
void fechaTurma();

//função de gerar id de aluno
int gerarID(char *arquivo,char *arquivo2);

//função pra contar alunos na turma
int contaalunos(int id_turma);

//Função para achar o numero do telefone
char* achatelefone(int id_prof);

void confirmarTurma();

void copiarDados(FILE *fp, FILE *fp2);

int contaturma(int n);

int maiorconfirmado();

#endif