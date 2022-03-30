#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "defFunciones.h"


void imprimirCancion(Cancion* a){
    printf("------------------------------------------------\n");

    printf("Nombre : %s \n", a->Nombre);
    printf("Artista : %s \n", a->Artista);
    printf("Genero : %s \n", a->Genero);
    printf("Anyo : %s \n", a->year);
    printf("Lista : %s \n", a->NombreLista);

    return;
}

void ImprimirMenu(int op, int op2)
{
    printf("opcion 1. Agregar Cancion\n");
    printf("opcion 2. Buscar Cancion\n");
    printf("opcion 3. Eliminar Cancion\n");
    printf("opcion 4. Mostrar Nombres Listas\n");
    printf("opcion 5. Mostrar Lista\n");
    printf("opcion 6. Mostrar todas las Canciones\n");
    scanf("%d", &op);

    switch(op)
    {
        case 1:
            printf("Función en proceso\n");
            break; 
        case 2:
            printf("opcion 1. Nombre\n");
            printf("opcion 2. Artista\n");
            printf("opcion 3. Genero\n");
            scanf("%d", &op2);
            switch(op2)
            {
                case 1:
                    printf("Ingrese el nombre: ");
                    // BuscarPorNombre(General);
                    break;
                case 2:
                    printf("Ingrese el artista: ");
                    break;
                case 3:
                    printf("Ingrese el genero: ");
                    break;
            }
            break;
        case 3:
            printf("Función en proceso\n");
            break;
        case 4:
            printf("Función en proceso\n");
            break;
        case 5:
            printf("Función en proceso\n");
            break;
        case 6:
            printf("Función en proceso\n");
            break;
        break;
    }

}


void importar(FILE *archivo, Reproduccion* listaGlobal)
{
    int i;
    int k = 0;
    char linea[1024];

    while (fgets(linea, 1024, archivo) != NULL) {

        Cancion* aux = (Cancion *) malloc(sizeof(Cancion));

        strcpy(aux->Nombre, get_csv_field(linea, 0));
        strcpy(aux->Artista,get_csv_field(linea, 1)); 
        strcpy(aux->Genero, get_csv_field(linea, 2)) ;
        strcpy(aux->year, get_csv_field(linea, 3));  
        strcpy(aux->NombreLista, get_csv_field(linea, 4)); 

        pushFront(listaGlobal->ListaReprod, aux);
        listaGlobal->cantidadCanciones += 1;
        if (k < 5) imprimirCancion(aux);
        k++;
    }
    
    fclose(archivo);
    //return listGeneral;
}

const char *get_csv_field (char * tmp, int k) {
    int open_mark = 0;
    char *ret = (char *) malloc (150 * sizeof(char));
    int ini_i = 0, i = 0, j = 0;
    while(tmp[i+1] != '\0'){

        if(tmp[i] == '\"'){
            open_mark = 1 - open_mark;
            if(open_mark) ini_i = i + 1;
            i++;
            continue;
        }

        if(open_mark || tmp[i] != ','){
            if(k == j) ret[i-ini_i] = tmp[i];
            i++;
            continue;
        }

        if(tmp[i] == ','){
            if(k == j) {
               ret[i-ini_i] = 0;
               return ret;
            }
            j++; ini_i = i + 1;
        }
        i++;
    }

    if(k == j){

        i = i - 1;
        for (i; tmp[i] != '\0'; i++)
        {
            ret[i - ini_i] =  tmp[i];
        }
       ret[i - ini_i] = 0;
       return ret;
    }
    return NULL;
}

/*void obtenerGeneros(List * genero, const char *dato){
    printf("Aun no se crea esta funcion");
}


void LlenarLista(Biblioteca *listGeneral, char *linea)

{
    // for(int i = 0; i < 5; i++)
    // {
    //     const char *atributo = get_csv_field(linea, i);
    //     if(i == 0)
    //         strcpy(listGeneral -> cancion -> Nombre, atributo);
    //     else if (i == 1)
    //         strcpy(listGeneral -> cancion -> Artista, atributo);
    //     else if (i == 2)
    //         guardarGenero(listGeneral, atributo);
    //     else if(i == 3)
    //         listGeneral -> cancion -> year = atributo;
    //     else
    //         guardarLista(listGeneral,atributo);
    // }
}



void guardarLista(Biblioteca *lista, const char *atr)
{
    printf("Aun no se crea esta funcion");
}

/*
void BuscarPorNombre(Biblioteca *lista, List* canciones){
    char *cancionBuscada;
    scanf("%s", cancionBuscada);
    Canciones *cancion = firstList(canciones);
    int flag = 0;
    
    while(cancion != NULL){        
        if(strcmp(cancion -> Nombre, cancionBuscada)==0){
            printf("Nombre: %s", cancion -> Nombre);
            printf("Artista: %s", cancion -> Artista);
            printf("Genero: %s", cancion -> Genero);
            printf("Año: %s", cancion -> year);
            printf("Lista de: %s", cancion -> Lista);
            flag = 1;            
            break;
        }
        cancion = nextList(canciones);
    }
    if (flag == 0)
        printf("La cancion buscada no se encuentra");
}
*/ 