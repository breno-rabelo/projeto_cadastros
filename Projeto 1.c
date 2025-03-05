#include <stdio.h> // comunica��o com usu�rio
#include <stdlib.h> // aloca��o de mem�ria
#include <locale.h> // textos por regi�o
#include <string.h> // gerenciar strings

int registro(){ // cadastro dos usu�rios no sistema

	
	char arquivo[40]; 
	char cpf[40];  
	char nome[40];
	char sobrenome [40];
	char cargo[40];  // cria��o de vari�veis
	
	printf ("\n\nDigite o CPF a ser cadastrado:\n"); 
	scanf ("%s", cpf);  // receber a informa��o do usu�rio e armazena em uma string

	strcpy (arquivo, cpf); // respons�vel por copiar os valores das strings
	
	FILE * file; //FILE � uma fun��o do sistema para criar um arquivo
	file = fopen(arquivo,"w"); //cria o arquivo, o w � para escrever no arquivo
	fprintf (file,cpf); // salva no arquivo a vari�vel cpf
	fclose(file); // fecha a pasta
	
	file = fopen (arquivo, "a"); // atualiza o file
	fprintf (file, ","); // separar as informa��es com ,
	fclose (file); // fecha a pasta
	
	printf ("\n\nDigite o nome a ser cadastrado\n");
	scanf ("%s",nome);
	
	file = fopen (arquivo, "a");
	fprintf (file, nome);
	fclose(file);
	
	file = fopen (arquivo, "a"); // atualiza o file
	fprintf (file, ","); // separar as informa��es com ,
	fclose (file);
	
	printf ("\n\nDigite o sobrenome a ser cadastrado:\n");
	scanf ("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a"); // atualiza o file
	fprintf (file, ","); // separar as informa��es com ,
	fclose (file);
	
	printf ("\n\nDigite o cargo a ser cadastrado:\n");
	scanf ("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	system ("pause");
	
}

int consultar(){
	
	setlocale (LC_ALL,"Portuguese"); // Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf ("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	FILE * file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("N�o foi poss�vel abrir o arquivo.\n");
	}
	
	while (fgets(conteudo, 200, file)!=NULL) 
	{
		printf ("Essas s�o as informa��es do usu�rio:\n");
		printf ("%s", conteudo);
		printf("\n\n");
	}
	 
	system ("pause");
}

int deletar(){
	
	char cpf[40];
	
	printf ("Digite o CPF a ser deletado: ");
	scanf ("%s",cpf);
	
	remove(cpf);
	
	FILE * file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf ("Usu�rio n�o encontrado no sistema.\n");
		system ("pause");
	}
}

int main () 
{
	int opcao = 0; // variaveis
    int laco=1;
    
    for(laco=1;laco=1;){
        
        setlocale (LC_ALL,"Portuguese"); // Linguagem
		system ("cls");  // limpa a tela
		
        printf ("Cart�rio\n\n"); //Inicio do menu
        printf ("Escolha a op��o desejada:\n\n");
        printf ("\t1 Registar nomes\n\n");
        printf ("\t2 Consultar nomes\n\n");
        printf ("\t3 Deletar nomes\n\n");
        printf ("Escolha: ");// Fim do menu

        scanf ("%d", &opcao); // Armazenar informacoes
		        
        switch (opcao) // chamada das fun��es
        {
        	case 1:
        		registro();
        		break;
        	case 2:
        		consultar();
        		break;
        	case 3:
        		deletar();
        		break;
        	default:
        		printf ("\nOp��o n�o encontrada\n\n");
        		system ("pause");
        		break;
		}
	}
}
