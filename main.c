#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int op;

    do
    {
        system("cls");
        printf("1 - Criar um arquivo\n2 - Cadastrar contato\n3 - Excluir Contato\n");
        printf("4 - Atualizar dados de contato\n5 - Consultar dados de um determinado contato\n0 - Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1: criararquivo();break;
            case 2: cadastrarContato();break;
            case 3: excluirContato();break;
            case 4: atualizarContato();break;
            case 5:exibirContato();break;
            case 0: system("cls");printf("Tchau!!!!");break;
            default: printf("Opção não encontrada!");getchar();break;
        }

    } while (op != 0);
    
}