// aquí se definen.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List *lista = (List *) calloc(1,sizeof(List));
    lista -> head = NULL;
    lista -> tail = NULL;
    lista -> current = NULL;
    return lista;
}

void * firstList(List * list) {
    if(list -> head && list -> head -> data){
      list -> current = list -> head;
      return list -> head -> data;
    }
    return NULL;
}

void * nextList(List * list) {
    if(list -> current && list -> current -> next){
      list -> current = list -> current -> next;
      return list -> current -> data;
    }
    return NULL;
}

void * lastList(List * list) {
    if(list -> tail && list -> tail -> data){
      list -> current = list -> tail;
      return list -> tail -> data;
    }
    return NULL;
}

void * prevList(List * list) {
    if(list -> current && list -> current -> prev){
      list -> current = list -> current -> prev;
      return list -> current -> data;
    }
    return NULL;
}

void pushFront(List * list, void * data) {
    Node *nodo = createNode(data);
    nodo -> next = list -> head;
    if (list -> head)
      list -> head -> prev = nodo;
    else
      list -> tail = nodo;
    list -> head = nodo;
    nodo -> prev = NULL;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    Node *nodo = createNode(data);
    if(list == NULL){
      list -> head = nodo;
      list -> tail = nodo;
    }
    else{
      if(list -> current == list -> tail){
        list -> current -> next = nodo;
        nodo -> prev = list -> current;
        list -> tail = nodo;
      }
      else{
        nodo -> next = list -> current -> next;
        list -> current -> next -> prev = nodo;
        nodo -> prev = list -> current;
        list -> current -> next = nodo;
      }
    }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    Node *aux = list -> current;
    void *auxData = aux-> data;
    if(list == NULL){
      list -> head = NULL;
      list -> tail = NULL;
      list -> current = NULL;
    }
    else if(list -> current == list -> head){
      list -> head = list -> current -> next;
      list -> current -> next -> prev = NULL;
      list -> current = list -> head;
    }
    else if(list -> current == list -> tail){
      list -> tail = list -> current -> prev;
      list -> current -> prev -> next = NULL;
      list -> current = list -> tail;
    }
    else{
      list -> current -> prev -> next = list -> current -> next;
      list -> current -> next -> prev = list -> current -> prev;
      list -> current = list -> current -> next;
      
    }
    free(aux);
    return auxData;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}