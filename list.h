/*------------------------------------------------
list.h
Arquivo com a especificacao para o TAD Lista
---------------------------------------------------
Componente curricular: Estrutura de Dados 1
Trabalho de Implementação 03 - TAD Lista
-------------------------------------------------*/
#ifndef LIST_H
#define LIST_H
/*-------------------------------------------------
Definicoes locais
-------------------------------------------------*/

typedef struct slnode_ {
    void *data;
    struct SLNode *next;
} SLNode;

typedef struct sllist_ {
    struct SLNode *first;
} SLList;

/*-------------------------------------------------
Funcoes que implementam as operacoes do TAD Lista
-------------------------------------------------*/

/* Cria um novo TAD Lista
Pos-condicao: retorna o endereço de um novo TAD Coleção
 vazio ou NULL se não conseguir criar*/
SLList * sllCreate( void );

/* Destroi um TAD Lista
Pre-condicao: (c é um TAD Coleção lista por uma chamada colCreate e que está vazio)
Pos-condicao: a memoria usada pelo TAD foi liberada*/
int sllDestroy ( SLList *l);

int sllIsEmpty ( SLList *l);

int sllLength ( SLList *l);

/* Adiciona um item na primeira posição da Lista
Pre-condicao : (c é um TAD Coleção criado por uma chamada sllCreate)
Pos-condicao: item foi adicionado ao TAD Lista*/
int sllInsertAsFirst(SLList *l, void *data);

int sllInsertAsLast( SLList *l, void *data);

int sllInsertAfterSpec( SLList *l, void *key, int (*cmp)(void *, void *), void *data);

int sllInsertBeforeSpec( SLList *l, void *key, int (*cmp)(void *, void *), void *data);

/* Remove o primeiro item da Lista
Pre-condicao : (c é um TAD Coleção criado por uma chamada sllCreate)
Pos-condicao: item foi adicionado ao TAD Lista*/
void *sllRemoveFirst ( SLList *l);

void *sllRemoveLast( SLList *l);

void *sllRemoveSpec( SLList *l, void *key, int (*cmp)(void *, void *));

void *sllRemoveAfterSpec( SLList *l, void *key, int (*cmp)(void *, void *));

void *sllRemoveBeforeSpec( SLList *l, void *key, int (*cmp)(void *, void *));

void *sllQuery( SLList *l, void *key, int (*cmp)(void *, void *));

void *sllGetFirst( SLList *l);

void *sllGetNext(SLList *l, void *key, int (*cmp)(void *, void *));

#else
extern SLList * sllCreate( void );
extern int sllDestroy ( SLList *l);
extern int sllIsEmpty ( SLList *l);
extern int sllLength ( SLList *l);
extern int sllInsertAsFirst(SLList *l, void *data);
extern int sllInsertAsLast( SLList *l, void *data);
extern int sllInsertAfterSpec( SLList *l, void *key, int (*cmp)(void *, void *), void *data);
extern int sllInsertBeforeSpec( SLList *l, void *key, int (*cmp)(void *, void *), void *data);
extern void *sllRemoveFirst ( SLList *l);
extern void *sllRemoveLast( SLList *l);
extern void *sllRemoveSpec( SLList *l, void *key, int (*cmp)(void *, void *));
extern void *sllRemoveAfterSpec( SLList *l, void *key, int (*cmp)(void *, void *));
extern void *sllRemoveBeforeSpec( SLList *l, void *key, int (*cmp)(void *, void *));
extern void *sllQuery( SLList *l, void *key, int (*cmp)(void *, void *));
extern void *sllGetFirst( SLList *l);
extern void *sllGetNext(SLList *l, void *key, int (*cmp)(void *, void *));
#endif //LIST_H

