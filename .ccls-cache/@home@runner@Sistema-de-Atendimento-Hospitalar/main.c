#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <string.h>

int menucontrole = 1;
int tam;
int ini,fim;
int tamfilaAmarela = 0;
int tamfilaVerde = 0;
int error;
int i=0;
int prioridade;

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

void Error(){ //mensagem de erro se a opção estiver errada
	printf(VERMELHO"---------- Erro ❗ ---------- \n");
  printf("❌ Opção inválida! 😐 \nTente novamente! \n");
	printf("---------------------------- \n" RESET);
}
void FilaVazia(){
	printf(VERMELHO"--------- Erro ❗ ---------- \n" RESET);
	printf(" Fila Vazia! , nenhum paciente foi encontrado 😢 \n");
	printf("-------------------------------------\n");
}

void Cadastrar(){
	int menucontrole = 0;
	char escolha = ' ';
	printf("--------- Cadastro ---------- \n");
	printf("Cadastrar novo Paciente :\n");
	printf("Qual o nome do Paciente ?\n");
	printf("Digite o nome e sobrenome: ");
	scanf(" %s%s", cadastro[ini].nome , cadastro[ini].sobrenome);
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
				printf(VERDE"-------------------------------------- \n \n \n" RESET);
				printf(VERDE"--------- Sucesso ! ---------- \n");
				printf(VERDE"✔ Conta criada com sucesso! \n");
				printf(VERDE"-------------------------------------- \n" RESET);
				cadastro[ini].prioridade = 'V';
				cadastro[ini].posicaoPrioridadeVerde++;
				ini++;
				break;
      case 'A':
      	case 'a':
        printf(AMARELO"--------- Prioridade Amarela ---------- \n" RESET);
				printf(AMARELO"Prioridade definida como Amarela! \n" RESET);
				printf(AMARELO"-------------------------------------- \n \n \n" RESET);
				printf(VERDE"--------- Sucesso ! ---------- \n");
				printf(VERDE"✔ Conta criada com sucesso! \n");
				printf(VERDE"-------------------------------------- \n" RESET);
				cadastro[ini].prioridade = 'A';
				cadastro[ini].posicaoPrioridadeAmarela++;
				ini++;
      break;
      default:
				Error();
		}tam = tam +1; //switch
}//VOID CADASTRAR

void Remover(){
  menucontrole = 0;
  char escolha = ' ';
	char nome = ' ';
	printf("--------- Remover Paciente da Fila ---------- \n");

	if(tamfilaAmarela != 0){
		if(prioridade < 3){
				tamfilaAmarela--; 
				prioridade++;
		}
	}else if (tamfilaVerde != 0){
		tamfilaVerde--;
		
		if(prioridade >=7){
			prioridade=0;
		}
	}
    if(tam == 0){
		 FilaVazia();
		}else{
			printf(VERDE"--------- ✔ Paciente removido com sucesso ! :)---------- \n");
			ini++;
		}
	menucontrole =1;
}//VOID REMOVER

void Pesquisar(){
  menucontrole = 0;
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

				for(i = ini-1; i < fim; i++){
				if(cadastro[i].prioridade == 'v' || cadastro[i].prioridade == 'V'){
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
							printf("%d", cadastro[ini].posicaoGeral+1); 
							printf(" \n ");
							printf("Posição por prioridade: ");
							printf("%d", cadastro[ini].posicaoPrioridadeVerde+1);
							printf(" \n ");
							printf(VERDE"-------------------------------------- \n" RESET);
				}else{error=1;}
			}//for
				if(error == 1){ FilaVazia(); }break;

      case 'A':
      	case 'a':
        for(i = ini-1; i < fim; i++){
				if(cadastro[i].prioridade == 'a' || cadastro[i].prioridade == 'A'){
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
				printf("%d", cadastro[ini].posicaoGeral +1); // criar um for pra mudar o valor do vetor
				printf(" \n ");
				printf("Posição por prioridade: ");
				printf("%d", cadastro[ini].posicaoPrioridadeAmarela+1); // criar um for pra mudar o valor do vetor
				printf(" \n ");
				printf(AMARELO"-------------------------------------- \n" RESET);
					}//IF
        else{
					error=1;}
			}//FOR
				if(error ==1){
 FilaVazia(); }beak;	
      default:Error();}//SWITCH
		menucontrole =1;
}//VOID PESQUISAR
	
