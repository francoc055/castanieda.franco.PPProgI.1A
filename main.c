#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 20
#define TAM_N 5

typedef struct{
int id;
char procesador[20];
char marca[20];
float precio;
}Notebook;

int aplicarDescuento (int producto);
int contarCaracteres (char cadena[TAM], int tam, char caracter);
int ordenarXmarca(Notebook vec[], int tam);
int main()
{
    //punto 1;
    printf("%d", aplicarDescuento(100));

    //punto 2
    contarCaracteres("perro", TAM, 'r');

    //punto 3
    Notebook arrayN[TAM_N] ={
        {1, "core i3", "intel", 20000},
        {2, "core i5", "intel", 21000},
        {3, "core i7", "intel", 22000},
        {4, "core i9", "intel", 25000},
        {5, "core duo", "intel", 100000}
        };


        for(int i = 0; i < TAM_N; i++)
        {
            printf("%d\t %s\t %s\t %f\n", arrayN[i].id, arrayN[i].procesador, arrayN[i].marca, arrayN[i].precio);
        }

        printf("\n\n");


        ordenarXmarca(arrayN, TAM_N);

        for(int i = 0; i < TAM_N; i++)
        {
            printf("%d\t %s\t %s\t %f\n", arrayN[i].id, arrayN[i].procesador, arrayN[i].marca, arrayN[i].precio);
        }
    return 0;
}

int aplicarDescuento (int producto)
{
    int porcentaje = 5;
    int descuento;
    int total;

    descuento = producto * porcentaje / 100;

    total = producto - descuento;

    return total;
}

int contarCaracteres (char cadena[TAM], int tam, char caracter)
{
    int ret = 1;
    int contador = 0;
    if(cadena != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(cadena[i] == caracter)
            {
                contador++;
            }
        }
        if(contador > 0)
        {
            printf("cantidad de veces que aparece el caracter %c: %d", caracter, contador);
        }
        else
        {
            printf("no aparace el caracter %c en la cadena %s", caracter, cadena);
        }
        ret = 1;
    }
    return ret;
}




int ordenarXmarca(Notebook vec[], int tam)
{
    int ret = 0;
    Notebook auxNotebook;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam - 1; i++)
        {
            for(int j = i+1; j < tam; j++)
            {
                if(strcmp(vec[i].marca, vec[j].marca) > 0
                   || vec[i].precio > vec[j].precio);
                {
                    auxNotebook = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxNotebook;
                }
            }
        }
        ret = 1;
    }
    return ret;
}
