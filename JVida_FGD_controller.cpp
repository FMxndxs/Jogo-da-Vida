//JVida_FGD_controller.cpp
//Grupo: FGD
//Felipe Mendes Campos
//Daniel Kwang Hyuc Um
//Gustavo Macedo Costa

#include "JVida_FGD_controller.h"
#include "JVida_FGD_view.cpp"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>


void controll()
{
	
	DefineDim();
	CriarMatriz();
	MostraMatriz();
    int op;
    int i, k;
    
    do
    {
        op = MenuDeOpcoes();
        
        

        switch (op)
        {
        case 1:
        	system("cls");
			ExibirMatriz();
		   	//ftempo(6);
			break;
			
		case 2:
			system("cls");
			ftempo(1);
			LimpaMatriz();
			NovaLinha();
			//ftempo(5);
			
			break;
			
		case 3:
			system("cls");
			AdicionaCelulas();
			mostramundo();
			NovaLinha();
			NovaLinha();
			break;
			
		case 4:
			system("cls");
			FlagVizinho();
			//LimpaListaVivo():
			mostramundo();
			NovaLinha();
			break;
			
		case 5:
			system("cls");
			Menu_simula();
			atualizaViz();
			break;
			
		case 6: 
			system("cls");
			gravaCelula();
			break;
			
		case 7:
			system("cls");
			recuperaCelulas();
			mensagem(10);
			break;
			
		case 8:
			system("cls");
			RegrasEvolucao();
			break;
			
        case 0:
        	system("cls");
        	apresentaMsg("SAINDO DO PROGRAMA....\n OBRIGADO POR JOGAR\n");
        	NovaLinha();
        	//ftempo(2);
            break;

        default:
        	system("cls");
        	 OpcaoInvalida();
        	 NovaLinha();
        	 NovaLinha();
            break;
        }
		
		

    }
    while(op!=0);


}



void limparBuffer() //Funcao para descartar caracteres adicionais do Buffer e viabilizar a leitura de dados

{

    char C;
    while ((C = getchar()) != '\n' && C != EOF) {}

}

void ftempo(int seg)
{
	
	time_t lt1, lt2;
	lt1 = time(NULL);
	lt2 = lt1;
	while (difftime(lt2,lt1) < seg)
		lt2 = time(NULL);
}

int DefineDim()
{
	
	do
	{
		DefineTam();
		scanf("%d", &dim);
			
		if(dim >= 10 && dim <= 60)
		{
			return (dim);
		}
		else
			ErroTam();
	
	} while(dim < 10 || dim > 60);
	
 return 0;
}

void CriarMatriz()
{
	int i, j;
	
	for(i = dim - 1; i >= 0; i--)
        for(j = 0; j < dim; j++)
            Matriz[i][j] = '.';
}

void MostraMatriz()
{
	int i, j;
    
    printf("  ");
    for(j = 0; j < dim; j++) 
        printf(" %2d ", j);
    printf("\n");
            
	for(i = 0; i < dim; i++)
    {   
        printf("%2d", i); 
        for(j = 0; j < dim; j++)
            printf("  %c ", Matriz[i][j]);
        printf("\n");    
    }
}

/*int AtualizarMapa (char Matriz[dim][dim])
{
	
	int linha, coluna;
	
	for(linha = 1; linha <= dim; linha++)
		for(coluna = 1; coluna <= dim; coluna++)
		
	
}*/



