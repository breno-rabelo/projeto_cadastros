#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h> 
#include <string.h>

int registro() { 
    char arquivo[50]; 
    char cpf[40];  
    char nome[40];
    char sobrenome[40];
    char cargo[40];  

    printf("\nDigite o CPF a ser cadastrado:\n"); 
    scanf("%s", cpf); 

    snprintf(arquivo, sizeof(arquivo), "%s.txt", cpf); // Adiciona extensão para evitar conflitos

    FILE *file = fopen(arquivo, "w"); 
    if (file == NULL) {
        printf("Erro ao criar arquivo.\n");
        return 1;
    }
    
    fprintf(file, "%s,", cpf);

    printf("\nDigite o nome a ser cadastrado:\n");
    scanf("%s", nome);
    fprintf(file, "%s,", nome);

    printf("\nDigite o sobrenome a ser cadastrado:\n");
    scanf("%s", sobrenome);
    fprintf(file, "%s,", sobrenome);

    printf("\nDigite o cargo a ser cadastrado:\n");
    scanf("%s", cargo);
    fprintf(file, "%s", cargo);

    fclose(file);
    printf("\nCadastro realizado com sucesso!\n");
    system("pause");
    return 0;
}

int consultar() {
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char arquivo[50];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    snprintf(arquivo, sizeof(arquivo), "%s.txt", cpf);

    FILE *file = fopen(arquivo, "r");

    if (file == NULL) {
        printf("Usuário não encontrado.\n");
        system("pause");
        return 1;
    }

    printf("Essas são as informações do usuário:\n");
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        printf("%s\n", conteudo);
    }

    fclose(file);
    system("pause");
    return 0;
}

int deletar() {
    char cpf[40];
    char arquivo[50];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);
    
    snprintf(arquivo, sizeof(arquivo), "%s.txt", cpf);

    if (remove(arquivo) == 0) {
        printf("Usuário removido com sucesso!\n");
    } else {
        printf("Usuário não encontrado no sistema.\n");
    }

    system("pause");
    return 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese"); 
    int opcao = 0;

    while (1) {
        system("cls");

        printf("Cartório\n\n");
        printf("Escolha a opção desejada:\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair\n");
        printf("Escolha: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registro();
                break;
            case 2:
                consultar();
                break;
            case 3:
                deletar();
                break;
            case 4:
                printf("Encerrando o sistema...\n");
                return 0;
            default:
                printf("\nOpção não encontrada\n\n");
                system("pause");
                break;
        }
    }
}
