#include <stdio.h>
#include <stdlib.h>

#include "../include/components.h"



void menu(void){

    system("cls");

    printf("-----------------------------------\n");
    printf("          Matriz Esparsa:          \n");
    printf("-----------------------------------\n");

}

int Inserir_Elemento(Elemento* *vet_lin, int N, Elemento* *vet_col, int M, Elemento el){

    Elemento *no = (Elemento *) malloc(sizeof(Elemento));

    if(no == NULL){
        printf("Nao foi possivel alocar memoria para o novo elemento!\n");
        return 0;
    }

    (*no).lin = el.lin;
    (*no).col = el.col;
    (*no).valor = el.valor;

    //Lidando com os ligamentos da linha:

    //Esta linha ainda nao possui elementos:
    if(vet_lin[el.lin] == NULL){

        vet_lin[el.lin] = no;

        (*no).prox_lin = NULL;

    //Esta linha ja possui elementos:
    }else{

        Elemento *ant;
        Elemento *atual = vet_lin[el.lin];

        while(atual != NULL && (*atual).col < (*no).col){
            ant = atual;
            atual = (*atual).prox_col;
        }

        if((*ant).col == (*no).col || (*atual).col == (*no).col){
            printf("Posicao ja ocupada!\n");
            return 0;
        }

        //Se isso acontecer significa que nem entramos no while, o novo no deve ser inserido antes de todos os outros:
        if(atual == vet_lin[el.lin]){ // INSERÇÃO NO COMEÇO:

            (*no).prox_lin = vet_lin[el.lin];

            vet_lin[el.lin] = no;

        }else if(atual == NULL){// INSERÇÃO NO FINAL:

            (*ant).prox_lin = no;

            (*no).prox_lin = NULL;

        }else if((*atual).col > (*no).col && (*ant).col < (*no).col){ // INSERÇÃO NO MEIO:

            (*ant).prox_col = no;

            (*no).prox_col = atual;
        }

        //Lidando com os ligamentos da coluna:

        //Se a coluna nao possuir elementos:
        if(vet_col[el.col] == NULL){

            vet_col[el.col] = no;

            (*no).prox_col = NULL;

        //Caso ja houverem elementos:
        }else{

            Elemento *antt;
            Elemento *atuall = vet_col[el.col];

            while(atuall != NULL && (*atuall).lin < (*no).lin){

                antt = atuall;
                atuall = (*atuall).prox_lin;

            }


            if((*antt).lin == (*no).lin || (*atuall).lin == (*no).lin){
                printf("Posicao ja ocupada!\n");
                return 0;
            }

            //Se isso acontecer significa que nem entramos no while, o novo no deve ser inserido antes de todos os outros:
            if(atuall == vet_col[el.col]){ // INSERÇÃO NO COMEÇO:

                (*no).prox_col = vet_col[el.col];

                vet_col[el.col] = no;



            }else if(atuall == NULL){// INSERÇÃO NO FINAL: //atual apontando para NULL e antt apontando para o ultimo elemento da coluna:

                (*antt).prox_col = no;
                (*no).prox_col = NULL;



            }else if((*atuall).lin > (*no).lin && (*antt).lin < (*no).lin){ //INSERÇÃO NO MEIO:

                (*antt).prox_col = no;

                (*no).prox_col = atuall;


            }

        }



    }


    return 1;

}



int Mostrar_Matriz(Elemento** vet_lin, int N, Elemento** vet_col, int M){

    Elemento *aux;

    for(int i = 0; i < N; ++i){

        aux = vet_lin[i];

        if(aux == NULL){

            for(int j = 0; j<M; ++j){
                printf("0 ");
            }

        }else{

            for(int j = 0; j < M; ++j){
                if(aux != NULL){
                    if(j == (*aux).col){
                        printf("%d ", (*aux).valor);
                        aux = (*aux).prox_lin;
                    }else{
                        printf("0 ");
                    }
                }else{
                    printf("0 ");
                }
            }
        }

        printf("\n");

    }

    return 1;
}




