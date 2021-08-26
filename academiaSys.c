#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "academiaSys.h"
#include "prog2Utils.h"// biblioteca de funções auxiliares. Por exemplo editar informações de arquivos.
#include <time.h>

#define CAPACIDADE_MAXIMA 100 // valor total para armazenar em uma estrutura
//Estrutura de aluno
struct aluno{
	int id;
	char nome[300];
	char cpf[15];
	char telefone[50];
	char email[100];
};
//Estrutura de aula
struct aula{
  
	int id;
	char tipo; 
  int dia; // 1=domingo , 2=segunda-feira , etc...
	char horario[6];
	int id_prof;
	int minimo;
	int maximo;
	char faixa_etaria[6];
	struct aluno alunos[CAPACIDADE_MAXIMA];
};
//Estrutura de turma
struct turma{

  int id;
  int dia; // 1=domingo , 2=segunda-feira , etc...
  char tipo;
  char hora[10];
  int id_prof;
  int idades;
  int max;
  int min; 
};

/*Está função é para mostrar o menu*/
int lerOpcao(){

  // Recebe o valor referente a opção a ser executada
	int opcao = 0;
	// Imprime as opções disponiveis

  // Recebe o valor referente a opção a ser executada
	//int opcao = 0; 
	// Imprime as opções disponiveis 
  
	printf("______________Opções:_____________\n");
	printf("[1] Cadastrar Aluno:\n");
	printf("[2] Cadastrar Proferssor:\n");
	printf("[3] Cadastrar Turma:\n");
	printf("[4] Inscrever aluno:\n");
	printf("[5] Cancelar inscrição:\n");
	printf("[6] Fechar turmas:\n");
  printf("[7] Confirmar turmas:\n");
	printf("[8] Fechar o programa:\n");
	printf("Opção: ");
	scanf("%d", &opcao);

	return opcao;
} 

/*Essa Função pega as informações digitadas pelo usuario e cadastra elas*/ 
void cadastrarAluno(){

  struct aluno aluno;

  aluno.id=gerarID("alunos.txt","inscricoesCanceladas.txt");
  getchar();
  printf("Id do aluno: %d\n",aluno.id);

  printf("Informe o nome do aluno: ");
  fgets(aluno.nome,300,stdin);

  printf("Informe o cpf:");
  fgets(aluno.cpf,15,stdin);

  printf("Informe o Telefone: ");
  fgets(aluno.telefone,50, stdin);

  printf("Informe o email: ");
  fgets(aluno.email,100,stdin);

  FILE *fp = fopen("alunos.txt","a");
  if(fp==NULL){
    printf("Erro no cadastro de alunos!");
    exit(1);
  }
  
  // Removendo a quebra de linha da string
  strtok(aluno.nome, "\n");
  strtok(aluno.cpf, "\n");
  strtok(aluno.telefone, "\n");
  strtok(aluno.email, "\n");
  
  // Gravando as informações no arquivo
  fprintf(fp,"%d,%s,%s,%s,%s\n",aluno.id,aluno.nome,aluno.cpf,aluno.telefone,aluno.email);
  
  printf("\n\tCadastro Realizado!\n");
  //fechando o arquivo
  fclose(fp);
  //Limpa a tela
  system("clear");
}

/*Essa Função pega as informações digitadas pelo usuario e cadastra elas e sao gravadas num arquivo*/
void cadastrarProfessor()
{
  struct aluno professor;

  professor.id=gerarID("professor.txt","gambiarra");

  printf("Id do professor: %d\n",professor.id);

  printf("Informe o nome do Professor: ");
  getchar();
  fgets(professor.nome,300,stdin);

  printf("Informe seu cpf:");
  getchar();
  fgets(professor.cpf,15,stdin);

  printf("Informe o Telefone: ");
  getchar();
  fgets(professor.telefone,50, stdin);

  printf("Informe seu email: ");
  getchar();
  fgets(professor.email,100,stdin);

  FILE *fp;
  fp = fopen("professor.txt", "a"); //append
  if(fp==NULL){
    printf("Erro no cadastro de professor!");
    exit(1);
  }
  
  // Removendo a quebra de linha da string
  strtok(professor.nome, "\n");
  strtok(professor.cpf, "\n");
  strtok(professor.telefone, "\n");
  strtok(professor.email, "\n");
  
  // Gravando as informações no arquivo
  fprintf(fp," ID:%d,Nome:%s,CPF:%s,Tel:%s, Email:%s",professor.id, professor.nome, professor.cpf, professor.telefone, professor.email);

  printf("\t\t\nCADASTRO REALIZADO!\n");
  //fechando o arquivo
  fclose(fp);
  //Limpa a tela
  system("clear");
}