void VfilaCompleta(){
	int i = ini;
	int indice=0;
  menucontrole = 0;
	printf(AZUL"--------- Visualizar Fila Completa ---------- \n" RESET);
	if(tam == 0){ FilaVazia(); }else{
			do{ printf(" %d" , indice+1); printf(" - ");
					printf("Nome: "); printf("%s" , cadastro[i].nome);printf(" ");
					printf("%s" , cadastro[i].sobrenome);printf(" ");
					printf("Prioridade: ");printf("%c" , cadastro[i].prioridade);printf(" ");
					i++; indice++;
				}while(i<50);
		} menucontrole =1;}//void VfilaCompleta

void VfilaTipoUrgencia(){
  menucontrole = 0;
	int i = tam;
	int indice=0;
	printf(AZUL"--------- Visualizar Tipo de Urgência ---------- \n" RESET);
	char escolha = ' ';
	char nome = ' ';
	printf("Qual a urgência do paciente ?\n");
	printf(VERDE"V - Verde");
 rintf(RESET" | ");
 rintf(AMARELO"A - Amarelo \n" RESET);
	printf("Digite a urgência: ");
 canf(" %c", &escolha);
	 	switch(escolha){
			case 'V':
      case 'v':
        printf(VERDE"--------- Prioridade Verde ---------- \n" RESET);
        if(tam == 0){ FilaVazia(); }else{
					for(int f=0; f<50; f++){
					if(cadastro[i].prioridade == 'v' || cadastro[i].prioridade == 'V'){
						printf("%d" , indice+1); printf(" - ");
						printf("%s" , cadastro[i].nome); printf(" - ");
						printf("%s" , cadastro[i].sobrenome) ;printf("\n");
						indice++;
 


 reak;

			      case 'A':
      case 'a':
        printf(AMARELO"--------- Prioridade Amarela ---------- \n" RESET);
				if(tam == 0){ FilaVazia(); }else{
					for(int t=0; t<50;t++){
						if(cadastro[i].prioridade == 'a' || cadastro[i].prioridade == 'A'){
						printf("%d" , indice+1);
						printf(" - ");
						printf("%s" , cadastro[i].nome); 
						printf(" - ");
						printf("%s" , cadastro[i].sobrenome);
						printf("\n");
						indice++;
						}
					}
				}
					break;
			
      default:
				printf(VERMELHO"--------- Erro ❗---------- \n" RESET);
				printf(" ❌ Nosso sistema só aceita A ou V como níveis de prioridade! \n");
				printf("-------------------------------------- \n" );
		}//Switch
  menucontrole =1;
  }//void VfilaTipoUrgencia
	
void ConsultarFila(){
  int menucontrole = 0;
	printf(AZUL"--------- Consultar Fila ---------- \n" RESET);
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
}//Void ConsultarFila

void Menu(){
  int i;
	do{
		printf(AZUL"------------------ Menu ---------------- \n" RESET);
		printf("1 - Cadastrar Paciente \n");
		printf("2 - Remover Paciente \n");
		printf("3 - Pesquisar Paciente por nível de urgência \n");
		printf("4 - Visualizar fila completa \n");
 	 	printf("5 - Visualizar fila por tipo de urgência \n");
  	printf("6 - Consultar situação da fila \n");
		printf("Digite uma Opção: ");
		scanf("%d", &i);
		printf(AZUL"---------------------------------------- \n" RESET);
			switch(i){
      case 1:Cadastrar();break;
      case 2:Remover(); break;
      case 3:Pesquisar();break;
      case 4:VfilaCompleta();break;
      case 5:VfilaTipoUrgencia();break;
      case 6:ConsultarFila(); break;
      default: Error();}
	}while(menucontrole ==1); 
}//Void Menu

int main(void){ 
	setlocale (LC_ALL,"portuguese"); // define o idioma do projeto como portugês brasil
	Menu(); // chama o menu
}