void AdicionaCelulas()
{
    int linha, coluna, excluir, fim, opt;
    
	do
	{
		
	apresentaMsg("Deseja adicionar uma nova celula? Digite 1 para SIM ou 0 para NAO:  ");
    scanf("%d", &opt);
	
	if(opt == 1)
	{
    do
    {
        MostraMatriz();
        apresentaMsg("\nPara prosseguir, digite as coordenadas abaixo\n");
        apresentaMsg("Digite a linha para adicionar uma nova celula: ");
        scanf("%d", &linha);
        apresentaMsg("Digite a coluna para adicionar um celula: ");
        scanf("%d", &coluna);

		fim = 0;
		
        if (linha < 0 || linha >= dim || coluna < 0 || coluna >= dim)
        {
            apresentaMsg("A coordenada fornecida e invalida, tente novamente\n");
            fim++;
            ftempo(2);
            system("cls");
        }
        
        
    }while(fim != 0);

    if (Matriz[linha][coluna] == '.')
    {
        Matriz[linha][coluna] = 'O';
        carregaVivo(linha,coluna);
        mostraLvivo();
        
        apresentaMsg("A celula foi adicionada com sucesso\n");
    }
    else if (Matriz[linha][coluna] == 'O')
    {
        apresentaMsg("A posicao desejada ja esta ocupada.\n");
        apresentaMsg("Deseja excluir a celula? (Tecle 1 para SIM ou 0 para NAO): ");
        scanf("%d", &excluir);

        if (excluir == 0)
            apresentaMsg("A celula foi mantida na posicao, nenhuma alteracao foi feita\n");
        else if (excluir == 1)
        {
            Matriz[linha][coluna] = '.';
            apresentaMsg("A celula foi excluida com sucesso,");
            apresentaMsg("nao ha celulas ocupantes na posicao\n");
            excluiLVivo(linha,coluna);
        }
    }
    
    ftempo(1);
    system("cls");
	}
    
	}while(opt == 1);
}


void LimpaMatriz()  // funcao para limpar toda a Matriz, apagando todas os pontos que possuem '+' ou 'O' e substituindo pelos '.' originalmente postos.
{
	int i, j;
	int mostrar;
	
	for(i = dim - 1; i >= 0; i--)                      //varredura do mapa que verifica pontos do mapa com 'O' ou '+' e os substitui por '.'
        for(j = 0; j < dim; j++)
            if (Matriz[i][j] == 'O' || Matriz[i][j] == '+')
				{
					Matriz[i][j] = '.';
				}
				
	apresentaMsg("O mapa foi limpo, nao ha nenhuma celula viva, deseja ver o mapa?\n");
	apresentaMsg("TECLE 1 PARA SIM, 0 PARA NAO:  ");
	scanf("%d", &mostrar);
	
	if (mostrar == 1)					//Pergunta para exibir ou nao o mapa apos apaga-lo
	{
		MostraMatriz();
		
	}
	else if(mostrar == 0)
	{
		apresentaMsg("O mapa nao sera exibido, retornando ao Menu Principal em alguns segundos...");
	}
	
	else 
	{
		OpcaoInvalida();
	}
}


void MostraVizinho()  //Funcao para mostrar ou esconder os vizinhos no mapa das celulas 
{
	
	int i, j;
	
		for(i = 0; i < dim; i++)      
		{              
        	for(j = 0; j < dim; j++)
        	{
            	if (Matriz[i][j] == 'O')
            	{
            		if(Matriz[i+1][j] == '.')
            		{
            			Matriz[i+1][j] = '+';
					}
					if(Matriz[i+1][j+1] == '.')
					{
						Matriz[i+1][j+1] = '+';
					}
					if(Matriz[i][j+1] == '.')
					{
						Matriz[i][j+1] = '+';
					}
					if(Matriz[i-1][j] == '.')
					{
						Matriz[i-1][j] = '+';
					}
					if(Matriz[i-1][j-1] == '.')
					{
						Matriz[i-1][j-1] = '+';
					}
					if(Matriz[i-1][j+1] == '.')
					{
						Matriz[i-1][j+1] = '+';
					}
					if(Matriz[i+1][j-1] == '.')
					{
						Matriz[i+1][j-1] = '+';
					}
					if(Matriz[i][j-1] == '.')
					{
						Matriz[i][j-1] = '+';
					}
				}
			}
		}
	
	
}

void EscondeVizinho()
{
	
	int i, j;
	
	for(i = 0; i < dim; i++)                    
        	for(j = 0; j < dim; j++)
            	if (Matriz[i][j] == '+' && Matriz[i][j] != 'O')
            		Matriz[i][j] = '.';
}

void FlagVizinho() 
{
	int flag;
	int i, j;
	
	apresentaMsg("Digite 1 para mostrar as celulas vizinhas mortas ou 0 para esconder: ");
	scanf("%d", &flag);
	
	if(flag == 1)
	{
		apresentaMsg("Exibindo celulas vizinhas mortas");
		marcador = 1;
		
	}
	
	else if(flag == 0)
	{
		apresentaMsg("Celulas vizinhas mortas nao serao exibidas");
		marcador = 2;
		
	}
	
	else
	{
		system("cls");
		OpcaoInvalida();
	}
}

