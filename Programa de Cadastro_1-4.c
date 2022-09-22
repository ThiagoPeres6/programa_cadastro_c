//PROGRAMAS DE CADASTRO DE CLIENTES

//Bibliotecas e Constantes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define SIZE 200

//Matrizes, Vetores e Variáveis Globais
char nome[SIZE][50];
char email[SIZE][50];
int cpf[SIZE];
int op;
int qnt_cadastros = 0;

//Declaração dos Protótipos das outras Funções
void cadastro();
void pesquisa();
void lista();

int main(void){
	
	do{
		system("cls");
		printf("\n------------- MENU -------------\n\n1 - Cadastrar\n2 - Listar Todos\n3 - Pesquisar\n4 - Sair\n\nDigite uma opcao: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				cadastro();
				break;
			case 2:
				lista();
				break;
			case 3:
				pesquisa();
				break;
			case 4:
				system("exit");
				break;
			default:
				printf("Opcao Invalida");
				getchar();
				Sleep(1500);
				break;
		}
	}while(op != 4);
	
	return 0;
}

void cadastro(){
	
	static int linha = 0;
	
	do{
		printf("\nDigite o nome: ");
		scanf(" %49[^\n]", nome[linha]);
		printf("\nDigite o email: ");
		scanf(" %49s", email[linha]);
		printf("\nDigite o cpf: ");
		scanf("%d", &cpf[linha]);
		printf("\nDigite 1 para continuar cadastrando ou outro valor para voltar ao menu ");
		scanf("%d", &op);
		linha++;
		qnt_cadastros++;
	}while(op == 1);
}

void pesquisa(){
	
	int cpf_pesquisa;
	char email_pesquisa[50];
	int i;
	
	do{
		printf("\nDigite 1 para pesquisar por cpf ou 2 para pesquisar por email ");
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("\nDigite o cpf: ");
				scanf("%d", &cpf_pesquisa);
				for(i=0; i<SIZE; i++)
				{
					if(cpf[i] == cpf_pesquisa)
						printf("\nNome: %s\nEmail: %s\nCPF: %d", nome[i], email[i], cpf[i]);
				}
				break;
			case 2:
				printf("\nDigite o email: ");
				scanf("%s", email_pesquisa);
				for(i=0; i<SIZE; i++)
				{
					if(strcmp(email[i], email_pesquisa) == 0)
						printf("\nNome: %s\nEmail: %s\nCPF: %d", nome[i], email[i], cpf[i]);
				}
				break;
			default:
				printf("\nOpcao invalida\n");
				break;
		}
		printf("\n\nDigite 1 para continuar pesquisando ou outro valor para voltar ao menu ");
		scanf("%d", &op);
	}while(op == 1);
}

void lista(){
	
	int i;
	
	for(i=0; i<qnt_cadastros; i++){
		printf("\nNome: %s\nEmail: %s\nCPF: %d\n\n", nome[i], email[i], cpf[i]);
	}
	system("pause");
}
