#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>

void cores(int ForgC, int BackC){
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

void textcolor(int newcolor){
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
     (csbi.wAttributes & 0xf0) | newcolor);
}

void gotoxy(int x, int y) {
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void imp_autor(){
  setlocale(LC_ALL, "Portuguese");
  gotoxy(27,12);
  textcolor(10);
  printf("Vinícius Daniel");
  Sleep(1500);
  system("cls"); // comando para limpar o conteúdo da tela.
  textcolor(15);
}

int gcont = 0, g = 0; //VARIAVEIS GLOBAIS

struct Mercado
{
    int cod;
    char nome[50];
    int quantEstqMin = 0;
    float precoMedUni = 0;
    int estqTotal = 0;
};

struct Mercado produto[10]; //VETOR DO TIPO MERCADO QUE RECEBERA O STRUCT

// AQUI COMEÇAM AS FUNÇÕES

struct Mercado cadastra(struct Mercado prod[]);
struct Mercado listar(struct Mercado prod[]);
struct Mercado consultar(struct Mercado prod[]);
struct Mercado vender(struct Mercado prod[]);
struct Mercado comprar (struct Mercado prod[]);

main()
{

   char opcao;

    do
    {
        system("cls");

        textcolor(10);
        gotoxy(14,3);
        printf("<MENU PRINCIPAL>");

        gotoxy(10,4);
        printf("========================");
        textcolor(15);
        gotoxy(10,5);
        printf("1 - Cadastrar Produto");
        gotoxy(10,6);
        printf("2 - Listar Produto");
        gotoxy(10,7);
        printf("3 - Consultar Produto");
        gotoxy(10,8);
        printf("4 - Vender Produto");
        gotoxy(10,9);
        printf("5 - Comprar Mercadoria");
        gotoxy(10,10);
        printf("6 - Sair");
        gotoxy(10,15);
        printf("Selecione uma opcao: ");
        opcao = getche();

        switch(opcao)
        {
            case '1':
                system("cls");
                gotoxy(27,14);
                textcolor(10);
                printf("CADASTRO SELECIONADO...");
                Sleep(2000);
                textcolor(15);
                system("cls");
                cadastra(produto);

            break;

            case '2':
                system("cls");
                gotoxy(27,14);
                textcolor(10);
                printf("LISTAGEM SELECIONADA...");
                Sleep(2000);
                textcolor(15);
                system("cls");
                listar(produto);

            break;

            case '3':
                system("cls");
                gotoxy(27,14);
                textcolor(10);
                printf("CONSULTA SELECIONADA...");
                Sleep(2000);
                textcolor(15);
                system("cls");
                consultar(produto);

            break;

            case '4':
                system("cls");
                gotoxy(27,14);
                textcolor(10);
                printf("VENDA DE PRODUTO SELECIONADA...");
                Sleep(2000);
                textcolor(15);
                system("cls");
                vender(produto);

            break;

            case '5':
            system("cls");
            gotoxy(27,14);
            textcolor(10);
            printf("INCLUIR PRODUTO SELECIONADO...");
            Sleep(2000);
            textcolor(15);
            system("cls");
            comprar(produto);

            break;

            case '6':
            system("cls");
            gotoxy(10,10);
            printf("O programa foi encerrado.");
            gotoxy(10,12);
            printf("Tecle algo para sair...");
            getch();
            exit (0);

            break;

            default:
            gotoxy(10,17);
            textcolor(12);
            printf("Opcao Invalida.");
            textcolor(15);
            gotoxy(10,18);
            printf("Tecle algo para continuar...");
            getch();
        }

    }while(opcao!=6);

   getch(); // força uma parada do programa no final da seua execução.
}//Aqui termina o main e começa as funções.

struct Mercado cadastra(struct Mercado prod[]) //INICIO DO CADASTRO
{
    int i;
    char continua = 's';

    while(continua == 's')
    {
        gotoxy(10,3);
        textcolor(10);
        printf("<CADASTRO DE PRODUTO>\n");
        printf("==========================================\n");
        textcolor(15);

        gotoxy(10,6);
        printf("Codigo: ");
        scanf("%d", &produto[gcont].cod);
        fflush(stdin);

        gotoxy(10,7);
        printf("Nome: ");
        gets(produto[gcont].nome);
        fflush(stdin);

        gotoxy(10,8);
        printf("Quantidade minima: ");
        scanf("%d", &produto[gcont].quantEstqMin);
        fflush(stdin);

        gotoxy(10,11);
        printf("Produto cadastrado! Deseja continuar [s/n]? ");
        scanf("%c", &continua);

        if(continua == 's')
        {
            gcont++;
            system("cls");
            continua = 's';
        }
        else
        {
            gcont++;
            system("cls");
            continua = 'n';
            main();
        }
    }
} // FIM DO CADASTRO

struct Mercado listar(struct Mercado prod[]) //LISTAR OS PRODUTOS
{
    int i;
    float valorAtual = 0;
    char continuaLista = 's';

    gotoxy(10,3);
    textcolor(10);
    printf("<LISTAR PRODUTOS>\n");
    printf("======================================\n");
    textcolor(15);

    for(i = 0; i < gcont; i++)
    {
        printf("Codigo do produto: %d\nProduto: %s\nQuantidade Minima em estoque: %d\nQuantidade total em estoque: %d\nPreco medio unitario: %.2f\n\n",
                                                                           prod[i].cod,
                                                                           prod[i].nome,
                                                                           prod[i].quantEstqMin,
                                                                           prod[i].estqTotal,
                                                                           prod[i].precoMedUni);
        valorAtual = valorAtual + (prod[i].estqTotal * prod[i].precoMedUni);

    }

    textcolor(10);
    printf("Valor total em estoque: %.2f\n\n", valorAtual);
    textcolor(15);

    gotoxy(0, 30);
    printf("\n\nProdutos listados! Digite algo para sair! ");
    continuaLista = getche();

    system("cls");
    main();
} //FIM DA LISTAGEM

struct Mercado consultar(struct Mercado prod[]) // INICIO DA FUNÇÃO CONSULTA
{
    int i=0, testCod=0, contLocal = 0;
    float valorAtual = 0;
    char loop = 's', voltaMenu;


        gotoxy(10,3);
        textcolor(10);
        printf("<CONSULTAR PRODUTO>\n");
        printf("======================================\n");
        textcolor(15);

        gotoxy(5, 5);
        printf("Digite o codigo do produto: ");
        scanf("%d", &testCod);

        printf("\n");
        printf("\n");

        for (i=0; i<gcont; i++)
        {
            if(testCod == prod[i].cod)
            {
                 printf("Codigo do produto: %d\nProduto: %s\nQuantidade Minima em estoque: %d\nQuantidade total em estoque: %d\nPreco medio unitario: %.2f\n\n",
                                                                           prod[i].cod,
                                                                           prod[i].nome,
                                                                           prod[i].quantEstqMin,
                                                                           prod[i].estqTotal,
                                                                           prod[i].precoMedUni);

                valorAtual = prod[i].estqTotal * prod[i].precoMedUni;

                textcolor(10);
                printf("Valor total em estoque do produto: %.2f\n\n", valorAtual);

                printf("Produto listado! Digite algo para voltar ao menu!");
                textcolor(15);
                voltaMenu = getche();
                system("cls");
                main();

            }
            if (testCod != prod[i].cod)
            {
                contLocal++;
            }


        }

         if (contLocal == gcont)
            {
                gotoxy(33, 5);
                textcolor(12);
                printf("Codigo invalido!\n");
                textcolor(15);
                Sleep(2000);
                system("cls");
                main();
            }

        for(i = 0; i < gcont; i++)
        {
            if(prod[i].estqTotal < prod[i].quantEstqMin)
            {
                gotoxy(32, 8);
                textcolor(12);
                printf("Estoque abaixo do minimo!\n");
                textcolor(15);
            }
        }

} // FIM DA CONSULTA

struct Mercado vender(struct Mercado prod[]) // INICIO DA FUNÇÃO DE EXCLUIR
{
    int i = 0, j = 0, removeCod = 0, vend, contLocal =0;
    char voltaMenu;

    gotoxy(10,3);
    textcolor(10);
    printf("<VENDER MERCADORIA>\n");
    printf("======================================\n");
    textcolor(15);

    gotoxy(10,5);
    printf("Digite o codigo do produto: ");//PRODUTO VENDIDO
    scanf("%d", &removeCod);

    gotoxy(10,6);
    printf("Digite a quantidade vendida: ");
    scanf("%d", &vend);

    for(i=0;i<gcont;i++)
    {
        if(vend > prod[i].estqTotal)
        {
            textcolor(12);
            printf("Valor em estoque indisponivel! Voltando ao menu...");
            textcolor(15);
            Sleep(2000);
            system("cls");
            main();
        }
    }

    for(i = 0;i<gcont;i++)
    {
        if(removeCod == prod[i].cod)
        {
            prod[i].estqTotal = prod[i].estqTotal - vend;

            if(prod[i].estqTotal < prod[i].quantEstqMin)
            {
                gotoxy(10,7);
                textcolor(12);
                printf("Estoque minimo abaixo do esperado! Faltam %d unidades para completar o estoque!\n\n", prod[i].quantEstqMin - prod[i].estqTotal);
                textcolor(15);
            }

            gotoxy(10,8);
            textcolor(10);
            printf("\nQuantidade Removida! Digite algo para voltar ao menu!");
            textcolor(15);
            voltaMenu = getche();
            system("cls");
            main();
        }


        if (removeCod != prod[i].cod)
        {
            contLocal++;
        }
    }

    if (contLocal == gcont)
    {
        system("cls");
        gotoxy(10,6);
        printf("Produto nao encontrado!");
        Sleep(2000);
        system("cls");
    }

} // FIM DA FUNÇÇÃO DE EXCLUIR

struct Mercado comprar(struct Mercado prod[]) // INICIO DA FUNÇÃO DE INCLUIR
{
    int i = 0, add =0, qntdd=0, contLocal = 0;
    float vTotal=0;
    char voltaMenu = 's';


        gotoxy(10,3);
        textcolor(10);
        printf("<COMPRAR PRODUTO>\n");
        printf("======================================\n");
        textcolor(15);

        gotoxy(4,5);
        printf("Digite o codigo do produto que deseja incluir: ");
        scanf("%d", &add);

        for(i = 0;i<gcont;i++)
        {
            if (add == prod[i].cod)
            {
                system("cls");
                gotoxy(10,3);
                textcolor(10);
                printf("<COMPRAR PRODUTO>\n");
                printf("======================================\n");
                textcolor(15);

                //system("cls");
                gotoxy(10,6);
                printf("Digite a quantidade comprada: ");
                scanf("%d", &qntdd);

                //system("cls");
                gotoxy(10,7);
                printf("Digite o valor total da compra: ");
                scanf("%f", &vTotal);

                prod[i].precoMedUni = ((prod[i].precoMedUni*prod[i].estqTotal) + vTotal)/ (prod[i].estqTotal + qntdd);
                prod[i].estqTotal = prod[i].estqTotal + qntdd;

                main();
            }

            if(add != prod[i].cod)
            {
                contLocal++;
            }
    }

    if(contLocal == gcont)
    {
        system("cls");
        gotoxy(10,6);
        printf("Produto nao encontrado! Voltando ao menu...");
        Sleep(2000);
        system("cls");
        main();
    }
}//FIM DA FUNÇÃO COMPRAR
