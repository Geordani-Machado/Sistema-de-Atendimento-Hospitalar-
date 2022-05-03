#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <string.h>

int menucontrole = 1;
int tam;
int ini,fim;
int iniAmarelo=0 , fimAmarelo=23;
int iniVerde=24, fimVerde=50;
int tamfilaAmarela = 0;
int tamfilaVerde = 0;
int filaAmarela;
int filaVerde;

struct Paciente{
  char nome[50];//salva o nome do paciente na fila
	char sobrenome[50];//salvar o sobrenome 
  char prioridade;//salva a prioridade do paciente   V ou A
  int posicaoGeral; // salva a posição do paciente da fila por ordem de chegada.
	int posicaoPrioridadeVerde;// salva a posição do paciente p ela prioridade Verde
	int posicaoPrioridadeAmarela;// salva a posição do paciente pela prioridade Amarela
} ;
typedef struct Paciente Paciente;
Paciente cadastro[50]; //vetor | dividir ele 2/ fila 0 - 25 | 26 -50

// sistema de cores
#define VERDE "\x1b[32m"
#define AMARELO "\x1b[93m"
#define VERMELHO "\x1b[31m"
#define AZUL "\x1b[34m"
#define RESET "\x1b[0m"

void Cadastrar(){
	int menucontrole = 0;
	char escolha = ' ';
	struct Paciente Paciente;
	printf("--------- Cadastro ---------- \n");
	printf("Cadastrar novo Paciente :\n");
	printf("Qual a urgência do paciente ?\n");
	printf(VERDE"V - Verde");
	printf(RESET" | ");
	printf(AMARELO" A - Amarelo \n" RESET);
	printf("Digite a urgência: ");
	scanf(" %c", &escolha);

	char verde = 'v';
	char amarelo = 'a';
	  switch(escolha)
		{
			case 'V':
      case 'v':
				printf(VERDE"--------- Prioridade Verde ---------- \n"RESET);
				printf(VERDE"Prioridade definida como Verde! \n"RESET);
				printf("Qual o nome do Paciente ?\n");
				printf("Digite o nome e sobrenome: ");
				scanf(" %s%s", cadastro[iniVerde].nome , cadastro[iniVerde].sobrenome);
				printf(VERDE"-------------------------------------- \n" RESET);

				printf(" ");
				printf(" ");

				printf(VERDE"--------- Sucesso ! ---------- \n");
				printf(VERDE"Conta criada com sucesso! \n");
				printf(VERDE"-------------------------------------- \n" RESET);

				cadastro[iniVerde].prioridade = 'V';
				cadastro[iniVerde].posicaoPrioridadeVerde++;
				tamfilaVerde++;
				iniVerde++;
				
			break;

      case 'A':
      case 'a':
        printf(AMARELO"--------- Prioridade Amarela ---------- \n" RESET);
				printf(AMARELO"Prioridade definida como Amarela! \n" RESET);
				printf("Qual o nome do Paciente ?\n");
				printf("Digite o nome e sobrenome: ");
				scanf(" %s%s", cadastro[iniAmarelo].nome , cadastro[iniAmarelo].sobrenome);
				printf(AMARELO"-------------------------------------- \n" RESET);

				printf(" ");
				printf(" ");

				printf(VERDE"--------- Sucesso ! ---------- \n");
				printf(VERDE"Conta criada com sucesso! \n");
				printf(VERDE"-------------------------------------- \n" RESET);

				cadastro[iniAmarelo].prioridade = 'A';
				cadastro[iniAmarelo].posicaoPrioridadeAmarela++;
				tamfilaAmarela++;
				iniAmarelo++;
				
      break;
			
      default:
				printf(VERMELHO"--------- Erro ---------- \n");
				printf("Nosso sistema só aceita A ou V como níveis de prioridade! \n");
				printf("-------------------------------------- \n" RESET);
		}

	tam = tam +1;
	
}
void Remover(){
  menucontrole = 0;
  char escolha = ' ';
	char nome = ' ';
	struct Paciente Paciente;
	printf("--------- Remover Paciente da Fila ---------- \n");

	// fila amarela != 0 | fila amarela -1 | caso contrario | fila amarela == 0 | fila verde verificar se != | Fila verde -1

	if(filaAmarela != 0){
		filaAmarela--; 
		iniAmarelo++;
	}else if (filaVerde != 0){
		filaVerde--;
		iniVerde++;
	}

		if(tam == 0){
		 printf(VERMELHO" Fila Vazia! :( \n");
		}else{
			ini++;
			
			printf(VERDE"--------- Paciente removido com sucesso ! :)---------- \n");
		}
	menucontrole =1;
}
void Pesquisar(){
  menucontrole = 0;
	struct Paciente Paciente;
	printf(AZUL"<------------ Consultar Fila -------> \n" RESET);
	char escolha = ' ';
	char nome[50];
	char sobrenome[50];
	printf("Qual o nome do Paciente ?\n");
	printf("Digite o nome: ");
	scanf(" %s%s", nome , sobrenome);
	printf("Qual a urgência do paciente ?\n");
	printf("Digite a urgência: ");
	printf(VERDE"V - Verde");
	printf(RESET" | ");
	printf(AMARELO"A - Amarelo \n" RESET);
 	scanf(" %c", &escolha);

  int i;
	 	switch(escolha)
		{
			case 'V':
      case 'v':

		if(cadastro->nome == nome && cadastro->prioridade == 'v' || cadastro->nome == nome && cadastro->prioridade == 'V' ){

							printf("Esse usuario esta como: \n");
							printf(" Nome: ");
					//		printf("%s", Paciente.nome);
							printf(" \n ");
							printf("Sobrenome: ");
					//		printf("%s", Paciente.sobrenome);
							printf(" \n ");
							printf("Prioridade: ");
							printf(" \n ");
							printf("Posição Geral: ");
					//		printf("%d", Paciente.posicaoGeral[0]); // criar um for pra mudar o valor do vetor
							printf(" \n ");
							printf("Posição por prioridade: ");
					//	printf("%d", Paciente.posicaoPrioridadeVerde[0]); // criar um for pra mudar o valor do vetor
							printf(" \n ");
							printf(VERDE"-------------------------------------- \n" RESET);
					
				}else{
					printf(VERMELHO"---------> Erro ---------- \n" RESET);
					printf("nenhum paciente encontrado! :( ");
				}
				
			break;

      case 'A':
      case 'a':

        for(i = 0 ; i < tam ; i++){
					
				if(cadastro[i].prioridade == 'a' || cadastro[i].prioridade == 'A'){
        
				//busca na fila somente os pacientes com a prioridade amarela
				printf("Esse usuario esta como: \n");
				printf(" Nome: ");
				printf("%s", cadastro[i].nome);
				printf(" \n ");
				printf("Sobrenome: ");
				printf("%s", cadastro[i].sobrenome);
				printf(" \n ");
				printf("Prioridade: ");
				printf("%c", cadastro[i].prioridade);
				printf(" \n ");
				printf("Posição Geral: ");
				printf("%d", cadastro[i].posicaoGeral +1); // criar um for pra mudar o valor do vetor
				printf(" \n ");
				printf("Posição por prioridade: ");
				printf("%d", cadastro[i].posicaoPrioridadeAmarela +1); // criar um for pra mudar o valor do vetor
				printf(" \n ");
				printf(AMARELO"-------------------------------------- \n" RESET);

					}else{
					printf(VERMELHO"---------> Erro ---------- \n" RESET);
					printf("nenhum paciente encontrado! :( ");
					}
				}
      break;
			
      default:
				printf(VERMELHO"--------- Erro ---------- \n" RESET);
				printf("Nosso sistema só aceita A ou V como níveis de prioridade! \n");
				printf("-------------------------------------- \n");
			}

	menucontrole =1;
		
}
void VfilaCompleta(){
  menucontrole = 0;
	struct Paciente Paciente;

	printf(AZUL"--------- Visualizar Fila Completa ---------- \n" RESET);
	// mostra a fila completa independente do nivel de prioridade
	// criar um for que corre toda a fila e mostra no console o nome, prioridade e posição

	if(tam == 0){
		printf(VERMELHO"--------- Erro ---------- \n" RESET);
		printf(" Fila Vazia! , nenhum paciente foi encontrado :(\n");
		printf("-------------------------------------\n");
		
	}else{
	int i = ini;
	
		int indice=1;
			do
				{
					printf(" %d" , indice);
					printf(" - ");
					printf("Nome: ");
					printf("%s" , cadastro[i].nome);
					printf(" ");
					printf("%s" , cadastro[i].sobrenome);
					printf(" ");
					printf("Prioridade: ");
					printf("%c" , cadastro[i].prioridade);
					printf(" ");
					printf("\n");
					i++;
					indice++;
					
				}while(i<50);
		}

	menucontrole =1;
	}

