#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "Lib/academiaSys.h"
#include "Lib/prog2Utils.h" // biblioteca de funções auxiliares. Por exemplo editar informações de arquivos.
#define CAPACIDADE_MAXIMA 100 // valor total para armazenar em uma estrutura

struct aluno{
	int id;
	char nome[300];
	char cpf[15];
	char telefone[50];
	char email[100];
};

struct aula{
	int id;
	char tipo; 
  int dia;
	char horario[6];
	int id_prof;
	int minimo;
	int maximo;
	char faixa_etaria[6];
	struct aluno alunos[CAPACIDADE_MAXIMA];
};

struct turma{
  int dia;
  int id_prof;
  int idades;
  int max;
  int min;
};

// **aqui vão os protótipos de suas funções**

// por exemplo, uma função para salvar as aulas em um arquivo
void salvarAula(struct aula *aulasAsalvar);

// função para mostrar menu na tela e ler opção digitada
int lerOpcao();

//void cadastrarAluno();

// Programa Principal 
int main ()
{
		struct aula aulas[CAPACIDADE_MAXIMA];
		
    int opcao=1;
    
    do{
        puts("     🏋️ 💪  Academia superação 💪 🏋️ \n            Digite a opcao: ");
        opcao = lerOpcao();
        switch (opcao)
        {
           case 1: // 1- Cadastra aluno
            //Limpa a tela
            system("clear");

           // Se o arquivo não existir, é gerado um novo arquivo
				    if(!verificarquivo("alunos.txt"))
            { 
					    newFile("alunos.txt","w");
					    cadastrarAluno();
				    }// Executa a função
				    else {
					  cadastrarAluno();
				    }
            
            break;

           case 2: // 2-  Cadastrar professor
            //Limpa a tela
            system("clear");
             //void cadastrarProfessor()
             if(!verificarquivo("professor.txt"))
            { 
					    newFile("professor.txt","w");
					    cadastrarProfessor();
				    }// Executa a função
				    else {
					  cadastrarProfessor();
				    }
             break;

					 case 3: // 3- Cadastrar turma
            //Limpa a tela
            system("clear");

            if(!verificarquivo("aulas.txt"))
            { 
					    newFile("aulas.txt","w");
					    cadastrarTurma();
				    }// Executa a função
				    else if(!verificarquivo("aulasCanceladas.txt"))
            {
              newFile("aulasCanceladas.txt","w");
					    cadastrarTurma();
				    }
            else
            {
              cadastrarTurma();
            }
             break;
             
           case 4:  // 4- Inscrever aluno

             if(!verificarquivo("turma.txt"))
            { 
					    newFile("turma.txt","w");
					    inscreveAluno();
				    }// Executa a função
				    else {
					  inscreveAluno();
				    }
             break;
             //Limpa a tela
             system("clear");
             
           case 5:  // 5- Cancelar inscrição
             //Limpa a tela
             system("clear");

             if(!verificarquivo("inscricoesCanceladas.txt"))
             {
               newFile("inscricoesCanceladas.txt","w");
               cancelarinscri();          
             }
             else{
              cancelarinscri(); 
             }
             break; 
       
           case 6:  // 6- Fechar turmas
           //Limpa a tela
           system("clear");

            if(!verificarquivo("aulasCanceladas.txt"))
            { 
					    newFile("aulasCanceladas.txt","w");
					    fechaTurma();
				    }// Executa a função
				    else {
					  fechaTurma();
				    }
             break;
           
           case 7: confirmarTurma(); // 7- Confirmar turmas
            //  system("clear");

             break;

						case 8:  // 8- Fechar o programa
						 //Limpa a tela
             system("clear");
             //salvarAula(aulas);
             printf("--------------------------------------\n");
             printf("💥\tO PROGRAMA FOI ENCERRADO !!!\t ⚡\n");
             printf("⚡\tAQUI É BODYBUILDER, BIRL !!!\t 💥\n");
             printf("--------------------------------------");
             exit(0);
						
             break;

						default:
							printf("Opcao invalida, tente novamente!\n");
							break;
                      
        }
     }while (opcao>0 && opcao<9);

  return 0;
} // fim do main