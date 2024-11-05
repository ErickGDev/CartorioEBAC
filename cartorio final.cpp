#include <stdio.h>      
#include <stdlib.h>     
#include <locale.h>     
#include <string.h>     

// Fun��o para registrar um usu�rio
void registro() 
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    char continuar;

    do {
        printf("Digite o CPF: ");
        scanf("%s", cpf);

        strcpy(arquivo, cpf); // Copiar CPF para o nome do arquivo
        FILE *file = fopen(arquivo, "w"); // Criar o arquivo

        if (file == NULL) {
            perror("Erro ao criar o arquivo");
            return;
        }

        fprintf(file, "%s, ", cpf);
        fclose(file);

        printf("Digite o nome: ");
        scanf("%s", nome);

        file = fopen(arquivo, "a");
        fprintf(file, "%s ", nome);
        fclose(file);

        printf("Digite o sobrenome: ");
        scanf("%s", sobrenome);

        file = fopen(arquivo, "a");
        fprintf(file, "%s, ", sobrenome);
        fclose(file);

        printf("Digite seu cargo: ");
        scanf("%s", cargo);

        file = fopen(arquivo, "a");
        fprintf(file, "%s", cargo);
        fclose(file);

        printf("Registro conclu�do com sucesso.\n");

        // Pergunta se o usu�rio quer continuar registrando nomes
        printf("Deseja registrar outro nome? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    printf("Retornando ao menu principal...\n");
}

// Fun��o para consultar um usu�rio
void consultar() 
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];
    char continuar;

    do {
        printf("Digite o CPF a ser consultado: ");
        scanf("%s", cpf);

        FILE *file = fopen(cpf, "r");

        if (file == NULL) {
            printf("Arquivo n�o encontrado\n");
        } else {
            printf("\nEssas s�o as informa��es:\n");
            while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
                printf("%s\n", conteudo);
            }
            fclose(file);
        }

        // Pergunta se o usu�rio quer continuar consultando
        printf("Deseja consultar outro CPF? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    printf("Retornando ao menu principal...\n");
}

// Fun��o para deletar um usu�rio
void deletar() 
{
    char cpf[40];
    char continuar;

    do {
        printf("Digite o CPF do usu�rio a ser deletado: ");
        scanf("%s", cpf);

        FILE *file = fopen(cpf, "r");
        
        if (file == NULL) {
            printf("O usu�rio n�o se encontra no sistema!\n");
        } else {
            fclose(file);
            if (remove(cpf) == 0) {
                printf("Usu�rio deletado com sucesso!\n");
            } else {
                perror("Erro ao deletar o usu�rio");
            }
        }

        // Pergunta se o usu�rio quer continuar deletando nomes
        printf("Deseja deletar outro nome? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    printf("Retornando ao menu principal...\n");
}

// Fun��o principal
int main() 
{
    setlocale(LC_ALL, "Portuguese");

    int opcao = 0;
    char senha[20];
    int tentativas = 3;

    printf("### Cart�rio ###\n\n");

    while (tentativas > 0) {
        printf("Login de administrador!\nDigite sua senha: ");
        scanf("%s", senha);

        if (strcmp(senha, "admin") == 0) {
            printf("Login bem-sucedido!\n");
            break;
        } else {
            tentativas--;
            printf("Senha incorreta! Tentativas restantes: %d\n", tentativas);
            if (tentativas == 0) {
                printf("Acesso bloqueado!\n");
                return 1;
            }
        }
    }

    // Menu principal
    while (1) {
        system("cls"); // Limpar a tela
        printf("\t====================\n");
        printf("\t     Cart�rio\n");
        printf("\t====================\n\n");
        printf("    Escolha uma op��o do menu:\n\n");
        printf("\t1 - Registro de nomes \n");
        printf("\t2 - Consultar nomes \n");
        printf("\t3 - Deletar nomes \n");
        printf("\t0 - Sair\n\n");
        printf("Op��o: ");
        scanf("%d", &opcao);

        system("cls"); // Limpar a tela

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
            case 0:
                printf("Saindo...\n");
                return 0; // Finaliza o programa
            default:
                printf("Essa op��o n�o � v�lida\n");
                break;
        }
        system("pause");
    }
}

