//JVida_FGD_model.h
//Grupo: FGD
//Felipe Mendes Campos
//Daniel Kwang Hyuc Um
//Gustavo Macedo Costa
#define FALSE 0
#define TRUE 1
#define VIVO 'O'
#define MORTO '.'
#define VIZINHO '+'
//typedef int bool; // 0=False e qualquer outro inteiro = True
//bool fviz = FALSE; //se TRUE, mostra os mortos-vizinhos

char Matriz[60][60];
int MostraVizinh = 0;
int dim; //variavel para a dimensao da matriz
int totvivo, totmorto, totvivoprox; //quantidades totais das listas
typedef struct cel
{
	int  lin, col;
	struct cel *next; 
}TipoCel;

TipoCel  LConfig[100];  
char aux[60][60];