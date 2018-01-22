/* 
 * File:   ArvoreBinariaDeBusca.h
 * Author: ubuntu
 *
 * Created on 7 de Novembro de 2009, 19:47
 */

#ifndef _ARVOREBINARIADEBUSCA_H
#define	_ARVOREBINARIADEBUSCA_H
#include "NoAB.h"
#include <iostream>
using namespace std;

class ArvoreBinariaDeBusca {
public:
    ArvoreBinariaDeBusca();
    ArvoreBinariaDeBusca(Chave idRaiz, Informacao infoRaiz, NoABB* subArvEsq, NoABB* subArvDir);
    virtual ~ArvoreBinariaDeBusca();
    bool find(Chave idProcurado, Informacao& valorRetorno);
    bool insert(Chave idPosicao, Informacao valorNovo);
    bool remove(Chave idPosicao);
    void imprime();
private:
    NoABB *Raiz;
    bool insereABB(Chave idPosicao, Informacao valorNovo, NoABB*& ptr);
    int buscaABB(Chave idProcurado, NoABB*& ptr);
    bool removeABB(Chave idPosicao, NoABB*& ptr);
    void localizaMin(NoABB*& ptr);
    void imprimeArv(int nivel, NoABB* ptr);

};

#endif	/* _ARVOREBINARIADEBUSCA_H */

