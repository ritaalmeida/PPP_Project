#include "header.h"

int contav=0, contaa=0;

void voltarMenuOuSair(D* doente, D*vermelha, D* amarela, D* verde, D* geral){
	char opcao;

	escreve_ficheiros(*doente,0);
	escreve_ficheiros(*vermelha,1);
	escreve_ficheiros(*amarela,2);
	escreve_ficheiros(*verde,3);
	escreve_ficheiros(*geral,4); 

	printf("Escolha uma das seguintes opções: \n");
	printf("1-> Voltar ao menu inicial\n");
	printf("2-> Sair\n");
	printf("Opção: ");
	scanf(" %c", &opcao);
	
	switch(opcao){
		case '1':
			system("clear");
			menuInicial(doente, vermelha, amarela, verde, geral);
			break;

		case '2':
			system("clear");
			exit(0);

		default:
			system("clear");
			printf("ERRO: opção inexistente.\n\n");
			voltarMenuOuSair(doente, vermelha, amarela, verde, geral);
			break;
	}
}

void proximo_cliente(D* doente, D* vermelha, D* amarela, D* verde, D* geral){
	D lv = (*vermelha)->next;
	D la = (*amarela)->next;
	D lvd = (*verde)->next;
	D g = (*geral)->next;

	//SE HOUVER VERDES
	while(lista_vazia(*verde)==0){
		//SE HOUVER AMARELAS
		while(lista_vazia(*amarela)==0 && contaa<5){
			//SE HOUVER VERMELHAS
			while(lista_vazia(*vermelha)==0 && contav<3){	
				printf("----------------");
				printf("\n Nome:%s\n BI:%d\n Data: %d/%d/%d\n Hora: %dh:%dm\n\n", lv->nome, lv->bi, lv->registo.dia, lv->registo.mes, lv->registo.ano, lv->registo.hora, lv->registo.minutos);
				contav+=1;
				eliminaListar(vermelha, doente, vermelha, amarela, verde, geral, lv->bi);
			}
		printf("----------------");
		printf("\n Nome:%s\n BI:%d\n Data: %d/%d/%d\n Hora: %dh:%dm\n\n", la->nome, la->bi, la->registo.dia, la->registo.mes, la->registo.ano, la->registo.hora, la->registo.minutos);
		contaa+=1;
		contav=0;
		eliminaListar(amarela, doente, vermelha, amarela, verde, geral, la->bi);
		}

		//NO CASO DE NAO HAVER AMARELAS, MAS EXISTIREM VERDES E VERMELHAS
		while(lista_vazia(*amarela)!=0){
			while(lista_vazia(*vermelha)==0 && contav<15){
				printf("Imprime\n Nome:%s\n BI:%d\n Data: %d/%d/%d\n Hora: %dh:%dm\n\n", lv->nome, lv->bi, lv->registo.dia, lv->registo.mes, lv->registo.ano, lv->registo.hora, lv->registo.minutos);
				contav+=1;
				eliminaListar(vermelha, doente, vermelha, amarela, verde, geral, lv->bi);
			}

			printf("----------------");
			printf("\n Nome:%s\n BI:%d\n Data: %d/%d/%d\n Hora: %dh:%dm\n\n", lvd->nome, lvd->bi, lvd->registo.dia, lvd->registo.mes, lvd->registo.ano, lvd->registo.hora, lvd->registo.minutos);
			contaa=0;
			contav=0;
			eliminaListar(verde, doente, vermelha, amarela, verde, geral, lvd->bi);
		}

	printf("----------------");
	printf("\n Nome:%s\n BI:%d\n Data: %d/%d/%d\n Hora: %dh:%dm\n\n", lvd->nome, lvd->bi, lvd->registo.dia, lvd->registo.mes, lvd->registo.ano, lvd->registo.hora, lvd->registo.minutos);
	contaa=0;
	contav=0;
	eliminaListar(verde, doente, vermelha, amarela, verde, geral, lvd->bi);
	}
	
	//SE NAO HOUVER VERDES
	while(lista_vazia(*amarela)==0){
		while(lista_vazia(*vermelha)==0 && contav<3){	
			printf("----------------");
			printf("\n Nome:%s\n BI:%d\n Data: %d/%d/%d\n Hora: %dh:%dm\n\n", lv->nome, lv->bi, lv->registo.dia, lv->registo.mes, lv->registo.ano, lv->registo.hora, lv->registo.minutos);
			contav+=1;
			eliminaListar(vermelha, doente, vermelha, amarela, verde, geral, lv->bi);
		}

		printf("----------------");
		printf("\n Nome:%s\n BI:%d\n Data: %d/%d/%d\n Hora: %dh:%dm\n\n", la->nome, la->bi, la->registo.dia, la->registo.mes, la->registo.ano, la->registo.hora, la->registo.minutos);
		contaa+=1;
		contav=0;
		eliminaListar(amarela, doente, vermelha, amarela, verde, geral, la->bi);
	}

	//SE NAO HOUVER VERDES NEM AMARELAS
	while(lista_vazia(*vermelha)==0 && contav<3){
		printf("----------------");
		printf("\n Nome:%s\n BI:%d\n Data: %d/%d/%d\n Hora: %dh:%dm\n\n", lv->nome, lv->bi, lv->registo.dia, lv->registo.mes, lv->registo.ano, lv->registo.hora, lv->registo.minutos);
		contav+=1;
		eliminaListar(vermelha, doente, vermelha, amarela, verde, geral, lv->bi);	
	}

}

