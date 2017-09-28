#include "header.h"

void escreve_ficheiros(D lista, int tipo){
	/*0: Doentes  1:Pulseiras vermelhas  2: Pulseiras amarelas  3: Pulseiras verdes  4:Geral */
	D actual = lista->next;
    FILE *fich;

    switch(tipo){
        case 0:
            fich = fopen("doentes.txt","w+");
            break;
        case 1:
            fich = fopen("pulseiras_vermelhas.txt","w+");
            break;
        case 2:
            fich = fopen("pulseiras_amarelas.txt","w+");
            break;
        case 3:
            fich = fopen("pulseiras_verdes.txt","w+");
            break;
        case 4:
        	fich = fopen("geral.txt", "w+");
        	break;
        default:
            printf("ERRO. Não foram gerados ficheiros.");
            break;
    }

    while(actual){
        fprintf(fich,"%s\n%d\n%d\n%d\n%d\n%d\n%d\n", actual->nome, actual->bi, actual->registo.dia, actual->registo.mes, actual->registo.ano, actual->registo.hora, actual->registo.minutos);
        actual = actual->next;
    }
    fclose(fich);
}

void le_ficheiros(D* lista, int tipo){
    /*0: Doentes  1:Pulseiras vermelhas  2: Pulseiras amarelas  3: Pulseiras verdes  4:Geral */
    FILE *fich;
    char *line = (char*) malloc(MAX*sizeof(char));
    char nome[MAX];
    int bi;
    Data date;

    switch(tipo){
        case 0:
            fich = fopen("doentes.txt","r");
            break;
        case 1:
            fich = fopen("pulseiras_vermelhas.txt","r");
            break;
        case 2:
            fich = fopen("pulseiras_amarelas.txt","r");
            break;
        case 3:
            fich = fopen("pulseiras_verdes.txt","r");
            break;
        case 4:
            fich = fopen("geral.txt", "r");
            break;
        default:
            printf("ERRO. A leitura foi mal efetuada.\n");
            break;
    }

    if(fich!=NULL){
        while(fgets(line, MAX, fich)!=NULL){
            line[strlen(line)-1]='\0';
            strcpy(nome,line);
            fgets(line, MAX, fich);
            bi = atoi(line);

            fgets(line, MAX, fich);
            date.dia = atoi(line);
            fgets(line, MAX, fich);
            date.mes = atoi(line);
            fgets(line, MAX, fich);
            date.ano = atoi(line);
            fgets(line, MAX, fich);
            date.hora = atoi(line);
            fgets(line, MAX, fich);
            date.minutos = atoi(line);

            insere_doente_lista(lista, nome, bi, date);
        }
    }
}