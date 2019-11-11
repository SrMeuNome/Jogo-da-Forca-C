#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAM 100
#define MAX_ERROS 6


char enforcado[MAX_ERROS] = "OH\\//\\";

void imprime_enforcado_completo()
{

	char boneco[MAX_ERROS] = {' ', ' ', ' ', ' ', ' ', ' ',};

printf("TESTE: %s\n");

	printf("\t*** Jogo da Forca ***\n");
	printf("\t----------\n");
	printf("\t|\t |\n");
	printf("\t|\t %c\n", enforcado[0]);
	printf("\t|\t%c %c\n", enforcado[2], enforcado[3]);
	printf("\t|\t %c\n", enforcado[1]);
	printf("\t|\t%c %c\n", enforcado[4], enforcado[5]);
	printf("\t|\n");
	printf("\t|\n");
	printf("\t-----\n");

}

void imprime_enforcado(int erros)
{
	printf("\t*** Jogo da Forca ***\n");
	printf("\t----------\n");
	printf("\t|\t |\n");
	printf("\t|\t ");
	//cabeca
	if(erros > 0)
	 printf("%c", enforcado[0]);
	printf("\n\t|");
	//braco direito
	if(erros > 1)
		printf("\t%c ", enforcado[2]);
	//braco esquerdo
	if(erros > 2)
		printf("%c", enforcado[3]);
	printf("\n\t|");
	//corpo
	if(erros > 3)
	printf("\t %c", enforcado[1]);
	printf("\n\t|");
	//perna direita
	if(erros > 4)
		printf("\t%c", enforcado[4]);
	//perna esquerda
	if(erros > 5)
		printf(" %c", enforcado[5]);
//	else
		printf("\n");
	printf("\t|\n");
	printf("\t|\n");
	printf("\t-----\n");

}
//ArmazenarLetras
void TamanhoPalavraSecreta(int* tamanhoPalavraSecreta)
{
//GuardarLetras
    printf("DIGITE QUANTAS LETRAS TERA A PALAVRA SECRETA: ");
    scanf("%d", tamanhoPalavraSecreta);
}

char* AtribuirTamanho(int tamanhoPalavraSecreta)
{
    char* palavraSecreta;
    palavraSecreta = (char*) malloc(sizeof(char)*(tamanhoPalavraSecreta));

    return palavraSecreta;
}

char* AtribuirUmOco(char* palavra, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        palavra[i]= '-';
    }
    palavra[tam]= '\0';
}

void PegarPalavraSecreta(char palavraSecreta[])
{
    printf("DIGITE A PALAVRA SECRETA: ");
    scanf(" %[^\n]", palavraSecreta);
}

void SaltarLinhas()
{
    int i;

    for(i=0;i<=100;i++)
        printf("\n\n\n\n\n\n\n\n");
}

void PerguntarLetra(char* resposta)
{
    printf("\n\n FACA UM CHUTE: ");
    scanf(" %c", resposta);
}

int CompararLetra(char palavraSecreta[], char letrasCertas[], char resposta, int erros)
{
    int i, acerto = 0;

    for (i=0;palavraSecreta[i]!='\0';i++)
    {//palavraSecreta, letrasCertas
        if (palavraSecreta[i] == resposta)
        {
            letrasCertas[i] = palavraSecreta[i];
            acerto++;
           // printf ("\nacerto = %d\n", acerto);
        }

    }
    if(acerto==0)
    {
        erros++;
    //printf ("\nerros=%d\n", erros);
    }
    return erros;
}

int VerificarGanhou(char palavraSecreta[],char letrasCertas[])
{
    return strcmp(palavraSecreta, letrasCertas);
}

void ConverterMaiusculo(char* palavra)
{
    strupr(palavra);
}

void FimJogo(int ganhou, char* palavraSecreta)
{
    if(ganhou==0)
    {
        printf("\n\nPARABENS VOCE GANHOU!!!\n\n");
    } else
    {
        printf("\n\nPARABENS VOCE SE FERROU!!!\n\n");
        printf("A palavra certa era: %s\n\n", palavraSecreta);
    }
}

void GuardarLetras(char letras, char* VetorLetras, int* indice)
{
    VetorLetras[*indice] = letras;
}

int CompararSeRepete (char letra, char* Texto)
{
    int i;
    for(i=0;Texto[i]!='\0';i++)
    {
        if(Texto[i]==letra)
        {
            return 1;
        }
    }
    return 0;
}

void VerificarOco(char* palavraSecreta, char* letrasCertas)
{
    int i;
    for(i=0;palavraSecreta[i]!='\0';i++)
    {
        if(palavraSecreta[i]== 32)
        {
            letrasCertas[i] = 32;
        }
    }
}

int main()
{
    int i = 0;
	int erros = 0;
    char* palavraSecreta; //palavra secreta escolhida
    char resposta; //letra chutada
    int tentativa = 0;
    int ganhou = AtribuirUmOco;
    int tamanhoPalavraSecreta;
    char* letrasCertas; //
    char* ArmazenarLetras;

	do
    {
        TamanhoPalavraSecreta(&tamanhoPalavraSecreta);
        palavraSecreta = AtribuirTamanho(tamanhoPalavraSecreta);
        letrasCertas = AtribuirTamanho(tamanhoPalavraSecreta);
        ArmazenarLetras = AtribuirTamanho(tamanhoPalavraSecreta+6);
        AtribuirUmOco(letrasCertas, tamanhoPalavraSecreta);
        AtribuirUmOco(ArmazenarLetras, tamanhoPalavraSecreta+6);
        AtribuirUmOco(palavraSecreta, tamanhoPalavraSecreta);
        PegarPalavraSecreta(palavraSecreta);
        ConverterMaiusculo(palavraSecreta);
        if(tamanhoPalavraSecreta != strlen(palavraSecreta))
           {
                printf("\n\nPalavra pequena para o tamanho desejado.\n\n");
                free(palavraSecreta);
                free(letrasCertas);
                free(ArmazenarLetras);
           }
	} while(tamanhoPalavraSecreta != strlen(palavraSecreta));

	VerificarOco(palavraSecreta, letrasCertas);

	SaltarLinhas();

    while(erros<MAX_ERROS && ganhou!=0)
    {
        imprime_enforcado(erros);
        printf("\n%s\n", letrasCertas);
        printf("\n\nVoce ja chutou: %s\n\n", ArmazenarLetras);

        do
        {
            PerguntarLetra(&resposta);
            ConverterMaiusculo(&resposta);
            if(CompararSeRepete(resposta, ArmazenarLetras) == 1)
               {
                   printf("\n\nEssa letra e repetida cabecao!!! Digite novamente: ");
               }
        }while(CompararSeRepete(resposta, ArmazenarLetras)!= 0);

        GuardarLetras(resposta, ArmazenarLetras, &i);
	    erros = CompararLetra(palavraSecreta, letrasCertas, resposta, erros);
        ganhou = VerificarGanhou(palavraSecreta, letrasCertas);
	    printf("***Erros = %d\n", erros);
	    tentativa++;
	    i++;
	}

	SaltarLinhas();
	imprime_enforcado(erros);
	FimJogo(ganhou, palavraSecreta);

	free(palavraSecreta);
	free(letrasCertas);
	free(ArmazenarLetras);

	return 0;
}
