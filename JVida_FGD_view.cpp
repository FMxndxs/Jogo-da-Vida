//JVida_FGD_view.cpp
//Grupo: FGD
//Felipe Mendes Campos
//Daniel Kwang Hyuc Um
//Gustavo Macedo Costa

#include "JVida_FGD_view.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/*void DefineMatriz()
{
	
	printf("Digite um numero entre 10 e 60 para a criacao da sua matriz: ");
	scanf("%d", dim);
	printf ("\n\n");
	
	return(dim);
	
	limparBuffer();
}*/

int MenuDeOpcoes()

{

	int op;
	
	printf("+-------------------------------------+\n");
	printf("|                                     |\n");
	printf("|          ANUBIS LIFE'S GAME         |\n");
	printf("|                                     |\n");
	printf("+-------------------------------------+\n");
	printf("           *---------------*\n");
	printf("           |               |\n");
	printf("           |     MENU      |\n");
	printf("           |               |\n");
	printf("           *---------------*\n");
	printf("1  - Apresentar Mapa \n");
	printf("2  - Limpar o Mapa\n");
	printf("3  - Incluir/Excluir celulas vivas\n");
	printf("4  - Mostrar/Esconder vizinhos mortos\n");
	printf("5  - Iniciar o processo\n");
	printf("6  - Gravar uma geracao inicial\n");
	printf("7  - Recuperar uma geracao inicial cadastrada\n");
	printf("8 - Regras de evolucao das celulas\n");
	printf("0  - Sair\n");
	
	//Solicitar a opcao escolhida pelo usuario 
	printf("Digite um numero para prosseguir: ");
	scanf("%d", &op);
	printf("\n\n");
	return (op);
	
	limparBuffer();
	system ("cls");
}

void DefineTam()
{
	printf("\nEscolha o tamanho da matriz(10 - 60): ");
}

void ErroTam()
{
	printf("Tamanho invalido, tente novamente!");
}

void OpcaoInvalida()
{
	printf("Opcao Invalida, tente novamente");
}

void NovaLinha()
{
	printf("\n\n");
}


void apresentaMsg(const char mens[200])
{
	printf("%s", mens);
}


void MenuGeracoes()
{
	int geracao;
	printf("Digite a quantidade de geracoes: ");

    
   
}

void Menutempo()
{
	int tempo;
    printf("Digite o atraso de tempo: ");
    
   
}

void MenuGeraManual()
{
	int gerador;
	
	printf("Deseja criar a proxima geracao??");
	printf("Digite 1 para SIM ou 0 para NAO: ");
	
	
}

void mensagem(int valor)
{
    switch(valor)
    {
        case 1:
            printf("Tamanho informado incorreto, deve ser entre 10 e 60 !\n");
            break;
        case 2:
            printf("linha ou coluna ultrapassam os limites do mundo\n");
            break;
        case 3:
        	printf("Mundo ainda nao criado !!!\n");
        	break;
        case 4:
        	printf("Sem espaço na memoria para inclusao de celula viva\n");
        	break;
        case 5:
        	printf("O arquivo CONFIG_INIC nao pode ser aberto para gravacao\n");
        	break;
        case 6:
        	printf("Erro na gravacao do arquivo LConfig\n");
        	break;
        case 7:
        	printf("Salvamento realizado com sucesso!\n");
        	break;
        case 8:
        	printf("O arquivo LConfig nao pode ser aberto para leitura\n");
        	break;
        case 9:
        	printf("Erro na leitura do arquivo LConfig\n");
        	break;
        case 10:
        	printf("Carregamento concluido com sucesso\n");
        	break;
    }
}


int Menu_simula_view()
{
	int opt;
	
	printf("Quantas vezes quer simular?\nDigite a quantidade de geracoes desejada: ");
	scanf("%d", &opt);
	
	return opt;
}

void RegrasEvolucao()
{
	printf("Reproducao: Um ser vivo nasce numa celula vazia se essa celula tiver exatamente 3 vivos vizinhos");
	printf("\n Sobrevivencia: Um ser vivo que tenha dois ou tres vizinhos vivos sobrevive para a geracao seguinte");
	printf("\n Morte por falta de comida: Um ser vivo com 4 ou mais vizinhos vivos morre porque fica sem comida");
	printf("\n Morte por solidao: Um ser vivo com 0 ou 1 vizinhos morre de solidao\n\n");
}



