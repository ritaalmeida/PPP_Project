#include "header.h"


void menuInicial(D* doente, D* vermelha, D* amarela, D* verde, D* geral){
	char opcao;

	system("clear");
	printf("\n\t\t--Bem-vindo ao Centro Hospitalar de Coimbra--\n");
	printf("\nEscolha uma das seguintes opções: \n");
	printf("1-> Admitir um doente\n");
	printf("2-> Atribuir um doente a uma prioridade\n");
	printf("3-> Cancelar um doente em espera para triagem\n");
	printf("4-> Cancelar um doente em espera para consulta\n");
	printf("5-> Listar os doentes por prioridade de atendimento\n");
	printf("6-> listar os doentes de todas as prioridades ordenados por data e hora\n");
	printf("7-> Listar o próximo cliente a ser atendido\n");
	printf("8-> Sair\n");
	printf("Opção: ");
	scanf(" %c", &opcao);

	switch(opcao){
		case '1':
			system("clear");
			pedirDados(doente,geral);
			voltarMenuOuSair(doente, vermelha, amarela, verde, geral);
			break;

		case '2':
			system("clear");
			atribuirPulseira(doente, vermelha, amarela, verde, geral);
			voltarMenuOuSair(doente, vermelha, amarela, verde, geral);
			break;

		case '3':
			system("clear");
			elimina_doente_triagem(doente);
			voltarMenuOuSair(doente, vermelha, amarela, verde, geral);
			break;

		case '4':
			system("clear");
			elimina_doente_consulta(doente, vermelha, amarela, verde, geral);
			voltarMenuOuSair(doente, vermelha, amarela, verde, geral);
			break;

		case '5':
			system("clear");
			listar_por_prioridade(doente, vermelha, amarela, verde);
			voltarMenuOuSair(doente, vermelha, amarela, verde, geral);
			break;

		case '6':
			system("clear");
			listar_geral(geral);
			voltarMenuOuSair(doente, vermelha, amarela, verde, geral);
			break;

		case '7':
			system("clear");
			proximo_cliente(doente, vermelha, amarela, verde, geral);
			voltarMenuOuSair(doente, vermelha, amarela, verde, geral);
			break;

		case '8':
			system("clear");
			exit(0);

		default:
			system("clear");
			printf("\nERRO: opção inexistente.\n\n");
			menuInicial(doente, vermelha, amarela, verde, geral);
	}

}

int main(){
	D doente = cria_lista(0);
	le_ficheiros(&doente,0);
	D vermelha = cria_lista(1);
	le_ficheiros(&vermelha,1);
	D amarela = cria_lista(2);
	le_ficheiros(&amarela,2);
	D verde = cria_lista(3);
	le_ficheiros(&verde,3);
	D geral = cria_lista(4);
	le_ficheiros(&geral,4); 

	printf("\n\t\tPrincípios de Programação Procedimental\n");
   	printf("\n - Maria Filipa Serra Ferreira Rosa, 2012146116\n");
 	printf("\n - Rita Maria Faria Almeida, 2012169259\n\n");

	menuInicial(&doente, &vermelha, &amarela, &verde, &geral);
	return 0;
}