/* Cadastra as turmas em aulas.txt com todas as informações fornecidas*/
void cadastrarTurma(){

  struct turma turma;

  FILE *fp;

  turma.id=gerarID("aulas.txt","aulasCanceladas.txt");

  printf("ID da turma: %d\n", turma.id);

  printf("Informe o tipo da aula:");
  fflush(stdin);
  getchar();
  scanf("%c", &turma.tipo);

  printf("Informe o dia da semana (1-domingo, 2-segunda, etc):");
  scanf("%d", &turma.dia);

  printf("Informe o horario da aula:");
  fflush(stdin);
  getchar();
  fgets(turma.hora,10,stdin);

  printf("Informe a faixa etaria da aula:");
  scanf("%d", &turma.idades);

  printf("Informe a quantidade minima de alunos:");
  scanf("%d", &turma.min);

  printf("Informe a quantidade maxima de alunos:");
  scanf("%d", &turma.max);

  // Removendo a quebra de linha da string
  strtok(turma.hora,"\n");

  fp = fopen("aulas.txt", "a");
  if(fp==NULL){
    printf("Erro no cadastro da turma!");
    exit(1);
  }

  // Gravando as informações no arquivo
  fprintf(fp,"%d,%c,%d,%s,%d,%d,%d\n",turma.id, turma.tipo, turma.dia, turma.hora, turma.idades, turma.min, turma.max);
  
 printf("\t\t\nCADASTRO REALIZADO!\n");
  //fechando o arquivo
  fclose(fp);
  
}
/* Inscreve os alunos nas turmas abertas*/
void inscreveAluno(){

  struct aluno aluno;
  struct turma turma;
  
  printf("Informe o id do aluno:");
  scanf("%d", &aluno.id);

  printf("Informe o id da turma:");
  scanf("%d", &turma.id);

  FILE *fp = fopen("turma.txt", "a");
  if(fp==NULL){
    printf("Erro na inscrição do aluno!");
    exit(1);
  }
  //Insere o id do aluno e o id da turma no arquivo
  fprintf(fp,"%d,%d\n", aluno.id, turma.id);

  //fechando o arquivo
  fclose(fp);

  printf("\t\t\nINSCRICAO REALIZADA!\n");
  //Limpa a tela
  system("clear");
}
 /* Cancela inscrição dos alunos em turma e salva no arquivo de inscricoes Canceladas */
void cancelarinscri(){

  struct aluno aluno;
  struct turma turma;
  
  int *alunoscancel;

  FILE *fp = fopen("aulas.txt","r");
  if (fp == NULL){
  printf("ERRO! O arquivo não foi aberto!\n");
  }

  FILE *fptr = fopen("alunos.txt","r");
  if (fptr == NULL){
  printf("ERRO! O arquivo não foi aberto!\n");
  }

  printf("Informe o ID do aluno:");
  scanf("%d",&aluno.id);

  printf("Informe o ID da turma:");
  scanf("%d",&turma.id);

  FILE *novo = fopen("inscricoesCanceladas.txt","a");
  if (novo == NULL){
  printf("ERRO! O arquivo não foi aberto!\n");
  exit(1);
  } 

  while(fscanf(fp,"%d,%c,%d,%s,%d,%d,%d",&turma.id, &turma.tipo,&turma.dia,turma.hora,&turma.idades,&turma.min,&turma.max) != EOF){


  FILE *aux = fopen("aulasAux.txt","a");
    
  fprintf(novo,"%d da AULA %d teve sua inscricao CANCELADA\n",aluno.id,turma.id);
  }

  //fechando o arquivo
  fclose(fp);
  fclose(novo);
  fclose(fptr);
  //Limpa a tela
  system("clear");
}