void ExibirMatriz()
{
	int i, j;
	
	if(marcador == 1)
	{
		MostraVizinho();
		MostraMatriz();
	}
	
	else if( marcador == 2)
	{
		EscondeVizinho();
		MostraMatriz();
	}
	
	
}

int ContarVizinhosVivos(int x, int y)
{
	int vzvivo = 0;
	int i, j;
	
	for(i = x-i; i <= x+1; i++)
	{
		for(j = y-1; j <= y+1; j++)
		{
			if(i != x || j != y)
			{
				if(Matriz[i][j] == 'O')
				{
					vzvivo++;
				}
			}
		}
	}
	
	return vzvivo;
}

void CriarMatrizSup()
{
	int i, j;
	
	for(i = 0; i < dim; i++)
        for(j = 0; j < dim; j++)
            Matriz[i][j] = '.';
}

void CriaNovaGeracao()
{
	int i, j;
	char MatrizSup[dim+2][dim+2]; // Matriz suporte para criar as geracoes seguintes
	
	for(i = 0 ; i < dim; i++)
	{
		for(j = 0; j < dim; j++)
		{
			int vzvivo = ContarVizinhosVivos(i, j); //contar os vizinhos de todas as celulas vivas na geracao atual
			
			if (Matriz[i][j] == 'O') {
                if (vzvivo < 2 || vzvivo > 3) 
				{
                    MatrizSup[i][j] = '.';  // Celula morre
                } 
				
				else 
				{
                    MatrizSup[i][j] = 'O';  // Celula continua viva
                }
            } 
			else 
			{
                if (vzvivo == 3) 
				{
                    MatrizSup[i][j] = 'O';  // Celula nasce
                } 
				
				else 
				{
                    MatrizSup[i][j] = '.';  // Celula permanece morta
                }
            }
		}
	}
	
	// Copiar Matriz Secundaria na Matriz Principal 
	
	for(i = 0; i < dim; i++)
		for(j = 0; j < dim; j++)
			Matriz[i][j] = MatrizSup[i][j];
			
			
	//devemos limpar a Matriz suporte para refazer o processo
	

}

void SimularGeracoes()
{
	int gerador, geracao, tempo, op;
	int i;
	
	apresentaMsg("Digite 1 para simulacao temporizada ou digite 2 para simular manualmente(Tecle 0 para sair): ");
	scanf("%d", &op);
	
	if (op == 1)
	{
		MenuGeracoes();
		scanf("%d", &geracao);
		Menutempo();
		scanf("%d", &tempo);
		
		for (i = 0; i < geracao; i++)
		{
			CriaNovaGeracao();
			system("cls");
			ExibirMatriz();
			
			time_t lt1, lt2;
			//atraso de tempo
			lt1 = time(NULL);
			lt2 = lt1;
			while (difftime(lt2, lt1) < tempo)
			{
				lt2 = time(NULL);
			}
			
			
			
		}
	}
	
	else if (op == 2)
	{
		do
		{
			MenuGeraManual();
			scanf("%d", &gerador);
			
			if(gerador == 1)
			{
				CriaNovaGeracao();
				system("cls");
				ExibirMatriz(); 
			}
			
			
		} while (gerador != 0);
		
		system("cls");
	}
	
	else if (op == 0)
	{
		apresentaMsg("Saindo da simulacao de novas geracoes");
	}
	
	else 
	{
		OpcaoInvalida();
	}
	
	
	
}

void criarlista()
{

TipoCel *aux; //define um ponteiro para uma variável TipoCel
aux = (TipoCel*)malloc(sizeof(TipoCel)); //aloca memória para 1 célula
if (aux == NULL)
 {
 apresentaMsg("Sem espaço na memoria\n");
 return; //ou break, ou exit, conforme o caso, etc.
 }
 
}

//  para percorrer a lista de células vivas, partir do ponteiro
// ponteiro pvivo:

void mostraLvivo()
{
 TipoCel *aux; //define um ponteiro auxiliar
 aux = pvivo; //inicializa esse ponteiro auxiliar
 if (totvivo > 0)
 {
 while(aux->next != NULL)
 {
 printf("|%d,%d| ", aux->lin, aux->col);
 aux = aux->next; //caminha para o próximo ponteiro
 }
 printf("|%d,%d| ", aux->lin, aux->col); //mostra a ultima celula
 }
 NovaLinha();
}