void VfilaTipoUrgencia(){
  menucontrole = 0;
	printf(AZUL"--------- Visualizar Tipo de Urgência ---------- \n" RESET);
  // mostra a fila divida por nível de prioridade 

	char escolha = ' ';
	char nome = ' ';
	struct Paciente Paciente;
	printf("Qual a urgência do paciente ?\n");
	printf(VERDE"V - Verde");
	printf(RESET" | ");
	printf(AMARELO"A - Amarelo \n" RESET);
	printf("Digite a urgência: ");
 	scanf(" %c", &escolha);

	int indice1=0;
	int indice2=25;
	
	 	switch(escolha)
		{
			case 'V':
      case 'v':
				
        printf(VERDE"--------- Prioridade Verde ---------- \n" RESET);
        if(tamfilaVerde == 0){
					printf(VERMELHO"Erro ---> \n" RESET);
					printf("A fila está vazia! :( \n");
					printf("-------------------------------------- \n");
					}else{
						for(int a=iniVerde ; a < 50; a++){
						printf("%d" , indice2+1); 
						printf(" - ");
						printf("%s" , cadastro[a-1].nome); 
						printf(" - ");
						printf("%s" , cadastro[a-1].sobrenome);
						printf("\n");
						iniVerde++;
						indice2++;
			}
		}
      break;
      
      case 'A':
      case 'a':
        printf(AMARELO"--------- Prioridade Amarela ---------- \n" RESET);
				if(tamfilaAmarela != 0){
					
					for(int i=iniAmarelo; i <= 23; i++){
						printf("%d" , indice1+1);
						printf(" - ");
						printf("%s" , cadastro[i].nome); 
						printf(" - ");
						printf("%s" , cadastro[i].sobrenome);
						printf("\n");
						iniAmarelo++;
						indice1++;
					}
					
				}else{
					printf(VERMELHO"Erro ---> \n" RESET);
					printf("A fila está vazia! :( \n");
					printf("-------------------------------------- \n");	
			}
				
      break;
			
      default:
				printf(VERMELHO"--------- Erro---------- \n" RESET);
				printf("Nosso sistema só aceita A ou V como níveis de prioridade! \n");
				printf("-------------------------------------- \n" );
		}

	menucontrole =1;
  }
	