/* Lê o arquivo turma e joga os devidos alunos(de turmas que estiverem com menos alunos do que o solicitado) para o arquivo aulasCanceladas.txt e fecha a turma */
void fechaTurma()
{
  struct turma turma;
  struct aluno prof;

  int num;

  FILE *fp = fopen("r_aulasConfirmadas.csv", "r");
  
  if(fp == NULL){
    printf("Erro de i/o");
    exit(1);
  }

  FILE *fp1 = fopen("turma.txt", "r");

  if(fp1 == NULL){
    printf("Erro de i/o");
    exit(1);
  }
  
  FILE *fp2 = fopen("aulasCanceladas.txt", "a");
  
  if(fp2 == NULL){
    printf("Erro de i/o");
    exit(1);
  }
  
  printf("Informe o numero desejado de alunos:");
  scanf("%d", &num);

  while(fscanf(fp, "%d, %c,%d,%s,%d,%d,%d", 
  &turma.id,&turma.tipo, &turma.dia, turma.hora, &turma.idades, &turma.min, &turma.max) != EOF){

    printf("\n\n\n%d\n\n\n",contaalunos(turma.id));
    
    if(contaalunos(turma.id)<num){
    
    char linha[150];

    fprintf(fp2,"%d,%d,%s,%s,%s\n",turma.id,turma.dia,turma.hora,"vazio","vazio2"); /*achatelefone(turma.id_prof) retorna "vazio" achaProfEmail retorna "vazio2"*/

    FILE *novo = fopen("r_aulasConfirmadas2.csv", "a");

    if(novo == NULL){
      printf("Erro ao gerar ou escrever novo arquivo");
      exit(1);
    }
    
    struct turma turma2;

    FILE *temp = fopen("r_aulasConfirmadas.csv","r");

    if(temp == NULL){
      printf("Erro ao gerar ou escrever novo arquivo");
      exit(1);
    }

    char temp_linha[150],temp_tipo,temp_id[10],temp_dia[10],temp_hora[4],temp_idade[3],temp_min[3],temp_max[4];

    while(fgets(temp_linha,150,temp) != NULL){
      char * token = strtok(temp_linha, ",");
      for(int count=1; token != NULL; count++ ) {

       if(count==1){
         strcpy(temp_id,token);
       }
       if(count==2){
         temp_tipo=token[0];
       }
       if(count==3){
         strcpy(temp_dia,token);
       }
       if(count==4){
         strcpy(temp_hora,token);
       }
       if(count==5){
         strcpy(temp_idade,token);
       }
       if(count==6){
         strcpy(temp_min,token);
       }
       if(count==7){
         strcpy(temp_max,token);
       }

        turma2.id=atoi(temp_id);
        turma2.tipo=temp_tipo;
        turma2.dia=atoi(temp_dia);
        strcpy(turma2.hora,temp_hora);
        turma2.idades=atoi(temp_idade);
        turma2.min=atoi(temp_min);
        turma2.max=atoi(temp_max);
        
        token = strtok(NULL, ","); //Quebra de linha
        
       }
      
        if(contaalunos(turma2.id)>=num){
          fprintf(novo,"%d,%c,%d,%s,%d,%d,%d\n",turma2.id,turma2.tipo,turma2.dia,turma2.hora,turma2.idades,turma2.min,turma2.max);
        }
       
    }
    //fechando o arquivo
    fclose(temp);
    fclose(novo);
    
    //Removendo o arquivo
    remove("r_aulasConfirmadas.csv");
    //Renomeando o arquivo
    rename("r_aulasConfirmadas2.csv","r_aulasConfirmadas.csv");

    }
    
  }
    //fechando o arquivo
    fclose(fp2);
    fclose(fp);
    //Limpa a tela
    system("clear");
  }
