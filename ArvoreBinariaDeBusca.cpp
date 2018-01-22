/* 
 * File:   ArvoreBinariaDeBusca.cpp
 * Author: ubuntu
 * 
 * Created on 7 de Novembro de 2009, 19:47
 */

#include "ArvoreBinariaDeBusca.h"

/** buscaABB
 * @param idProcurado
 * parâmetro do tipo Chave que indica qual nó deve ser pesquisado.
 * @param ptr
 * parâmetro do tipo NoABB que é passado como referência e será atualizado a cada vez que a busca se aproximar do nó dado.
 * @return
 * retorno do tipo int que retornará 0 se a árvore for vazia, 1 se a Chave existir na árvore, 2 se a posição da Chave for filho esquerdo do nó mais próximo da Chave, e 3 se a posição for filho direito.
 */
int ArvoreBinariaDeBusca::buscaABB(Chave idProcurado, NoABB*& ptr) {
    NoABB* ptNo = ptr;
    int f;
    if (ptNo == NULL) {
        f = 0;
    } else {
        if (idProcurado == ptNo->id) {
            f = 1;
        } else {
            if (idProcurado < ptNo->id) {
                f = 2;
                if (ptNo->esq != NULL) {
                    ptr = ptNo->esq;
                    f = buscaABB(idProcurado, ptr);
                }
            } else {
                f = 3;
                if (ptNo->dir != NULL) {
                    ptr = ptNo->dir;
                    f = buscaABB(idProcurado, ptr);
                }
            }
        }
    };
    return f;
}

/** find
 * @param idProcurado
 * parâmetro do tipo Chave que indica qual nó deve ser pesquisado.
 * @param valorRetorno
 * parâmetro do tipo Informacao passado como referência que será atualizado se a Chave dada realmente existir, nesse caso esse parâmetro será atualizado para o valor armazenado no nó pesquisado.
 * @return
 * retorno do tipo bool que retornará verdadeiro se a Chave existir na árvore e falso caso contrário.
 */
bool ArvoreBinariaDeBusca::find(Chave idProcurado, Informacao& valorRetorno) {
    NoABB* ptr = Raiz;
    int f;
    f = buscaABB(idProcurado, ptr);
    if (f == 1) {
        valorRetorno = ptr->info;
        return true;
    } else {
        return false;
    }
}
/** insereABB
 * @param idPosicao
 * parâmetro do tipo Chave que indica a posição do nó a ser inserido.
 * @param valorNovo
 * parâmetro do tipo Informacao que representa o valor do novo nó.
 * @param ptr
 * parâmetro do tipo NoABB que é passado como referência e será atualizado para o nó mais próximo de onde deve ser inserido o novo nó.
 * @return
 * retorno do tipo bool que retorna verdadeiro se o nó foi inserido ou falso caso contrário.
 */
bool ArvoreBinariaDeBusca::insereABB(Chave idPosicao, Informacao valorNovo, NoABB*& ptr) {
    NoABB* ptNo = ptr;
    NoABB* ptNovo;
    int f;
    f = buscaABB(idPosicao, ptNo);
    if (f == 1) {
        return false;
    } else {
        ptNovo = new NoABB;
        ptNovo->id = idPosicao;
        ptNovo->info = valorNovo;
        ptNovo->esq = NULL;
        ptNovo->dir = NULL;
        if (f == 0) {
            Raiz = ptNovo;
        } else {
            if (f == 2) {
                ptNo->esq = ptNovo;
            } else {
                ptNo->dir = ptNovo;
            }
        };
        return true;
    }
}

/** insert
 * @param idPosicao
 * parâmetro do tipo Chave que indica a posição do nó a ser inserido.
 * @param valorNovo
 * parâmetro do tipo Informacao que representa o valor do novo nó.
 * @return
 * retorno do tipo bool que retorna verdadeiro se o nó foi inserido ou falso caso contrário.
 */
bool ArvoreBinariaDeBusca::insert(Chave idPosicao, Informacao valorNovo) {
    bool r;
    r = insereABB(idPosicao, valorNovo, Raiz);
    return r;
}

/** localizaMin
 * @param ptr
 * parâmetro do tipo NoABB que é passado como referência e será atualizado para o nó que possui a menor chave dentre seus filhos.
 */
