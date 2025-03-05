#include <stdio.h> // comunicação com usuário
#include <stdlib.h> // alocação de memória
#include <locale.h> // textos por região
#include <string.h> // gerenciar strings

int registro(){ // cadastro dos usuários no sistema

	
	char arquivo[40]; 
	char cpf[40];  
	char nome[40];
	char sobrenome [40];
	char cargo[40];  // criação de variáveis
	
	printf ("\n\nDigite o CPF a ser cadastrado:\n"); 
	scanf ("%s", cpf);  // receber a informação do usuário e armazena em uma string

	strcpy (arquivo, cpf); // responsável por copiar os valores das strings
	
	FILE * file; //FILE é uma função do sistema para criar um arquivo
	file = fopen(arquivo,"w"); //cria o arquivo, o w é para escrever no arquivo
	fprintf (file,cpf); // salva no arquivo a variável cpf
	fclose(file); // fecha a pasta
	
	file = fopen (arquivo, "a"); // atualiza o file
	fprintf (file, ","); // separar as informações com ,
	fclose (file); // fecha a pasta
	
	printf ("\n\nDigite o nome a ser cadastrado\n");
	scanf ("%s",nome);
	
	file = fopen (arquivo, "a");
	fprintf (file, nome);
	fclose(file);
	
	file = fopen (arquivo, "a"); // atualiza o file
	fprintf (file, ","); // separar as informações com ,
	fclose (file);
	
	printf ("\n\nDigite o sobrenome a ser cadastrado:\n");
	scanf ("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a"); // atualiza o file
	fprintf (file, ","); // separar as informações com ,
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
		printf("Não foi possível abrir o arquivo.\n");
	}
	
	while (fgets(conteudo, 200, file)!=NULL) 
	{
		printf ("Essas são as informações do usuário:\n");
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
		printf ("Usuário não encontrado no sistema.\n");
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
		
        printf ("Cartório\n\n"); //Inicio do menu
        printf ("Escolha a opção desejada:\n\n");
        printf ("\t1 Registar nomes\n\n");
        printf ("\t2 Consultar nomes\n\n");
        printf ("\t3 Deletar nomes\n\n");
        printf ("Escolha: ");// Fim do menu

        scanf ("%d", &opcao); // Armazenar informacoes
		        
        switch (opcao) // chamada das funções
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
        		printf ("\nOpção não encontrada\n\n");
        		system ("pause");
        		break;
		}
	}
}