/*Gera um arquivo r_aulasConfirmadas.csv que contém todas as aulas confirmadas de acordo com o arquivo aula.*/
void confirmarTurma(){
  
  struct turma turma;

    FILE *aulas = fopen("aulas.txt","r");
    if(aulas == NULL){
     printf("Erro na leitura");
      exit(1);
    }
    
    char temp2_linha[150],temp2_id[10],temp2_tipo,temp2_dia[10],temp2_hora[4],temp2_idade[3],temp2_min[3],temp2_max[4];
   
    while(fgets(temp2_linha,150,aulas) != NULL){

          char * token = strtok(temp2_linha, ",");
          for(int count2=1; token != NULL; count2++ ) {

       if(count2==1){
         strcpy(temp2_id,token);
       }
       if(count2==2){
         temp2_tipo=token[0];
       }
       if(count2==3){
         strcpy(temp2_dia,token);
       }
       if(count2==4){
         strcpy(temp2_hora,token);
       }
       if(count2==5){
         strcpy(temp2_idade,token);
       }
       if(count2==6){
         strcpy(temp2_min,token);
       }
       if(count2==7){
         strcpy(temp2_max,token);
       }

        turma.id=atoi(temp2_id);
        turma.tipo=temp2_tipo;
        turma.dia=atoi(temp2_dia);
        strcpy(turma.hora,temp2_hora);
        turma.idades=atoi(temp2_idade);
        turma.min=atoi(temp2_min);
        turma.max=atoi(temp2_max);
        
        token = strtok(NULL, ",");
        
       }

      printf("%d,%c,%d,%s,%d,%d,%d\n",turma.id,turma.tipo,turma.dia,turma.hora,turma.idades,turma.min,turma.max);

      int count=contaturma(turma.id);

      if(count>=turma.min){
        printf("turma %d tem %d aluno , entrou pois min %d\n",turma.id,count,turma.min);
        
          FILE *fp2 = fopen("r_aulasConfirmadas.csv","a");
          
          if(fp2 == NULL){
            printf("Erro de i/o");
            exit(1);
          }

          fprintf(fp2,"%d,%c,%d,%s,%d,%d,%d\n",turma.id,turma.tipo,turma.dia,turma.hora,turma.idades,turma.min,turma.max);

          fclose(fp2);

          printf("escrevi : %d,%c,%d,%s,%d,%d,%d em aulaconfirmada\n\n",turma.id,turma.tipo,turma.dia,turma.hora,turma.idades,turma.min,turma.max);

          FILE *original = fopen("aulas.txt","r");
          if(original == NULL ){
            printf("Erro ao abrir arquivo original!");
            exit(1);
          }
          
          FILE *novo = fopen("aulas2.txt","a");
          if(novo == NULL ){
            printf("Erro ao abrir arquivo novo!");
            exit(1);
          }

          struct turma turma2;

          while(fscanf(original,"%d,%c,%d,%s,%d,%d,%d",&turma2.id, &turma2.tipo,&turma2.dia,turma2.hora,&turma2.idades,&turma2.min,&turma2.max) != EOF){

            if(turma2.id!=turma.id){
              fprintf(novo,"%d,%c,%d,%s,%d,%d,%d\n",turma2.id, turma2.tipo,turma2.dia,turma2.hora,turma2.idades,turma2.min,turma2.max);
            }

          }
          //fechando o arquivo
          fclose(novo);
          fclose(fp2);
          //Removendo o arquivo aulas.txt
          remove("aulas.txt");
          //Renomeando o arquivo aulas2.txt para aulas.txt
          rename("aulas2.txt","aulas.txt");

      } 
    }
    //fechando o arquivo
    fclose(aulas);   
}

/* Função newFile
 * --------------
 * Cria um novo arquivo ".txt"
 * fileName: Nome do arquivo
 * action: Comando de execução do arquivo
*/
void newFile(char fileName[], char action[]){
	FILE *myFile = fopen(fileName, action);
	if(myFile == NULL)
  {
		printf("Arquivo não encontrado.");
		exit(0);
	}
}
/* Função: verifyFile
 * ----------------
 * Verifica se o arquivo existe
 * myFile: parametro que o nome do arquivo
*/
int verificarquivo(char meuarquivo[]){
	FILE *fileToVerify = fopen(meuarquivo, "r");
	if(fileToVerify)
		return 1; 
	else
		return 0;
}

/*Está função gera id para as funções que necessita do ID*/
int gerarID(char *arquivo,char *arquivo2){

  FILE *fp = fopen(arquivo,"r");
  if(fp==NULL){
    printf("Erro ao abrir arquivo: %s",arquivo);
    exit(1);
  }

  char temp_linha[150],temp_codigo[5];
  
   while(fgets(temp_linha,150,fp) != NULL){
      char * token = strtok(temp_linha, ",");
      for(int count=1; token != NULL; count++ ) {

      if(count==1){
        strcpy(temp_codigo,token);
      }
      
      token = strtok(NULL, ",");
    }
  }

  int lastID1=atoi(temp_codigo);


  if(lastID1==0){
  lastID1=000;
}

  FILE *fp2 = fopen(arquivo2,"r");
    if(fp2==NULL){
    printf("Erro ao abrir arquivo: %s",arquivo2);
      exit(1);
    }
  int lastID2=0,aux;

  char temp_linha2[150],temp_codigo2[10];

  while(fgets(temp_linha2,150,fp2) != NULL){
      char * token = strtok(temp_linha2, ",");
      for(int count=1; token != NULL; count++ ) {

      if(count==1){
        strcpy(temp_codigo2,token);
      }
     
      token = strtok(NULL, ",");
    }
    aux=atoi(temp_codigo2);
    
    if(aux>lastID2)
    lastID2=aux;
  }

  if(strcmp(arquivo,"aulas.txt")==0){

    if(maiorconfirmado()>lastID1&&maiorconfirmado()>lastID2)return maiorconfirmado()+1;
    
  }

  if(lastID1>lastID2){
    return lastID1+1;
  }
  //não é necessessario abrir um else, pq se ele entrar no primeiro if a função fecha
  return lastID2+1;
}

