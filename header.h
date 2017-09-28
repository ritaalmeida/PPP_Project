#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>//Acentuação
#include <ctype.h>

#define MAX 50
//Estruturas
typedef struct data{
	int dia, mes, ano, hora, minutos;
}Data;

typedef struct doente *D;
typedef struct doente{
	char *nome; 
	int bi;
	int numlista;
	Data registo;
	D next;
}Doente;


//Declaraçao de funçoes
void voltarMenuOuSair(D* doente, D* vermelha, D* amarela, D*verde, D* geral);
D cria_lista(int num);
D procura_lista(D lista, char* name, int cc, Data d, D* ant, D* actual);
D insere_doente_lista(D* lista,char *name, int cc, Data d);
void imprime_lista(D lista);
D pedirDados(D* doente, D* geral);
void menuInicial(D* doente, D* vermelha, D* amarela, D*verde, D* geral);
void elimina_doente_triagem(D* doente);
D atribuirPulseira(D* doente, D* vermelha, D* amarela, D* verde, D* geral);
void elimina_doente_lista_sresposta(D* doente, int cc);
void elimina_doente_consulta(D* doente, D* vermelha, D* amarela, D* verde, D* geral);
void elimina_doente_lista_consulta(D* doente, int cc);
void listar_por_prioridade(D* doente, D* vermelha, D* amarela, D* verde);
void listar_geral(D* geral);
void proximo_cliente(D* doente, D* vermelha, D* amarela, D* verde, D* geral);
int lista_vazia(D lista);
void eliminaListar(D* lista, D* doente, D* vermelha, D*amarela, D* verde, D* geral, int cc);
void escreve_ficheiros(D lista, int tipo);
void le_ficheiros(D* lista, int tipo);
int verfica_bi_existe(D* lista, int cc);
int verifica_bi(int cc);
int verifica_bi_alpha(char *str_bi);
int verifica_nome(char *nome);