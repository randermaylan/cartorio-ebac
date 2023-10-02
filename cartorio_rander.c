#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registrar() //Fun��o respons�vel pelo cadastro de usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; 
	char opcao; 
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser cadastrado: \n\n\t"); //Coletando informa��es do usu�rio
	scanf("%s",cpf); //Salva a string cpf. "%s" refere-se � string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo. "w" significa escrever (write)
	fprintf(file,"\tCPF: "); //Mensagem ao usu�rio
	fprintf(file,cpf); //Salva o valor da vari�vel na string cpf
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre um arquivo existente
	fprintf(file,"\n\tNOME: "); //Mensagem ao usu�rio
	fclose(file); //Fecha o arquivo
	
	printf("\nDigite o nome do usu�rio a ser cadastrado: \n\n\t"); //Coletando informa��es do usu�rio
	scanf("%s",nome); //Salva a string nome
	
	file = fopen(arquivo, "a"); //Abre o arquivo e adiciona as informa��es. "a" significa "append"
	fprintf(file,nome); //Salva o valor da vari�vel na string nome
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e adiciona as informa��es
	fprintf(file,"\n\tSOBRENOME: "); //Mensagem ao usu�rio
	fclose(file); //Fecha o arquivo
	
	printf("\nDigite o sobrenome do usu�rio a ser cadastrado: \n\n\t"); //Coletando informa��es do usu�rio
	scanf("%s",sobrenome); //Salva a string sobrenome
	
	file = fopen(arquivo, "a"); //Abre o arquivo e adiciona as informa��es
	fprintf(file,sobrenome); //Salva o valor da vari�vel na string sobrenome
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e adiciona as informa��es
	fprintf(file,"\n\tCARGO: "); //Mensagem ao usu�rio
	fclose(file); //Fecha o arquivo
	
	printf("\nDigite o cargo do usu�rio a ser cadastrado: \n\n\t"); //Coletando informa��es do usu�rio
	scanf("%s",cargo); //Salva a string cargo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e adiciona as informa��es
	fprintf(file,cargo); //Salva o valor da vari�vel na string cargo
	fprintf(file,"\n\n"); //Espa�o-linha para formata��o est�tica
	fclose(file); //Fecha o arquivo
	
	printf("\n"); //Espa�o-linha
	system("pause"); //Pausa a tela
	
	system("cls"); //Limpa a tela
	printf("Deseja cadastrar outro usu�rio? S ou N? \n\n"); //Coletando informa��es do usu�rio
	scanf(" %c", &opcao); //Salva a resposta do usu�rio na vari�vel op��o. "%c" refere-se � caracter
	printf("\n"); //Espa�o-linha
	system("cls"); //Limpa a tela
	
	if (opcao == 'S' || opcao == 's') //Condicional que determina a a��o a ser tomada com base na op��o do usu�rio
		return registrar(); //Retorna ao in�cio da fun��o
	else //Condicional que determina a a��o a ser tomada caso a op��o do usu�rio seja diferente da determinada em IF
		return 0; //Retorna � fun��o principal
	
} //Fim da fun��o registrar

int consultar() //Fun��o respons�vel pela consulta de usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200]; 
	char opcao;
	//Final da cria��o de vari�veis/string 
	
	printf("Digite o CPF do usu�rio a ser consultado: \n\n\t"); //Coletando informa��es do usu�rio
	scanf("%s",cpf); //Salva a string cpf. "%s" refere-se � string
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //L� um arquivo existente. "r" significa "read"
	
	if(file == NULL) //Determina a��o condicional
	{
		printf("\nN�o foi poss�vel abrir o arquivo. Usu�rio n�o localizado.\n\n"); //Mensagem ao usu�rio
		
	} //Final da a��o condicional
	
	if(file != NULL) //Determina a��o condicional
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n\n"); //Mensagem ao usu�rio
	} //Final da a��o condicional
	
	while(fgets(conteudo,200,file) != NULL) //Determina a��o condicional
	{
		printf("%s",conteudo); //Exibe ao usu�rio as informa��es encontradas
	} //Final da a��o condicional
	
	printf("Deseja consultar outro usu�rio? S ou N?\n\n"); //Coletando informa��es do usu�rio
	scanf(" %c", &opcao); //Salva a resposta do usu�rio na vari�vel op��o
	printf("\n"); //Espa�o-linha
	system("cls"); //Limpa a tela
	
	if (opcao=='S'||opcao=='s') //Determina a��o condicional
		return consultar(); //Retorna ao in�cio da fun��o
	else 
		return 0; //Final da a��o condicional
	
	system("pause"); //Pausa a tela
	fclose(file); //Fecha o arquivo
	
} //Fim da fun��o consultar

