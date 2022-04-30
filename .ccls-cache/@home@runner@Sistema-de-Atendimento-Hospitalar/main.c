#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <string.h>

int menucontrole = 1;
int tam;
int ini , fim;
int tamfilaAmarela = 0;
int tamfilaVerde = 0;


struct Paciente{
  char nome[50];//salva o nome do paciente na fila
	char sobrenome[50];//salvar o sobrenome 
  char prioridade;//salva a prioridade do paciente   V ou A
  int posicaoGeral[50]; // salva a posição do paciente da fila por ordem de chegada.
	int posicaoPrioridadeVerde[50];// salva a posição do paciente pela prioridade Verde
	int posicaoPrioridadeAmarela[50];// salva a posição do paciente pela prioridade Amarela
} ;

typedef struct Paciente Paciente;

Paciente cadastro[50]; //vetor 

// sistema de cores
#define VERDE  "\x1b[32m"
#define AMARELO "\x1b[93m"
#define VERMELHO "\x1b[31m"
#define AZUL "\x1b[34m"
#define RESET "\x1b[0m"


void criaFila(int *ini, int *fim){
    (*ini) = -1;
    (*fim) = 0;
}

void Cadastrar(){
	int menucontrole = 0;
	char escolha = ' ';
	struct Paciente Paciente;
	printf("--------- Cadastro ---------- \n");
	printf("Cadastrar novo Paciente :\n");
	printf("Qual o nome do Paciente ?\n");
	printf("Digite o nome e sobrenome: ");
	scanf(" %s%s", cadastro[tam].nome , cadastro[tam].sobrenome);
	printf("Qual a urgência do paciente ?\n");
	printf("V - Verde | A - Amarelo \n");
	printf("Digite a urgência: ");
	scanf(" %c", &escolha);

	char verde = 'v';
	char amarelo = 'a';
	  switch(escolha)
		{
			case 'V':
      case 'v':
				printf(VERDE"--------- Prioridade Verde ---------- \n");
				printf(VERDE"Prioridade definida como Verde! \n");
				printf(VERDE"-------------------------------------- \n" RESET);
				
				cadastro[tam].prioridade = 'v';
				cadastro[tam].posicaoPrioridadeVerde[tam] = tam;
				
			break;

      case 'A':
      case 'a':
        printf(AMARELO"--------- Prioridade Amarela ---------- \n");
				printf(AMARELO"Prioridade definida como Amarela! \n");
				printf(AMARELO"-------------------------------------- \n" RESET);

				cadastro[tam].prioridade = 'a';
				cadastro[tam].posicaoPrioridadeAmarela[tam] = tam;
				
      break;
			
      default:
				printf(VERMELHO"--------- Erro ---------- \n");
				printf("Nosso sistema só aceita A ou V como níveis de prioridade! \n");
				printf("-------------------------------------- \n" RESET);
		}

	fim = fim + 1;
	tam = tam +1;
	
}
void Remover(){
  menucontrole = 0;
  char escolha = ' ';
	char nome = ' ';
	struct Paciente Paciente;
	printf("--------- Remover Paciente da Fila ---------- \n");
	printf("Qual a posição geral do paciente :\n");
	printf("Digite a posição: ");
	scanf("%d", Paciente.posicaoGeral);
	printf("Qual a urgência do paciente ?\n");
	printf("V - Verde | A - Amarelo \n");
	printf("Digite a urgência: ");
 	scanf(" %c", &escolha);

	 	switch(escolha)
		{
			case 'V':
      case 'v':
				printf("--------- Prioridade Verde ---------- \n");
				printf("Qual o nome do Paciente ?\n");
				scanf(" %s%s", Paciente.nome , Paciente.sobrenome);
				printf("Qual o numero do paciente de acordo com essa prioridade ?\n");
				printf("Digite o numero: ");
				scanf(" %d", Paciente.posicaoGeral);
				printf("-------------------------------------- \n");
			break;

      case 'A':
      case 'a':
        printf("--------- Prioridade Amarela ---------- \n");
				printf("Qual o nome do Paciente ?\n");
				scanf(" %s%s", Paciente.nome , Paciente.sobrenome);
				printf("Qual o numero do paciente de acordo com essa prioridade ?\n");
				printf("Digite o numero: ");
				scanf(" %d", Paciente.posicaoGeral);
				printf("-------------------------------------- \n");
      break;
			
      default:
				printf(VERMELHO"--------- Erro ---------- \n");
				printf("Nosso sistema só aceita A ou V como níveis de prioridade! \n");
				printf("-------------------------------------- \n");
		}
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
	printf("V - Verde | A - Amarelo \n");
 	scanf(" %c", &escolha);

  int i;
	 	switch(escolha)
		{
			case 'V':
      case 'v':

				// fazer um for | if pra verificar se ele esta nessa prioridade


				if(cadastro->nome == nome && cadastro->prioridade == 'v' || cadastro->nome == nome && cadastro->prioridade == 'V' ){

							printf("Esse usuario esta como: \n");
							printf(" Nome: ");
							printf("%s", Paciente.nome);
							printf(" \n ");
							printf("Sobrenome: ");
							printf("%s", Paciente.sobrenome);
							printf(" \n ");
							printf("Prioridade: ");
							printf(" \n ");
							printf("Posição Geral: ");
							printf("%d", Paciente.posicaoGeral[0]); // criar um for pra mudar o valor do vetor
							printf(" \n ");
							printf("Posição por prioridade: ");
							printf("%d", Paciente.posicaoPrioridadeVerde[0]); // criar um for pra mudar o valor do vetor
							printf(" \n ");
							printf(VERDE"-------------------------------------- \n" RESET);
					
				}else{
					printf(VERMELHO"---------> Erro ---------- \n" RESET);
					printf("nenhum paciente encontrado! :( ");
				}
				
			break;

      case 'A':
      case 'a':

        for(i = 0 ; i < 50 ; i++) 
				  if(cadastro[i].nome == nome && cadastro[i].prioridade == 'a' || cadastro[i].nome == nome && cadastro[i].prioridade == 'A' ){
				
        
				//busca na fila somente os pacientes com a prioridade amarela
				printf("Esse usuario esta como: \n");
				printf("Nome: ");
				printf("%s", Paciente.nome);
				printf(" \n ");
				printf("Sobrenome: ");
				printf("%s", Paciente.sobrenome);
				printf(" \n ");
				printf("Prioridade: ");
			//	printf("%s", Paciente.prioridade);
				printf(" \n ");
				printf("Posição Geral: ");
				printf("%d", Paciente.posicaoGeral[0]); // criar um for pra mudar o valor do vetor
				printf(" \n ");
				printf("Posição por prioridade: ");
				printf("%d", Paciente.posicaoPrioridadeAmarela[0]); // criar um for pra mudar o valor do vetor
				printf(" \n ");
				printf(AMARELO"-------------------------------------- \n" RESET);

					}else{
					printf(VERMELHO"---------> Erro ---------- \n" RESET);
					printf("nenhum paciente encontrado! :( ");
					}
      break;
			
      default:
				printf(VERMELHO"--------- Erro ---------- \n" RESET);
				printf("Nosso sistema só aceita A ou V como níveis de prioridade! \n");
				printf("-------------------------------------- \n");
			}
		
}
void VfilaCompleta(){
  menucontrole = 0;
	struct Paciente Paciente;

	printf(AZUL"--------- Visualizar Fila Completa ---------- \n" RESET);
	// mostra a fila completa independente do nivel de prioridade
	// criar um for que corre toda a fila e mostra no console o nome, prioridade e posição

	if(ini == fim){
		printf(VERMELHO"--------- Erro ---------- \n" RESET);
		printf(" Fila Vazia! , nenhum paciente foi encontrado :(\n");
		printf("-------------------------------------\n");
		
	}else{
		int i;
			do
				{
					printf(" %d" , i+1);
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
					
				}while(i<tam);
			
		}
	}

