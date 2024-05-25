#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct
{
    char Nome[100];
    char Telefone[20];
}Contato;

int cont;
Contato contato[3];


void criararquivo()
{
    setlocale(LC_ALL, "Portuguse");

    system("cls");

    FILE *arq = fopen("ListaDeContatos.txt", "w");

    if(arq)
    {
        fprintf(arq, "0");
        printf("Arquivo criado com sucesso\n");
        getchar();
        getchar();

        fclose(arq);
    }
    else
    {
        printf("Não foi possivel criar um arquivo\n");
        getchar();
        getchar();
    }
}

void lerDoArquivo()
{
    setlocale(LC_ALL, "Portuguse");

    FILE *arq = fopen("ListaDeContatos.txt", "r");
    Contato c;
    fscanf(arq, "%d\n", &cont);
    
    if(arq)
    {
        fscanf(arq, "%d\n", &cont);
        for(int i = 0; i < cont; i++)
        {
            fgets(c.Nome, 100, arq);
            fgets(c.Telefone, 100, arq);

            contato[i] = c;
        }
        fclose(arq);
    }
    else
    {
        printf("Não foi possivel abrir o arquivo");
    }
}


void cadastrarContato() 
{
    setlocale(LC_ALL, "Portuguse");

    system("cls");
    FILE *arq = fopen("ListaDeContatos.txt", "r+");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    if (fscanf(arq, "%d", &cont) != 1) {
        cont = 0;
    }

 
    cont++;

    rewind(arq);
    fprintf(arq, "%d\n", cont);
    fflush(arq); 

    
    fseek(arq, 0, SEEK_END);

    getchar();

    printf("Digite o nome: ");
    fgets(contato[cont - 1].Nome, 100, stdin);
    printf("Digite o contato: ");
    fgets(contato[cont - 1].Telefone, 20, stdin);


    size_t len = strlen(contato[cont - 1].Nome);
    if (len > 0 && contato[cont - 1].Nome[len - 1] == '\n') {
        contato[cont - 1].Nome[len - 1] = '\0';
    }
    len = strlen(contato[cont - 1].Telefone);
    if (len > 0 && contato[cont - 1].Telefone[len - 1] == '\n') {
        contato[cont - 1].Telefone[len - 1] = '\0';
    }

    fprintf(arq, "%s\n", contato[cont - 1].Nome);
    fprintf(arq, "%s\n", contato[cont - 1].Telefone);

    fclose(arq);
}


void excluirContato()
{
    setlocale(LC_ALL, "Portuguse");
    system("cls"); 
    lerDoArquivo();

    int op;

    for (int i = 0; i < cont; i++)
    {
        printf("%d. %s\n", i + 1, contato[i].Nome);
    }

    printf("Digite o número do contato que deseja excluir: ");
    scanf("%d", &op);

    if (op < 1 || op > cont)
    {
        printf("Opção inválida\n");
        return;
    }

    FILE *arq = fopen("ListaDeContatos.txt", "w");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    fprintf(arq, "%d\n", cont - 1);

    for (int i = 0; i < cont; i++)
    {
        if (i != op - 1)
        {
            fprintf(arq, "%s", contato[i].Nome);
            fprintf(arq, "%s", contato[i].Telefone);
        }
    }

    fclose(arq);

    printf("Contato excluído com sucesso!\n");

 
    while (getchar() != '\n');
    getchar();
}

void atualizarContato()
{
    setlocale(LC_ALL, "Portuguse");
    system("cls"); 
    lerDoArquivo();

    int op;

    for (int i = 0; i < cont; i++)
    {
        printf("%d. %s\n", i + 1, contato[i].Nome);
    }

    printf("Digite o número do contato que deseja atualizar: ");
    scanf("%d", &op);

    if (op < 1 || op > cont)
    {
        printf("Opção inválida\n");
        return;
    }

    FILE *arq = fopen("ListaDeContatos.txt", "w");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    fprintf(arq, "%d\n", cont);

    for (int i = 0; i < cont; i++)
    {
        if (i != op - 1)
        {
            fprintf(arq, "%s", contato[i].Nome);
            fprintf(arq, "%s", contato[i].Telefone);
        }
        else
        {
            printf("Digite um novo telefone: ");
            getchar();
            fgets(contato[i].Telefone, 20, stdin);
            fprintf(arq, "%s", contato[i].Nome);
            fprintf(arq, "%s", contato[i].Telefone);
        }
    }

    fclose(arq);

    printf("Contato atualiazado com sucesso!\n");
    getchar();
}

void exibirContato()
{
    setlocale(LC_ALL, "Portuguse");
    system("cls"); 
    lerDoArquivo();

    int op;

    for (int i = 0; i < cont; i++)
    {
        printf("%d. %s\n", i + 1, contato[i].Nome);
    }

    printf("Digite o número do contato que deseja consultar: ");
    scanf("%d", &op);

    if (op < 1 || op > cont)
    {
        printf("Opção inválida\n");
        return;
    }

    printf("%s", contato[op - 1].Nome);
    printf("%s", contato[op - 1].Telefone);
    getchar();
    getchar();
}