//Exclui uma celula viva da lista LVivo identificada pelas coordenadas ii e jj
void excluiLVivo(int ii, int jj)
{
 TipoCel *aux, *aux2; //define 2 ponteiros auxiliares
 aux = pvivo;
 aux2 = aux; //guarda a célula como sendo a anterior
 if (totvivo > 0)
 {
 while (aux->lin != ii || aux->col != jj)
 {
 aux2 = aux;
 aux = aux->next;
 }
 if (aux->lin == ii && aux->col == jj)
 {
 if (aux2 == aux) //se é o primeiro da lista
 pvivo = aux->next;
 else
 aux2->next = aux->next;
 free(aux);
 }
 totvivo--;
 }
}

void liberaLista(TipoCel *aux, int tot)
{
 if(aux == NULL || tot == 0) //já está liberada
 return;
 TipoCel *aux2;
 do
 {
 aux2 = aux;
 aux = aux->next;
 free(aux2); //libera memoria
 }
 while(aux != NULL);
}


void iniciaListas()
{
	
 liberaLista(pvivo, totvivo);
 liberaLista(pmorto, totmorto);
 liberaLista(pvivoprox, totvivoprox);
 pvivo = pmorto = pvivoprox = NULL; //ponteiros vazios
 totvivo = totmorto = totvivoprox = 0; //inicialmente listas vazias
}

void carregaVivo(int i, int j)
{
 TipoCel *aux = (TipoCel*) malloc(sizeof(TipoCel));
  if (aux == NULL)
  {
  apresentaMsg("Sem espaço na memoria para inclusao de celula viva\n");
   return;
  }
 aux->lin = i;
 aux->col = j;
 if(totvivo == 0)
  {
  pvivo = aux;
   pvivo->next = NULL;
  }
  else //lista não vazia
  {
   aux->next = pvivo;
   pvivo = aux;
  }
  totvivo++;
}

//inclui uma célula na Lista de vivos da próxima geração
void carregaVivoProx(int ii, int jj)
{
 TipoCel *aux = (TipoCel*)malloc(sizeof(TipoCel));
 if (aux == NULL)
 {
 apresentaMsg("Sem espaço na memoria para inclusao de celula viva para a proxima geracao\n");
 return;
 }
 aux->lin = ii;
 aux->col = jj;
 if(totvivoprox == 0) //se a lista está vazia
 {
 pvivoprox = aux;
 pvivoprox->next = NULL;
 }
 else //lista não vazia
 {
 aux->next = pvivoprox;
 pvivoprox = aux; //o inicio da lista passa a ser a nova celula
 }
 totvivoprox++;
}


//verifica se já está na Lista de mortos
bool VerifMorto(int ii, int jj)
{
 TipoCel *aux;
 aux = pmorto;
 if (totmorto == 0)
 return FALSE;
 do
 {
 if (aux->lin == ii && aux->col == jj)
 return TRUE;
 aux = aux->next;
 } while (aux != NULL);
 return FALSE;
}

void carregaMorto(int ii, int jj)
{
	int fviz;
 if ((ii < 0) || (jj < 0)) //celula inexistente
 return;
 if ((ii >= dim) || (jj >=dim)) //celula inexistente
 return;
 if(Matriz[ii][jj] == VIVO) //celula viva
 return;
 //Verifica se este morto-vizinho já está na lista
 if (VerifMorto(ii, jj)== TRUE)
 return;
 //inclui na lista de mortos-vizinhos
 TipoCel *aux = (TipoCel*)malloc(sizeof(TipoCel));
 if (aux == NULL)
 {
 apresentaMsg("Sem espaço na memoria para inclusao de celula morta-vizinha\n");
 return;
 }
 aux->lin = ii;
 aux->col = jj;
 if(totmorto == 0) //se a lista está vazia
 {
 pmorto = aux;
 pmorto->next = NULL;
 }
 else //lista não vazia
 {
 aux->next = pmorto;
 pmorto = aux; //o inicio da lista passa a ser a nova celula
 }
 totmorto++;
 if (fviz == TRUE) //se TRUE, mostra os vizinhos mortos
 Matriz[ii][jj] = VIZINHO;
 else
 Matriz[ii][jj] = MORTO;
}


