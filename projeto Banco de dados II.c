#include <stdio.h>      // Biblioteca de comunicação com o usuário
#include <stdlib.h>     // Biblioteca de alocação de espaço na memória
#include <locale.h>     // Biblioteca de alocação de texto por região
#include <string.h>     // Biblioteca para manipulação de strings
#include <ctype.h>


// Função para registrar um usuário
int registro() 

{

    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); // Copiar CPF para o nome do arquivo
    FILE *file = fopen(arquivo, "w"); // Criar o arquivo

    if (file == NULL) 

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

    printf("Registro concluído com sucesso.\n");
}

// Função para consultar um usuário
int consultar() 
{
	int validarCPF(const char *cpf) {
    // Verifica se o CPF tem 11 caracteres numéricos
    if (strlen(cpf) != 11) return 0;
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) return 0;
    }
    return 1;
}

int main()
 {
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado (apenas números, 11 dígitos): ");
    scanf("%s", cpf);

    if (!validarCPF(cpf)) {
        printf("CPF inválido. Certifique-se de que o CPF possui 11 dígitos numéricos.\n");
        return 1;
    }

    FILE *file = fopen(cpf, "r");

    if (file == NULL) {
        printf("Arquivo não encontrado para o CPF fornecido.\n");
        return 1;
    }

    printf("\nEssas são as informações:\n");
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        printf("%s", conteudo);  // A quebra de linha já está incluída em 'conteudo'
    }
    fclose(file);

    return 0;
    
}

// Função para deletar um usuário
int deletar() {
    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("O usuário foi deletado\n");
    } else {
        perror("Erro ao deletar o usuário");
    }
}

// Função principal
int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao = 0;

    while (1) {
        system("cls"); // Limpar a tela

        printf("\t====================\n");
        printf("\t     Cartório\n");
        printf("\t====================\n\n");
        printf("    Escolha uma opção do menu:\n\n");
        printf("\t1 - Registro de nomes \n");
        printf("\t2 - Consultar nomes \n");
        printf("\t3 - Deletar nomes \n");
        printf("\t0 - Sair\n\n");
        printf("Opção: ");

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
                printf("Essa opção não é válida\n");
                break;
        }
        system("pause");
    }
}
