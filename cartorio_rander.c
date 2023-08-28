#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registrar() //Função responsável pelo cadastro de usuários no sistema
{
	char arquivo[40]; //Início da criação de variáveis/string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //Final da criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser cadastrado: \n\n\t"); //Coletando informações do usuário
	scanf("%s",cpf); //Salva a string cpf. "%s" refere-se à string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo. "w" significa escrever (write)
	fprintf(file,"\tCPF: "); //Mensagem ao usuário
	fprintf(file,cpf); //Salva o valor da variável na string cpf
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre um arquivo existente
	fprintf(file,"\n\tNOME: "); //Mensagem ao usuário
	fclose(file); //Fecha o arquivo
	
	printf("\nDigite o nome do usuário a ser cadastrado: \n\n\t"); //Coletando informações do usuário
	scanf("%s",nome); //Salva a string nome
	
	file = fopen(arquivo, "a"); //Abre o arquivo e adiciona as informações. "a" significa "append"
	fprintf(file,nome); //Salva o valor da variável na string nome
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e adiciona as informações
	fprintf(file,"\n\tSOBRENOME: "); //Mensagem ao usuário
	fclose(file); //Fecha o arquivo
	
	printf("\nDigite o sobrenome do usuário a ser cadastrado: \n\n\t"); //Coletando informações do usuário
	scanf("%s",sobrenome); //Salva a string sobrenome
	
	file = fopen(arquivo, "a"); //Abre o arquivo e adiciona as informações
	fprintf(file,sobrenome); //Salva o valor da variável na string sobrenome
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e adiciona as informações
	fprintf(file,"\n\tCARGO: "); //Mensagem ao usuário
	fclose(file); //Fecha o arquivo
	
	printf("\nDigite o cargo do usuário a ser cadastrado: \n\n\t"); //Coletando informações do usuário
	scanf("%s",cargo); //Salva a string cargo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e adiciona as informações
	fprintf(file,cargo); //Salva o valor da variável na string cargo
	fprintf(file,"\n\n"); //Espaço-linha para formatação estética
	fclose(file); //Fecha o arquivo
	
	printf("\n"); //Espaço-linha
	
	system("pause"); //Pausa a tela
	
} //Fim da função registrar

int consultar() //Função responsável pela consulta de usuários no sistema
{
	char cpf[40]; //Início da criação de variáveis/string
	char conteudo[200]; //Final da criação de variáveis/string 
	
	printf("Digite o CPF do usuário a ser consultado: \n\n\t"); //Coletando informações do usuário
	scanf("%s",cpf); //Salva a string cpf. "%s" refere-se à string
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Lê um arquivo existente. "r" significa "read"
	
	if(file == NULL) //Determina ação condicional
	{
		printf("\nNão foi possível abrir o arquivo. Usuário não localizado.\n\n"); //Mensagem ao usuário
	} //Fim do comando
	
	if(file != NULL) //Determina ação condicional
	{
		printf("\nEssas são as informações do usuário: \n\n"); //Mensagem ao usuário
	} //Fim do comando
	
	while(fgets(conteudo,200,file) != NULL) //Determina ação condicional
	{
		printf("%s",conteudo); //Exibe ao usuário as informações encontradas
	} //Fim do comando
	
	system("pause"); //Pausa a tela
	fclose(file); //Fecha o arquivo
	
} //Fim da função consultar

int deletar() //Função responsável pela exclusão de usuários no sistema
{
	char cpf[40]; //Criação da variável/string
	
	printf("Digite o CPF do usuário a ser deletado: \n\n\t"); //Coletando informações do usuário
	scanf("%s",cpf); //Salva a string cpf. "%s" refere-se à string
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Lê um arquivo existente.
		
	if(file == NULL) //Determina ação condicional
	{
		printf("\nO usuário não pôde ser localizado.\n\n"); //Mensagem ao usuário
		system("pause"); //Pausa a tela
		return 0;
	} //Fim do comando
	
	else //Determina ação condicional
		fclose(file); //Fecha o arquivo
		remove(cpf); //Deleta o arquivo
		printf("\nO usuário foi deletado com sucesso.\n\n"); //Mensagem ao usuário
		system("pause"); //Pausa a tela
		
} //Fim da função deletar

int main() //Função principal do software
{
	
	int opcao=0; //Definindo variáveis
	int laco=1; //Definindo variáveis em loop
	
	for (laco=1;laco=1;) //Determina ação a ser seguida para a variável indicada
	{
		
		system("cls"); //Limpa a tela	
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário na string
	
		system("cls"); //Limpa a tela
		
		switch(opcao) //Início da seleção do menu
		{
			case 1: //Início da opção
			registrar(); //Chamada de funções
			break; //Fim da opção
			
			case 2: //Início da opção
			consultar(); //Chamada de funções
			break; //Fim da opção
			
			case 3: //Início da opção
			deletar(); //Chamada de funções
			break; //Fim da opção
			
			default: //Função padrão quando o comando do usuário não se encontra nas opções
			printf("Essa opção não está disponível\n"); //Mensagem ao usuário
			system("pause"); //Pausa a tela
			break; //Fim do comando
		} //Fim da seleção do menu
	}
	
	
	
	
} //Fim da função principal
