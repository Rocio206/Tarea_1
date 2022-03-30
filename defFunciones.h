#ifndef defFunciones_h
#define defFunciones_h 
#include "list.h"

typedef struct{          // Corresponde a la estructura de cada lista
    int cantidadCanciones;       
    List *ListaReprod;
    char NombreList[35];
} Reproduccion;

typedef struct{         // Estructura que guarda la infromación de cada canción
    char Nombre[35];
    char Artista[35];
    char Genero[35];
    char year[4];
    char NombreLista[35];
} Cancion;

typedef struct{          // Es la estructura que guarda cada lista creada.
    int cantidadListas;   // cantidad de listas guardadas
    List *ListaGeneral;   // Guarda las listas de reproducción creadas
    List *ListaCanciones; //Cada posición contiene la información de una lista
}   Biblioteca;

void ImprimirMenu(int op, int op2);
void importar(FILE *archivo, Reproduccion* biblioteca);
void LlenarLista(Biblioteca *listGeneral, char *linea);
void guardarGenero(Biblioteca *listGeneral, const char *atributo);
void guardarLista(Biblioteca *listGeneral, const char *atributo);
//Reproduccion *buscarListDeRepro(Cancion *auxCanciones);
Biblioteca *crearBiblioteca();
void obtenerGeneros(List * genero, const char *dato);

void imprimirCancion(Cancion * lista);

#endif