void eliminaListar(D* lista,D* doente, D* vermelha, D*amarela, D* verde, D* geral, int cc){

	char opcao;
	printf("Pretende eliminar o doente que listou?\n1-> Sim\n2-> Não\n");
	printf("Opção: ");
	scanf(" %c", &opcao);

	switch(opcao){
		case '1':
			system("clear");
			elimina_doente_lista_sresposta(lista, cc);
			elimina_doente_lista_sresposta(geral, cc);
			voltarMenuOuSair(doente, vermelha, amarela, verde, geral);
			break;

		case '2':
			system("clear");
			voltarMenuOuSair(doente, vermelha, amarela, verde, geral);
			break;

		default:
			system("clear");
			printf("ERRO: opção inexistente.\n\n");
			eliminaListar(lista, doente, vermelha, amarela, verde, geral, cc);
			break;
	}
}

int lista_vazia(D lista){
	return (lista->next == NULL ? 1 : 0);
}


D cria_lista(int num){
	D aux;
	aux = (D) malloc (sizeof(Doente));
	if(aux!=NULL){
		aux -> nome=NULL;
		aux -> bi=0;
		aux->registo.dia = 0;
		aux->registo.mes = 0;
		aux->registo.ano = 0;
		aux->registo.hora = 0;
		aux->registo.minutos = 0;
		aux -> numlista=num;
		aux -> next=NULL;
	}
	return aux;
}

D procura_lista(D lista, char* name, int cc, Data d, D* ant, D* actual){
	*ant = lista;
	*actual = lista->next;
	while((*actual)!= NULL){
		*ant = *actual;
		*actual = (*actual)->next;
	}
	
	if((*actual)!= NULL)
		*actual = NULL; /*Se elmento nao encontrado*/

	return *actual;
}

D insere_doente_lista(D* lista,char *name, int cc, Data d){
	D ant, actual;
	D novo;
	novo = (D) malloc(sizeof(Doente));
	
	if(novo!=NULL && procura_lista(*lista,name,cc,d,&ant,&actual)==NULL){
	    novo->nome = (char*) malloc((strlen(name)+1)*sizeof(char));
        if(novo->nome != NULL){
        	strcpy(novo->nome,name);
        }
		novo->bi = cc;
		novo->registo=d;

		novo->next = actual;
		ant->next = novo;
	}

	else if (novo!=NULL && procura_lista(*lista,name,cc,d,&ant,&actual)!=NULL){
        novo = procura_lista(*lista,name,cc,d,&ant,&actual);

    }
	return novo;
}

D procura_lista_para_delete(D lista ,int cc, D* ant, D* actual){
	*ant = lista;
	*actual = lista->next;

	while((*actual)!= NULL && (*actual)->bi != cc){
		*ant = *actual;
		*actual = (*actual)->next;
	}
	return *actual;
}

void imprime_lista(D lista){
	D l = lista->next; /*Salta o header*/
	if(l==NULL){
		printf("\nNão existem mais doentes!\n\n");
	}
	while(l){
		printf("\n Nome:%s\n BI:%d\n Data: %d/%d/%d\n Hora: %dh:%dm\n\n", l->nome, l->bi, l->registo.dia, l->registo.mes, l->registo.ano, l->registo.hora, l->registo.minutos);
		l=l->next;
	}
}

