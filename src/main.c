#include <stdio.h>
#include <stdlib.h>

#include "../include/components.h"


int main (void){

    int N, M, op;

    menu();

    printf("  Qual o tamanho da matriz (nxm) ?\n");

    scanf("%d %d", &N, &M);


    Elemento* vet_lin[N];

    for(int i = 0; i<N; ++i)
        vet_lin[i] = NULL;


    Elemento* vet_col[M];

    for(int i = 0; i<M; ++i)
        vet_col[i] = NULL;

    Elemento elemento;

    do{
        menu();

        printf("1 - Inserir elemento:\n");
        printf("2 - Mostrar a matriz.\n");
        printf("3 - Sair e limpar a memoria.\n");

        scanf("%d", &op);

        switch(op){
            case 1:

                menu();

                do{
                    system("cls");
                    printf("Posicao de insercao - i, j :\n");
                    scanf("%d %d", &elemento.lin, &elemento.col);

                    if(elemento.lin >= N || elemento.lin < 0 || elemento.col >= M || elemento.col < 0){
                        printf("Insira uma posicao valida!\n");
                        system("pause");
                    }

                }while(elemento.lin >= N || elemento.lin < 0 || elemento.col >= M || elemento.col < 0);

                printf("Valor:\n");
                scanf("%d", &elemento.valor);

                if(Inserir_Elemento(vet_lin, N, vet_col, M, elemento)){
                    printf("Elemento inserido com sucesso!\n");
                }else{
                    printf("Nao foi possivel inserir o elemento!\n");
                }

                system("pause");

                break;

            case 2:

                Mostrar_Matriz(vet_lin, N, M);

               system("pause");

                break;

            default:

                Liberar_Memoria(vet_lin, N, M);

                break;
        }
    }while(op != 3);




    return 0;
}