//inclui celulas vizinhas mortas na Lista Lmortos
void carregaMortosViz()
{
 int k, i, ii, jj;
 struct
 {
 int li, co; //linha e coluna
 } a,b,c,d,e,f,g,h; //celulas vizinhas
 //libera lista de mortos
 totmorto = 0;
 TipoCel *aux;
 aux = pvivo;
 if (totvivo == 0)
 return;
 do
 {
 ii = aux->lin;
 jj = aux->col;
 a.li = ii-1; a.co = jj-1;
 b.li = ii-1; b.co = jj;
 c.li = ii-1; c.co = jj+1;
 d.li = ii; d.co = jj-1;
 e.li = ii; e.co = jj+1;
 f.li = ii+1; f.co = jj-1;
 g.li = ii+1; g.co = jj;
 h.li = ii+1; h.co = jj+1;
 carregaMorto(a.li, a.co);
 carregaMorto(b.li, b.co);
 carregaMorto(c.li, c.co);
 carregaMorto(d.li, d.co);
 carregaMorto(e.li, e.co);
 carregaMorto(f.li, f.co);
 carregaMorto(g.li, g.co);
 carregaMorto(h.li, h.co);
 if(aux->next == NULL)
 break;
 aux = aux->next;
 }
 while(TRUE);
}



//Calcula a qtde de vizinhos (de celulas vivas e mortas)
//e executa o processo para chegar à proxima geração
void atualizaViz()
{
 int i, j, ii, jj, vii, vjj, ct;
 liberaLista(pvivoprox, totvivoprox);
 pvivoprox = NULL; //ponteiros vazios
 if (pvivo == NULL)
 return;
 //vizinhos vivos das celulas vivas
 TipoCel *aux, *aux2;
 aux = pvivo;
 do
 {
 ct = 0; //contador de vizinhos da celula (ii,jj)
 ii = aux->lin;
 jj = aux->col;
 aux2 = pvivo;
 do
 {
 vii = aux2->lin;
 vjj = aux2->col;
 if (vii != ii || vjj != jj) //se não for a mesma célula
 if(abs(ii-vii)<=1 && abs(jj-vjj)<=1) //se é vizinho
 ct++;
 aux2 = aux2->next;
 } while(aux2 != NULL);
 //ATITUDE sobre a célula viva conforme a qtd.de vizinhos
 if (ct == 2 || ct == 3)
 carregaVivoProx(ii,jj); //sobrevive na próxima geração
 //else
 // carregaMortoProx(ii,jj); //morre na próxima geração
 aux = aux->next;
 } while(aux != NULL);
 if (pmorto == NULL)
 return;
 //vizinhos vivos das celulas mortas
 aux = pmorto;
 do
 {
 ct = 0; //contador de vizinhos da celula (ii,jj)
 ii = aux->lin;
 jj = aux->col;
 aux2 = pvivo;
 do
 {
 vii = aux2->lin;
 vjj = aux2->col;
 if(abs(ii-vii)<=1 && abs(jj-vjj)<=1) //se é vizinho
 ct++;
 aux2 = aux2->next;
 } while(aux2 != NULL);
 //ATITUDE sobre a célula morta conforme a qtd.de vizinhos vivos
 if (ct == 3)
 carregaVivoProx(ii,jj); //nasce na próxima geração
 aux = aux->next;
 } while(aux != NULL);
}

void mostramundo()
{
	int i,j;
MostraVizinho();
carregaMortosViz();
system("cls");
printf("\n");
printf("    ");
	for(j =0; j < dim; j++)
		printf("%2d ", j);
		printf("\n\n");
	for(i = 0; i < dim ; i++)
{

printf("%2d ", i);
for(j = 0; j < dim;j++)
{

	if( MostraVizinh == 0)
	{
	if(Matriz[i][j] == '+')
		printf(" . ");
	else
		printf("%3c",Matriz[i][j]);
	}
	else
		printf("%3c",Matriz[i][j]);
	}
NovaLinha();
}
printf("vivos= ");
mostraLvivo();
printf("mortos= ");
mostraLmorto();

}