/*Conta o numero de alunos que contem no arquivo dentra do arquivo turma*/
int contaalunos(int id_turma){
  
    FILE *fp = fopen("turma.txt", "r");
    
      if(fp == NULL){
        printf("Erro de i/o");
        exit(1);
      }

    int count=0;
    char temp_linha[20],temp_idaluno[10],temp_idturma[10];

    while(fgets(temp_linha,20,fp) != NULL){
      
      char * token = strtok(temp_linha, ",");
      
      for(int count=1; token != NULL; count++ ) {

       if(count==2){
         strcpy(temp_idturma,token);
       }
     
        token = strtok(NULL, ",");
       }
       int id=atoi(temp_idturma);
       if(id==id_turma)count++;
    }
  //fechando o arquivo
  fclose(fp);

  return count;
}

/*Essa Função é para achar o telefone do professor, recebendo por parametro o id do professor para indentificar o nome do professor*/
char *achatelefone(int id_prof){

   FILE *fp = fopen("professor.txt", "r");
    
      if(fp == NULL){
        printf("Erro de i/o");
        exit(1);
      }
  
  char temp_linha[150],temp_id[10],temp_telefone[20];

    while(fgets(temp_linha,150,fp) != NULL){
      
      char * token = strtok(temp_linha, ",");
      for(int count=1; token != NULL; count++ ) {

       if(count==1){
         strcpy(temp_id,token);
       }
       if(count==4){
         strcpy(temp_telefone,token);
       }
     
        token = strtok(NULL, ",");
       }
      int id=atoi(temp_id);
      
      if(id_prof==id){

        return temp_telefone; 
    }

  }
  return "vazio";
}
/* Essa função é para encontrar o email do professor, passando por parametro o id do professor */ 
char *achaProfEmail(int id_prof){

   FILE *fp = fopen("professor.txt", "r");
    
      if(fp == NULL){
        printf("Erro de i/o");
        exit(1);
      }
  
  char temp_linha[150],temp_id[10],temp_email[100];

    while(fgets(temp_linha,150,fp) != NULL){
      
      char * token = strtok(temp_linha, ",");
      for(int count=1; token != NULL; count++ ) {

       if(count==1){
         strcpy(temp_id,token);
       }
       if(count==4){
         strcpy(temp_email,token);
       }
     
        token = strtok(NULL, ",");
       }
      int id=atoi(temp_id);
      
      if(id_prof==id){

        return temp_email; 
    }

  }
  return "vazio2";
}
//Conta quantas turmas tem no arquivo
int contaturma(int n){

  FILE *turmas = fopen("turma.txt","r");
    if(turmas==NULL){
      printf("Erro na leitura");
      exit(1);
    }
      int aluno,id,count=0;
      
      while(fscanf(turmas,"%d,%d",&aluno,&id)!=EOF){
        if(id==n){
          count++;
          }
      }
      return count;
}
 //É utilizada para auxiliar a função de gerarID
int maiorconfirmado(){

  FILE *arq = fopen("r_aulasConfirmadas.csv","r");
  if(arq==NULL){
    printf("Erro ao abrir aulas confirmadas");
    exit(1);
  }

  char linha[150],codigo[10];

    int maior=0;

    while(fgets(linha,150,arq) != NULL){
        char * token = strtok(linha, ",");
        for(int count=1; token != NULL; count++ ) {

        if (count == 1){
          strcpy(codigo,token);
        }
          
          token = strtok(NULL, ",");
        }

        int novoaux=atoi(codigo);
        if(novoaux>maior){
          maior=novoaux;
          }
   }

    return maior;
}