void imprime_inversa_lista(D l){
	if(l->next==NULL){
		printf("\n Nome:%s\n BI:%d\n Data: %d/%d/%d\n Hora: %dh:%dm\n\n", l->nome, l->bi, l->registo.dia, l->registo.mes, l->registo.ano, l->registo.hora, l->registo.minutos);
	}
	
	else{
		imprime_inversa_lista(l->next);
		printf("\n Nome:%s\n BI:%d\n Data: %d/%d/%d\n Hora: %dh:%dm\n\n", l->nome, l->bi, l->registo.dia, l->registo.mes, l->registo.ano, l->registo.hora, l->registo.minutos);
	}

}

int verfica_bi_existe(D* lista, int cc){
    D aux;
    aux=(*lista)->next;

    while(aux!=NULL){
        if(aux->bi==cc){
            printf("ERRO: Doente já existente || (bi já utilizado)!\n");
            return 0;
        }
        aux=aux->next;
    }

    return 1;
}

int verifica_bi(int cc){
	int conta=0;
	
	while(cc!=0){
		conta++;
		cc/=10;
	}

	if(conta!=8){
		printf("ERRO: bi incorreto!\n");
		return 0;
	}
	else
		return 1;
}

int verifica_bi_alpha(char *str_bi){
	while(*str_bi!='\0'){
		if(isalpha(*str_bi) || ispunct(*str_bi)){
			printf("ERRO: bi inválido || (contém letras)!\n");
			return 0;
		}
        str_bi++;
	}
	return 1;
}

int verifica_nome(char *nome){
	while(*nome!='\0'){
		if(isdigit(*nome) || ispunct(*nome)){
			printf("ERRO: nome inválido!\n");
			return 0;
		}
        nome++;
	}
	return 1;
}


D pedirDados(D* doente, D* geral){
	D novo;
	char nome[MAX];
	int bi;
	char str_bi[MAX];

	Data data_system;

	time_t quando = time(NULL);
    struct tm *t = localtime(&quando);

    data_system.dia = t->tm_mday;
    data_system.mes = t->tm_mon+1;
    data_system.ano = t->tm_year+1900;
    data_system.hora = t->tm_hour;
    data_system.minutos = t->tm_min;

    do{
    	printf("Nome: ");
    	getchar();
    	fgets(nome, MAX, stdin);
    	nome[strlen(nome)-1]='\0';
    }
    while(verifica_nome(nome)==0);

	do{
		do{
			printf("\nNúmero de bilhete de identidade ou cartão de cidadão: ");
			//getchar();
    		fgets(str_bi, MAX, stdin);
    		str_bi[strlen(str_bi)-1]='\0';	
		}
		while(verifica_bi_alpha(str_bi)==0);
		bi = atoi(str_bi);
	}
	while((verfica_bi_existe(geral, bi)==0) || (verfica_bi_existe(doente, bi)==0) || (verifica_bi(bi)==0));

	printf("\nData: %d/%d/%d   Hora: %dh:%dm\n\n", (data_system).dia, (data_system).mes, (data_system).ano, (data_system).hora, (data_system).minutos);
	
	novo = insere_doente_lista(doente,nome,bi,data_system);

	return novo;
}

void elimina_doente_lista_sresposta(D* doente, int cc){ 
    D ant, actual;
    procura_lista_para_delete(*doente,cc,&ant, &actual);
    
    if(actual != NULL){
        ant->next = actual->next;
        free(actual);
    }
}

void elimina_doente_triagem(D* doente){ 
	int cc;
	D ant, actual;

	printf("Insira o número BI/CC do doente que deseja cancelar: \n");
	scanf(" %d",&cc);

    procura_lista_para_delete(*doente,cc, &ant, &actual);

    if(actual != NULL){
        ant->next = actual->next;
        free(actual);
        printf("\n\nDoente cancelado.\n\n");
    }
    else{
        printf("\n\nDoente inexistente.\n\n");
    }
}

void elimina_doente_lista_consulta(D* doente, int cc){ 
    D ant, actual;
    procura_lista_para_delete(*doente,cc, &ant, &actual);
    if(actual != NULL){
        ant->next = actual->next;
        free(actual);
        printf("\n\nDoente cancelado.\n\n");
    }
    else{
        printf("\n\nDoente inexistente.\n\n");
    }
}