void ArvoreBinariaDeBusca::localizaMin(NoABB*& ptr) {
    NoABB* esq = ptr->esq;
    if (esq != NULL) {
        ptr = esq;
        localizaMin(ptr);
    };
}

/** removeABB
 * @param idPosicao
 * parâmetro do tipo Chave que indica qual nó deverá ser removido.
 * @param ptr
 * parâmetro do tipo NoABB que é passado como referência e será atualizado para o local onde a árvore será modificada.
 * @return
 * retorno do tipo bool que retorna verdadeiro se o nó foi removido ou falso caso contrário.
 */
bool ArvoreBinariaDeBusca::removeABB(Chave idPosicao, NoABB*& ptr) {
    NoABB* ptNo = ptr;
    bool r = true;
    if (ptr == NULL) {
        r = false;
    } else {
        if (idPosicao < ptr->id) {
            removeABB(idPosicao, ptr->esq);
        } else {
            if (idPosicao > ptr->id) {
                removeABB(idPosicao, ptr->dir);
            } else {
                if ((ptr->esq != NULL) && (ptr->dir != NULL)) {
                    ptNo = ptr->dir;
                    localizaMin(ptNo);
                    ptr->id = ptNo->id;
                    ptr->info = ptNo->info;
                    removeABB(ptNo->id, ptr->dir);
                } else {
                    ptNo = ptr;
                    if (ptNo->esq != NULL) {
                        ptr = ptr->esq;
                    } else {
                        ptr = ptr->dir;
                    };
                    delete [] ptNo;
                }
            }
        }
    };
    return r;
}

/** remove
 * @param idPosicao
 * parâmetro do tipo Chave que indica qual nó deverá ser removido.
 * @return
 * retorno do tipo bool que retorna verdadeiro se o nó foi removido ou falso caso contrário.
 */
bool ArvoreBinariaDeBusca::remove(Chave idPosicao) {
    bool r;
    r = removeABB (idPosicao, Raiz);
    return r;
}

/** imprimeArv
 * @param nivel
 * parâmetro do tipo int que indica o nível de cada nó, facilitando o entendimento da árvore em sua representação.
 * @param ptr
 * parâmetro do tipo NoABB que é atualizado a cada chamada da função e representa o nó cuja Chave será impressa.
 */
void ArvoreBinariaDeBusca::imprimeArv(int nivel, NoABB* ptr) {
    for (int i = 0; i < (nivel-1)*5; i++) {
        cout << "-";
    };
    cout << ptr->id << endl;
    if (ptr->esq != NULL) {
        imprimeArv((nivel+1), ptr->esq);
    };
    if (ptr->dir != NULL) {
        imprimeArv((nivel+1), ptr->dir);
    };
}

/** imprime
 * função chamada para representar a árvore na tela
 */
void ArvoreBinariaDeBusca::imprime() {
    imprimeArv(1,Raiz);
}


/** ArvoreBinariaDeBusca
 * construtor que inicia uma árvore simples sem sub-árvores.
 */
ArvoreBinariaDeBusca::ArvoreBinariaDeBusca() {
    Raiz = new NoABB;
    Raiz->id = 0;
    Raiz->info = 0;
    Raiz->dir = NULL;
    Raiz->esq = NULL;
}

/** ArvoreBinariaDeBusca
 * @param idRaiz
 * parâmetro do tipo Chave que indica o valor da chave do nó Raiz na construção da árvore.
 * @param infoRaiz
 * parâmetro do tipo Informacao que representa o valor armazendo na Raiz na construção da árvore.
 * @param subArvEsq
 * parâmetro do tipo NoABB que representa a sub-árvore esquerda da Raiz na construção da árvore.
 * @param subArvDir
 * parâmetro do tipo NoABB que representa a sub-árvore direita da Raiz na construção da árvore.
 */
ArvoreBinariaDeBusca::ArvoreBinariaDeBusca(Chave idRaiz, Informacao infoRaiz, NoABB* subArvEsq, NoABB* subArvDir) {
    Raiz = new NoABB;
    Raiz->id = idRaiz;
    Raiz->info = infoRaiz;
    Raiz->dir = subArvDir;
    Raiz->esq = subArvEsq;
}

/** ~ArvoreBinariaDeBusca
 * destrutor da árvore.
 */
ArvoreBinariaDeBusca::~ArvoreBinariaDeBusca() {
    delete [] Raiz;
}