void VfilaTipoUrgencia(){
  menucontrole = 0;
	printf(AZUL"--------- Visualizar Tipo de Urgência ---------- \n" RESET);
  // mostra a fila divida por nível de prioridade 

	char escolha = ' ';
	char nome = ' ';
	struct Paciente Paciente;
	printf("Qual a urgência do paciente ?\n");
	printf("V - Verde | A - Amarelo \n");
	printf("Digite a urgência: ");
 	scanf(" %c", &escolha);

	 	switch(escolha)
		{
			case 'V':
      case 'v':
				printf(VERDE"--------- Prioridade Verde ---------- \n" RESET);
        if(tamfilaVerde == 0){
					printf(VERMELHO "Erro ---> \n" RESET);
					printf("A fila está vazia! :( \n");
					printf("-------------------------------------- \n");
					
				}else{
				for(int i=0; i < tamfilaVerde; i++){
					//printf(" fora do if ");
					if(cadastro[i].prioridade == 'v' || cadastro[i].prioridade == 'V'){
						printf("%d" , i);
						printf(" - ");
						printf("%s" , cadastro[i].nome);
						printf(" - ");
						printf("%s" , cadastro[i].sobrenome);
						printf(" \n ");
					}
				}
			}
			break;

      case 'A':
      case 'a':
        printf(AMARELO"--------- Prioridade Amarela ---------- \n" RESET);
				if(tamfilaAmarela == 0){
					printf(VERMELHO"Erro ---> \n" RESET);
					printf("A fila está vazia! :( \n");
					printf("-------------------------------------- \n");
				}else{
				for(int i=0; i < tamfilaAmarela; i++){
						if(cadastro[i].prioridade == 'a' || cadastro[i].prioridade == 'A'){
						printf("%d" , i);
						printf(" - ");
						printf("%s" , cadastro[i].nome);
						printf(" - ");
						printf("%s" , cadastro[i].sobrenome);
						printf(" \n ");
					}
					
				}
			}
      break;
			
      default:
				printf(VERMELHO"--------- Erro---------- \n" RESET);
				printf("Nosso sistema só aceita A ou V como níveis de prioridade! \n");
				printf("-------------------------------------- \n" );
		}
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

	
}

void Menu(){
  int i;

	do{
		printf(VERDE"--------------------- Menu ---------------- \n" RESET);
		printf("1 - Cadastrar Paciente \n");
		printf("2 - Remover Paciente \n");
		printf("3 - Pesquisar Paciente por nivel de urgência \n");
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