void ConsultarFila(){
  int menucontrole = 0;
	printf(AZUL"--------- Consultar Fila ---------- \n" RESET);
// mostra o tamanho da fila , quais a posições ocupadas , quais as posições livres na fila.

	printf("Tamanho da fila: ");
	printf("%d" , tam);
	printf(" \n");
	printf("Posições ocupadas: ");
	printf("%d" , tam);
	printf(" \n");
	printf("Posições livres: ");
	printf("%d" , 50 - tam);
	printf(" \n");

	menucontrole =1;
}

void Menu(){
  int i;

	do{
		
		printf(VERDE"--------------------- Menu ---------------- \n" RESET);
		printf("1 - Cadastrar Paciente \n");
		printf("2 - Remover Paciente \n");
		printf("3 - Pesquisar Paciente por nível de urgência \n");
		printf("4 - Visualizar fila completa \n");
 	 	printf("5 - Visualizar fila por tipo de urgência \n");
  	printf("6 - Consultar situação da fila \n");
		printf("Digite uma Opção: ");
		scanf("%d", &i);
		printf(VERDE"---------------------------------------- \n" RESET);

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
				printf(VERMELHO"---------- Erro! ---------- \n");
        printf("Opção inválida! :( \nTente novamente! \n");
				printf("---------------------------- \n" RESET);
		}
	}while(menucontrole ==1); 
}

int main(void){ 
	setlocale (LC_ALL,"portuguese"); // define o idioma do projeto como portugês brasil
	Menu(); // chama o menu
}