int deletar() //Fun��o respons�vel pela exclus�o de usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	char opcao;
	//Final da cria��o de vari�veis/string 
	
	printf("Digite o CPF do usu�rio a ser deletado: \n\n\t"); //Coletando informa��es do usu�rio
	scanf("%s",cpf); //Salva a string cpf. "%s" refere-se � string
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //L� um arquivo existente
		
	if(file == NULL) //Determina a��o condicional
	{
		printf("\nO usu�rio n�o p�de ser localizado.\n\n"); //Mensagem ao usu�rio
		system("pause"); //Pausa a tela
		return 0;
	} //Final da a��o condicional
	
	else //Determina a��o condicional
		while(fgets(conteudo,200,file) != NULL) //Determina a��o condicional
		{
			printf("%s",conteudo); //Exibe ao usu�rio as informa��es encontradas
		} //Final da a��o condicional
		printf("Tem certeza que deseja deletar este usu�rio? S ou N? \n\n"); //Coletando informa��es do usu�rio
		scanf(" %c",&opcao); //Salva a resposta do usu�rio na vari�vel op��o
		
		switch (opcao) //Determina a��o condicional
		{
			//In�cio do case
			case 'S': //Compara resposta do usu�rio
			case 's': //Compara resposta do usu�rio
			fclose(file); //Fecha o arquivo
			remove(cpf); //Deleta o arquivo
			printf("\nO usu�rio foi deletado com sucesso.\n\n\n"); //Mensagem ao usu�rio
			printf("Deseja deletar outro usu�rio? S ou N?\n\n"); //Coletando informa��es do usu�rio
			scanf(" %c", &opcao); //Salva a resposta do usu�rio na vari�vel op��o
			printf("\n"); //Espa�o-linha
			system("cls"); //Limpa a tela
			
			if (opcao=='S'||opcao=='s') //Determina a��o condicional
				return deletar(); //Retorna ao in�cio da fun��o
			else //Determina a��o condicional
				return 0; //Retorna � fun��o principal
			system("pause"); //Pausa a tela
			break; 
			//Final do case
			
			//In�cio do case
			case 'N': //Compara resposta do usu�rio
			case 'n': //Compara resposta do usu�rio
			return deletar(); //Retorna ao in�cio da fun��o
			break;
			//Final do case
			
			//In�cio do case
			default: //Fun��o padr�o quando o comando do usu�rio n�o se encontra nas op��es
			printf("Esta op��o n�o est� dispon�vel \n"); //Mensagem ao usu�rio
			system("pause"); //Pausa a tela
			break;
			//Final do case
		}//Final da a��o condicional
		
} //Fim da fun��o deletar

int main() //Fun��o principal do software
{
	int opcao=0; //Definindo vari�veis
	int laco=1; //Definindo vari�veis em loop
	
	for (laco=1;laco=1;) //Determina a��o a ser seguida para a vari�vel indicada
	{
		
		system("cls"); //Limpa a tela	
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		 //In�cio do menu
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); 
		//Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio na string
	
		system("cls"); //Limpa a tela
		
		//In�cio da sele��o do menu
		switch(opcao)
		{
			case 1: //In�cio da op��o
			registrar(); //Chamada de fun��es
			break; //Fim da op��o
			
			case 2: //In�cio da op��o
			consultar(); //Chamada de fun��es
			break; //Fim da op��o
			
			case 3: //In�cio da op��o
			deletar(); //Chamada de fun��es
			break; //Fim da op��o
			
			default: //Fun��o padr�o quando o comando do usu�rio n�o se encontra nas op��es
			printf("Essa op��o n�o est� dispon�vel\n"); //Mensagem ao usu�rio
			system("pause"); //Pausa a tela
			break; //Fim do comando
		} //Fim da sele��o do menu
	}//Fim do la�o
	
} //Fim da fun��o principal
