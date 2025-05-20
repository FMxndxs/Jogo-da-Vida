//JVida_FGD_controller.h
//Grupo: FGD
//Felipe Mendes Campos
//Daniel Kwang Hyuc Um
//Gustavo Macedo Costa

void MostraMatriz();
void limparBuffer();
void controll();
int DefineDim();
void AdicionaCelulas();
void CriarMatriz();
void ftempo(int seg);
void LimpaMatriz();
void MostraVizinho();
void EscondeVizinho();
void FlagVizinho();
int marcador = 2;
void ExibirMatriz(); 
int ContarVizinhosVivos(int x, int y);
void CriarMatrizSup();
void CriaNovaGeracao();
void SimularGeracoes();
void excluiLVivo(int ii, int jj);
void mostraLvivo();
void mostraLmorto();
void atualizaViz();
void mostramundo();
void carregaVivo(int i, int j);
void gravaCelula();
void recuperaCelulas();
int neighboursAlive(int linha, int coluna);
void Menu_simula();
void Simular();
void updates();















