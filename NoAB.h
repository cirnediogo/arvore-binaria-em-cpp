/* 
 * File:   NoAB.h
 * Author: ubuntu
 *
 * Created on 7 de Novembro de 2009, 18:47
 */

#ifndef _NOABB_H
#define	_NOABB_H
#include "Informacao.h"
#include "Chave.h"

typedef struct NoABB {
    Informacao info;
    Chave id;
    NoABB *esq;
    NoABB *dir;
};

#endif	/* _NOABB_H */

