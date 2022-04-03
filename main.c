#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "defFunciones.h"

//typedef struct Node Node;
//typedef List List;

int main()
{
    //importacion inicial
    FILE *archivo = fopen("Canciones.csv","r");
    if(archivo == NULL)
    {
        printf("No se pudo abrir el archivo");
        return(EXIT_FAILURE);
    }

    Biblioteca *biblioteca = crearBiblioteca();
    importar(archivo, biblioteca);
       
    
    
    int opcion;
    int opcion2;
    ImprimirMenu(opcion, opcion2, biblioteca);
        
    //mostrarCanciones(biblioteca->ListaCanciones);
    //mostrarReproduccion(biblioteca, "Lista 1");
    

    return 0;
}