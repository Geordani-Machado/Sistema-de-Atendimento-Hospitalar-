#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <string.h>

char paciente[50];

int menucontrole = 0;
int tam = 50;
int ini = -1;
int fim = -1;

// fila pro verde | fila pro amarelo 2 filas . 	

struct Paciente{
    char nome[50]; //salva o nome do paciente na fila
    char prioridade; //salva a prioridade do paciente  
    int posicaoGeral; // salva a posição do paciente da fila por ordem de chegada.
		int posicaoPrioridade; // salva a posiçaõ do paciente pela prioridade V ou A
};

typedef struct Paciente Paciente;

// o vetor salva os pacientes por ordem de chegada.
// para pegar a ordem por prioridade usamos um if para prioridade , pega a posição da fila 
//ana - v - 1 \ flavio - a - 10 \ pedro - v - 30 
// fila por chegada | fila verde | fila amarela.
// passagem por atribuição , passagem por definição | define o  valor e sobrescreve o original | passa o valor por copia e não mexe na original.
// char *c; int *d ; float *f

void Cadastrar(){
	int menucontrole = 0;
	char escolha = ' ';
	struct Paciente NomePaciente;
	printf("--------- Cadastro ---------- \n");
	printf("Cadastrar novo Paciente :\n");
	printf("Qual o nome do Paciente ?\n");
	printf("Digite o nome: ");
	scanf ("%[^\n]", NomePaciente.nome);
	  __fpurge(stdin);		
	
	printf("\n Qual a urgência do paciente ?\n");
	printf("V - Verde | A - Amarelo \n");
	printf("Digite a urgência: ");
    __fpurge(stdin);
	scanf(" %c", &escolha);
			
	  switch(escolha)
		{
			case 'V':
      case 'v':
				//system("color 2F");
				printf("--------- Prioridade Verde ---------- \n");
				printf("Prioridade definida como Verde! \n");
				printf("-------------------------------------- \n");
				 
			break;

      case 'A':
      case 'a':
        //system("color 6F");
        printf("--------- Prioridade Amarela ---------- \n");
				printf("Prioridade definida como Amarela! \n");
				printf("-------------------------------------- \n");
				 
        break;
			
      default:
				printf("--------- Erro ---------- \n");
				printf("Nosso sistema só aceita A ou V como níveis de prioridade! \n");
				printf("-------------------------------------- \n");
				
		}
}
void Remover(){
  int menucontrole = 0;
  char escolha = ' ';
	char nome = ' ';
	printf("--------- Remover Paciente da Fila ---------- \n");
	printf("Remover Paciente :\n");
	printf("Qual o nome do Paciente ?\n");
	printf("Digite o nome: ");
	scanf("%c", &nome);
	printf("Qual a urgência do paciente ?\n");
	printf("Digite a urgência: ");
	printf("V - Verde | A - Amarelo \n");
 	scanf("%c" , &escolha);

	 	switch(escolha)
		{
			case 'V':
      case 'v':
				printf("--------- Prioridade Verde ---------- \n");
				printf("Prioridade definida como Verde! \n");
				printf("-------------------------------------- \n");
			break;

      case 'A':
      case 'a':
        printf("--------- Prioridade Amarela ---------- \n");
				printf("Prioridade definida como Amarela! \n");
				printf("-------------------------------------- \n");
      break;
			
      default:
				printf("--------- Erro ---------- \n");
				printf("Nosso sistema só aceita A ou V como níveis de prioridade! \n");
				printf("-------------------------------------- \n");
		}
}
void Pesquisar(){
  int menucontrole = 0;
	printf("--------- Consultar Fila ---------- \n");
	char escolha = ' ';
	char nome = ' ';
	printf("Qual o nome do Paciente ?\n");
	printf("Digite o nome: ");
	scanf("%c", &nome);
	printf("Qual a urgência do paciente ?\n");
	printf("Digite a urgência: ");
	printf("V - Verde | A - Amarelo \n");
 	scanf("%c" , &escolha);

	 	switch(escolha)
		{
			case 'V':
      case 'v':
				printf("--------- Prioridade Verde ---------- \n");
				//busca na fila somente os pacientes com a prioridade verde
			
			break;

      case 'A':
      case 'a':
        printf("--------- Prioridade Amarela ---------- \n");
				//busca na fila somente os pacientes com a prioridade amarela
				
      break;
			
      default:
				printf("--------- Erro ---------- \n");
				printf("Nosso sistema só aceita A ou V como níveis de prioridade! \n");
				printf("-------------------------------------- \n");
			}
		
}
void VfilaCompleta(){
  int menucontrole = 0;
	int f;
	printf("--------- Visualizar Fila Completa ---------- \n");
	// mostra a fila completa independente do nivel de prioridade
	// criar um for que corre toda a fila e mostra no console o nome, prioridade e posição

	if(ini == fim){
		printf("--------- Fila Vazia! :( ---------- \n");
		printf("nenhum paciente foi encontrado \n");
		printf("-------------------------------------\n");
		
	}else{

		for(f=0;f>49;f++){
			// correr a fila e imprimir (nome , prioridade , posição na fila)
		}
	}
}
void VfilaTipoUrgencia(){
  int menucontrole = 0;
	printf("--------- Visualizar Tipo de Urgência ---------- \n");
  // mostra a fila divida por nível de prioridade 

	char escolha = ' ';
	char nome = ' ';
	printf("Qual o nome do Paciente ?\n");
	printf("Digite o nome: ");
	scanf("%c", &nome);
	printf("Qual a urgência do paciente ?\n");
	printf("Digite a urgência: ");
	printf("V - Verde | A - Amarelo \n");
 	scanf("%c" , &escolha);

	 	switch(escolha)
		{
			case 'V':
      case 'v':
				printf("--------- Prioridade Verde ---------- \n");
				//busca na fila somente os pacientes com a prioridade verde
				
			
			break;

      case 'A':
      case 'a':
        printf("--------- Prioridade Amarela ---------- \n");
				//busca na fila somente os pacientes com a prioridade amarela
				
      break;
			
      default:
				printf("--------- Erro---------- \n");
				printf("Nosso sistema só aceita A ou V como níveis de prioridade! \n");
				printf("-------------------------------------- \n");
		}
  }
	
void ConsultarFila(){
  int menucontrole = 0;
	printf("--------- Consultar Fila ---------- \n");
// mostra o tamanho da fila , quais a posições ocupadas , quais as posições livres na fila.
}

void Menu(){
  int i;

	do{
		printf("--------- Menu ---------- \n");
		printf("1 - Cadastrar Paciente \n");
		printf("2 - Remover Paciente \n");
		printf("3 - Pesquisar Paciente por nivel de urgência \n");
		printf("4 - Visualizar fila completa \n");
 	 	printf("5 - Visualizar fila por tipo de urgência \n");
  	printf("6 - Consultar situação da fila \n");
		printf("Digite uma Opção: ");
		scanf("%d" , &i);

			switch(i)
		{
      case 1:
				Cadastrar();
			break;

      case 2:
				Remover();
      break;

      case 3:
				Pesquisar();
      break;

      case 4:
				VfilaCompleta();
      break;

      case 5:
      	VfilaTipoUrgencia();
      break;

      case 6:
          ConsultarFila();
        break;
      
      default: 
				printf("---------- Erro! ---------- \n");
        printf("Opção inválida! :( \n Tente novamente! \n");
				printf("---------------------------- \n");
				menucontrole =1;
				
		}
		
	}while(menucontrole ==1); 
}

int main(void){ // chama o menu
	setlocale (LC_ALL,"portuguese"); // define o idioma do projeto como portugês brasil
	Menu();
}