D atribuirPulseira(D* doente, D* vermelha, D* amarela, D* verde, D* geral){
	char puls;
	D l= (*doente)->next;

	while(l){
		printf(" -----Doente-----");
		printf("\n Nome:%s\n BI:%d\n Data: %d/%d/%d\n Hora: %dh:%dm\n", l->nome, l->bi, l->registo.dia, l->registo.mes, l->registo.ano, l->registo.hora, l->registo.minutos);

		printf("\nQual a pulseira a atribuir: \n1-> Vermelha\n2-> Amarela\n3-> Verde\n");
		printf("Opção: ");
		scanf(" %c", &puls);

		switch(puls){
			case '1':
				system("clear");
				insere_doente_lista(geral, l->nome, l->bi, l->registo);
				insere_doente_lista(vermelha, l->nome, l->bi, l->registo);
				printf("Vermelha:\n");
				imprime_lista(*vermelha);
				elimina_doente_lista_sresposta(doente, l->bi);
				voltarMenuOuSair(doente, vermelha, amarela, verde, geral);
				break;

			case '2':
				system("clear");
				insere_doente_lista(geral, l->nome, l->bi, l->registo);
				insere_doente_lista(amarela, l->nome, l->bi, l->registo);
				printf("Amarela:\n");
				imprime_lista(*amarela);
				elimina_doente_lista_sresposta(doente, l->bi);
				voltarMenuOuSair(doente, vermelha, amarela, verde, geral);
				break;

			case '3':
				system("clear");
				insere_doente_lista(geral, l->nome, l->bi, l->registo);
				insere_doente_lista(verde, l->nome, l->bi, l->registo);
				printf("Verde:\n");
				imprime_lista(*verde);
				elimina_doente_lista_sresposta(doente, l->bi);			
				voltarMenuOuSair(doente, vermelha, amarela, verde, geral);
				break;

			default:
				system("clear");
				printf("ERRO: opção inexistente.\n\n");
				atribuirPulseira(doente, vermelha, amarela, verde, geral);
				break;
		}
	}
	return *doente;
}

void elimina_doente_consulta(D* doente, D* vermelha, D* amarela, D* verde, D* geral){

	char puls;
	printf("Insira a pulseira que o doente tem: \n1-> Vermelha\n2-> Amarela\n3-> Verde \n");
	printf("Opção: ");
	scanf(" %c",&puls);

	int cc;
	printf("Insira o número de BI/CC do doente que deseja cancelar: \n");
	scanf(" %d",&cc);

	switch(puls){
		case '1':
		    elimina_doente_lista_consulta(vermelha,cc);
		    elimina_doente_lista_sresposta(geral,cc);
		   	break;
		
		case '2':
			elimina_doente_lista_consulta(amarela,cc);
		    elimina_doente_lista_sresposta(geral,cc);
			break;

	    case '3':
	    	elimina_doente_lista_consulta(verde,cc);
		    elimina_doente_lista_sresposta(geral,cc);
			break;
			
		default:
			system("clear");
			printf("ERRO: opção inexistente.\n\n");
			elimina_doente_consulta(doente, vermelha, amarela, verde, geral);
			break;
	}
}

void listar_por_prioridade(D* doente, D* vermelha, D* amarela, D* verde){
	char puls;
	printf("Escolha a prioridade que quer listar:\n 0-> Espera para Triagem\n 1-> Vermelha\n 2-> Amarela\n 3-> Verde \n");
	printf("Opção: ");
	scanf(" %c",&puls);

	printf("\n\n");

	switch(puls){
		case '0':
			printf("----------------");
			imprime_lista(*doente);
			break;

		case '1':
			printf("----------------");
		    imprime_lista(*vermelha);
		   	break;
		
		case '2':
			printf("----------------");
			imprime_lista(*amarela);
			break;

	    case '3':
	    	printf("----------------");
	    	imprime_lista(*verde);
			break;
			
		default:
			system("clear");
			printf("ERRO: opção inexistente.\n\n");
			listar_por_prioridade(doente, vermelha, amarela, verde);
			break;
	}
}

void listar_geral(D* geral){
	printf("----------------");
	imprime_inversa_lista((*geral)->next);
}


