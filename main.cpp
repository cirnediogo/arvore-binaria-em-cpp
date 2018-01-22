/* 
 * File:   main.cpp
 * Author: ubuntu
 *
 * Created on 7 de Novembro de 2009, 18:47
 */

#include <stdlib.h>
#include "ArvoreBinariaDeBusca.h"
/*
 * 
 */
int main(int argc, char** argv) {

    ArvoreBinariaDeBusca Arvore(8, 8, NULL, NULL);
    Arvore.insert(3, 3);
    Arvore.insert(1, 1);
    Arvore.insert(5, 5);
    Arvore.insert(6, 6);
    Arvore.insert(7, 7);
    Arvore.insert(11, 11);
    Arvore.insert(9, 9);
    Arvore.insert(10, 10);
    Arvore.insert(14, 14);
    Arvore.insert(12, 12);
    Arvore.insert(13, 13);
    Arvore.insert(15, 15);
    Arvore.imprime();


    return (EXIT_SUCCESS);
}