void mostraLmorto()
{
TipoCel *aux; //define um ponteiro auxiliar
aux = pmorto; //inicializa esse ponteiro auxiliar
if (totmorto > 0)
	{
	while(aux->next != NULL)
		{
	
		printf("|%d,%d| ",aux->lin, aux->col);
		aux = aux->next; //caminha para o próximo ponteiro
		}
printf("|%d,%d| ", aux->lin, aux->col); //mostra a ultima celula
	}
NovaLinha();
}


void gravaCelula()
{
	int i, j, cont = 0;
	FILE *fp;
	
	//gravar no LConfig todas as celulas vivas
	
	for(i = 0; i < dim; i++)
	{
		for(j = 0; j < dim; j++)
		{
			if(Matriz[i][j] == 'O')
			{
				LConfig[cont].lin = i;
				LConfig[cont].col = j;
				cont++;
			}
		}
	}
	
	if( (fp = fopen("CONFIG_INIC", "w")) == NULL)
	{
		mensagem(5);
		return;
	}
	
	fwrite(&dim, sizeof(int), 1, fp);
	
	for(i = 0; i < totvivo; i++)
	{
		if(fwrite(&LConfig[i], sizeof(TipoCel), 1,fp) != 1)
		{
			mensagem(6);
			break;
		}
	}
	
	mensagem(7);
	fclose(fp);
	
}

void recuperaCelulas()
{
	int i, j, cont;
	int aux[2];
	FILE *fp;
	
	if( (fp = fopen("CONFIG_INIC", "r")) == NULL)
	{
		mensagem(8);
		return;
	}
	
	fread(&dim, sizeof(int), 1,fp);
	
	//limpar o mundo (a matriz e a lista)
	
	for(i = 0; i < dim; i++)
	{
		for(j = 0; j < dim; j++)
		{
			if(Matriz[i][j] == 'O')
			{
				excluiLVivo(i+1, j+1);
			}
			Matriz[i][j] = '.';
		}
	}
	
	do
	{
		//Recuperar o array do LConfig
		if(fread(&LConfig[cont], sizeof(TipoCel), 1,fp) != 1)
		{
			mensagem(9);
			break;
		}
		cont++;
	}while (LConfig->next != NULL);
	
	fread(&LConfig[cont], sizeof(TipoCel), 1, fp);
	
	cont = 0;
	for(i = 0; i < dim; i++)
	{
		for(j = 0; j < dim; j++)
		{
			if((i == LConfig[cont].lin) && (j == LConfig[cont].col))
			{
				Matriz[i][j] = 'O';
				cont++;
			}
		}
	}
	
	
}

void Simular()
{
	int linha, coluna;
	
	for(linha = 0; linha < dim; linha++)
	{
		for(coluna = 0; coluna < dim; coluna++)
		{
			if(Matriz[linha][coluna] == 'O')
			{
				aux[linha][coluna] = 'O';
				if( (neighboursAlive(linha,coluna) < 2) || neighboursAlive(linha,coluna) > 3)
				{
					//celula morrera em caso de ter menos de dois vizinhos ou mais de 3 vizinhos
					aux[linha][coluna] ='.';
				}
			}
			else 
			{
				if(neighboursAlive(linha,coluna) == 3)
				{
					//celula nasce em caso de ter 3 vizinhos vivos
					aux[linha][coluna] = 'O';
				}
			}
			if(Matriz[linha][coluna] == '.')
			{
				aux[linha][coluna] = '.';
				if(neighboursAlive(linha,coluna) == 3)
					aux[linha][coluna] = 'O';
			}
			
		}
	}
	updates();
	
}

void updates()
{
	int linha, coluna;
	
	for(linha = 0; linha < dim; linha++)
	{
		for(coluna = 0; coluna < dim; coluna++)
		{
			Matriz[linha][coluna] = aux[linha][coluna];
		}
	}
}




void Menu_simula()
{
	int opt, i;
	opt = Menu_simula_view();
	
	for(i = 0; i < opt; i++)
	{
		Simular();
		Sleep(2000);
		ExibirMatriz();
	}
}



int neighboursAlive(int linha, int coluna)
{
	int contaVivos = 0;
	int x,y;
	
	for(x = linha - 1; x <= linha + 1; x++)
	{
		for(y = coluna -1; y <= coluna + 1; y++){
			if(x == linha && y == coluna){
				continue;
			}
			if(Matriz[x][y] == 'O'){
				contaVivos += 1;
			}
		}
	}
	
	return contaVivos;
}

















