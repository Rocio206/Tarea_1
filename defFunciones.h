#ifndef defFunciones_h
#define defFunciones_h 
#include "list.h"

typedef struct{          // Corresponde a la estructura de cada lista
    int cantidadCanciones;       
    List* ListaReprod;
    char* NombreList;
} Reproduccion;

typedef struct{         // Estructura que guarda la infromación de cada canción
    char* Nombre;
    char* Artista;
    char* Genero;
    char* year;
    char* NombreLista;
} Cancion;

typedef struct{          // Es la estructura que guarda cada lista creada.
    int cantidadListas;   // cantidad de listas guardadas
    List *ListaGeneral;   // Guarda las listas de reproducción creadas
    List *ListaCanciones; // Cada posición contiene la información de una lista
}   Biblioteca;

void ImprimirMenu(int op, int op2, Biblioteca* biblioteca);
void importar(FILE *archivo, Biblioteca* biblioteca);
void mostrarCanciones(List* listaCanciones);
void mostrarReproduccion(Biblioteca* biblioteca, char* nombreLista);
Reproduccion* existeReproduccion(Biblioteca* biblioteca, char* nombreList);
Biblioteca *crearBiblioteca();
Cancion* crearCancion();

void imprimirCancion(Cancion * lista);

void LlenarLista(Biblioteca *listGeneral, char *linea);
void guardarGenero(Biblioteca *listGeneral, const char *atributo);
void guardarLista(Biblioteca *listGeneral, const char *atributo);
//Reproduccion *buscarListDeRepro(Cancion *auxCanciones);
void obtenerGeneros(List * genero, const char *dato);
// const char *get_csv_field (char * tmp, int k)

void BuscarPorNombre(List* canciones);
void BuscarPorArtista(List* canciones);
void BuscarPorGenero(List* canciones);


void AgregarCancion(Biblioteca* biblioteca);
int cancionExiste(char* buscada,List* canciones);

void EliminarCancion(Biblioteca* biblioteca);



#endif