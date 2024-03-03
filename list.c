/* Implementação do TAD Lista simplesmente encadeada */
#ifndef _LIST_C
#define _LIST_C

#define TRUE 1
#define FALSE 0
#include <list.h> /* inclui a especificacao do TAD LISTA */
#include <stdlib.h>

SLList * sllCreate( void ) {
    SLList *l;
    l = (SLList * ) malloc(sizeof(SLList ));
    if ( l != NULL ) {
        l->first = NULL;
        return l;
    }
    return NULL;
} // Fim de sllCreate

int sllDestroy ( SLList *l) {
    if ( l != NULL ) {
        if ( l->first == NULL ) {
            free (l);
            return TRUE;
        }
    }
    return FALSE;
} // Fim de sllDestroy

int sllIsEmpty ( SLList *l){
    if ( l != NULL){
        if(l->first != NULL) {
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
} // Fim de sllIsEmpty

int sllLength ( SLList *l){
    if ( l != NULL){
        if(l->first != NULL) {
            int sllLen = 1;
            SLNode *cur = (SLNode *) l->first;
            while(cur->next != NULL){
                sllLen++;
                cur = (SLNode *) cur->next;
            }
            return sllLen;
        }
        return 0;
    }
    return 0;
} // Fim de sllIsEmpty

int sllInsertAsFirst( SLList *l, void *data) {
    if ( l != NULL) {
        SLNode* newnode;
        newnode = (SLNode*) malloc(sizeof(SLNode));
        if ( newnode != NULL) {
            newnode->data = data;
            newnode->next = l->first;
            l->first = (struct SLNode *) newnode;
            return TRUE;
        }
    }
    return FALSE;
} // Fim de sllInsertAsFirst

int sllInsertAsLast( SLList *l, void *data){
    SLNode *newnode; SLNode *last;
    if ( l != NULL ) {
        newnode = ( SLNode *) malloc(sizeof(SLNode));
        if ( newnode != NULL) {
            newnode->data = data;
            newnode->next = NULL;
            if( l->first == NULL) {
                l->first = (struct SLNode *) newnode;
            } else {
                last = (SLNode *) l->first;
                while (last->next != NULL) {
                    last = (SLNode *) last->next;
                }
                last->next = (struct SLNode *) newnode;
            }
            return TRUE;
        }
    }
    return FALSE;
} // Fim de sllInsertAsLast

int sllInsertAfterSpec( SLList *l, void *key, int (*cmp)(void *, void *), void *data) {
    SLNode *spec, *newnode; int stat;
    if (l != NULL) {
        if (l->first != NULL) {
            spec = (SLNode *) l->first;
            stat = cmp(spec->data, key);
            while (stat != TRUE && spec->next != NULL) {
                spec = (SLNode *) spec->next;
                stat = cmp(spec->data, key);
            }
            if (stat == TRUE) {
                newnode = (SLNode *) malloc(sizeof(SLNode));
                if (newnode != NULL) {
                    newnode->data = data;
                    newnode->next = spec->next;
                    spec->next = (struct SLNode *) newnode;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}// Fim de sllInsertAfterSpec

int sllInsertBeforeSpec( SLList *l, void *key, int (*cmp)(void *, void *data), void* data) {
    SLNode *spec, *prev, *newnode; int stat;
    if (l != NULL) {
        if (l->first != NULL) {
            spec = (SLNode *) l->first;
            prev = NULL;
            stat = cmp(spec->data, key);
            while (spec->next != NULL && stat != TRUE) {
                prev = spec;
                spec = (SLNode *) spec->next;
                stat = cmp(spec->data, key);
            }
            if (stat == TRUE) {
                newnode = (SLNode *) malloc(sizeof(SLNode));
                if (newnode != NULL) {
                    newnode->data = data;
                    newnode->next = (struct SLNode *) spec;
                    if (prev != NULL) {
                        prev->next = (struct SLNode *) newnode;
                    } else {
                        l->first = (struct SLNode *) newnode;
                    }
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}// Fim de sllInsertAfterSpec

void *sllRemoveFirst ( SLList *l) {
    SLNode *first; void *data;
    if ( l != NULL) {
        if ( l->first != NULL ) { //Se a lista não esta vazia
            first = (SLNode *) l->first;
            data = first->data;
            l->first = first->next;
            free(first);
            return data;
        }
    }
    return NULL;
} // Fim de sllRemoveFirst

void *sllRemoveLast( SLList *l) {
    SLNode *last, *prev; void *data;
    if ( l != NULL) {
        if ( l->first != NULL ) {
            last = (SLNode *) l->first;
            while (last->next != NULL) {
                prev = last;
                last = (SLNode *) last->next;
            }
            data = last->data;
            prev->next = NULL;
            free(last);
            return data;
        }
    }
    return NULL;
} // Fim de sllRemoveLast

void *sllRemoveSpec( SLList *l, void *key, int (*cmp)(void *, void *)){
    SLNode *spec, *prev; void *data; int stat;
    if (l != NULL) {
        if (l->first != NULL) {
            spec = (SLNode *) l->first;
            prev = NULL;
            stat = cmp(spec->data, key);
            while (spec->next != NULL && stat != TRUE) {
                prev = spec;
                spec = (SLNode *) spec->next;
                stat = cmp(spec->data, key);
            }
            if (stat == TRUE) {
                data = spec->data;
                if(prev != NULL){
                    prev->next = spec->next;
                    free(spec);
                } else {
                    l->first = spec->next;
                    free(spec);
                }
                return data;
            }
        }
    }
    return FALSE;
}// Fim de sllRemoveSpec

void *sllRemoveAfterSpec( SLList *l, void *key, int (*cmp)(void *, void *)){
    SLNode *spec, *nextNode; void *data; int stat;
    if (l != NULL) {
        if (l->first != NULL) {
            spec = (SLNode *) l->first;
            stat = cmp(key, spec->data);
            while (stat != TRUE && spec->next != NULL) {
                spec = (SLNode *) spec->next;
                stat = cmp(key, spec->data);
            }
            if (stat == TRUE) {
                if(spec->next != NULL){
                    nextNode = (SLNode *) spec->next;
                    spec->next = nextNode->next;
                    data = nextNode->data;
                    free(nextNode);
                    return data;
                }
            }
        }
    }
    return NULL;
}// Fim de sllRemoveAfterSpec

void *sllRemoveBeforeSpec( SLList *l, void *key, int (*cmp)(void *, void *data)) {
    SLNode *spec, *prev, *prevPrevNode; void *data; int stat;
    if (l != NULL) {
        if (l->first != NULL) {
            spec = (SLNode *) l->first;
            prev = NULL;
            prevPrevNode = NULL;
            stat = cmp(spec->data, key);
            while (spec->next != NULL && stat != TRUE) {
                prevPrevNode = prev;
                prev = spec;
                spec = (SLNode *) spec->next;
                stat = cmp(spec->data, key);
            }
            if (stat == TRUE) {
                if(prev != NULL){
                    if (prevPrevNode != NULL){
                        prevPrevNode->next = (struct SLNode *) spec;
                    } else {
                        l->first = (struct SLNode *) spec;
                    }
                    data = prev->data;
                    free(prev);
                    return data;
                }
            }
        }
    }
    return FALSE;
}// Fim de sllRemoveBeforeSpec

void *sllQuery( SLList *l, void *key, int (*cmp)(void *, void *)){
    SLNode *spec; void *data; int stat;
    if (l != NULL) {
        if (l->first != NULL) {
            spec = (SLNode *) l->first;
            stat = cmp(spec->data, key);
            while (spec->next != NULL && stat != TRUE) {
                spec = (SLNode *) spec->next;
                stat = cmp(spec->data, key);
            }
            if (stat == TRUE) {
                data = spec->data;
                return data;
            }
        }
    }
    return NULL;
}// Fim de sllQuery

void *sllGetFirst( SLList *l){
    SLNode *first; void *data;
    if ( l != NULL) {
        if ( l->first != NULL ) { //Se a lista não esta vazia
            first = (SLNode *) l->first;
            data = first->data;
            return data;
        }
    }
    return NULL;
} // Fim de sllGetFirst

void *sllGetNext(SLList *l, void *key, int (*cmp)(void *, void *)){
    int stat; SLNode *spec; void *data;
    if ( l != NULL) {
        if ( l->first != NULL ) { //Se a lista não esta vazia
            spec = (SLNode *) l->first;
            stat = cmp(key, spec->data);
            while (stat != TRUE && spec->next != NULL) {
                spec = (SLNode *) spec->next;
                stat = cmp(key, spec->data);
            }
            if (stat == TRUE) {
                data = spec->next;
                return data;
            }
        }
    }
    return NULL;
} // Fim de sllGetNext

#endif //_LIST_C