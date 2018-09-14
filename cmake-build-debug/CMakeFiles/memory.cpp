//
// Created by Alena Pashkevich on 12.09.2018.
//
#include <memory.h>
#include "stdlib.h"


typedef char* VA;

struct LinkedList {
    int info;
    struct LinkedList *next, *prev;
} *begin, *end;

struct cache {
    int info;
    struct cache *next, *prev;
} *beginK, *endK;



/**
 	@func	_init
 	@brief	Инициализация модели менеджера памяти

	@param	[in] n		количество страниц
	@param	[in] szPage	размер страницы

	В варианте 1 и 2 общий объем памяти расчитывается как n*szPage

	@return	код ошибки
	@retval	0	успешное выполнение
	@retval	-1	неверные параметры //ToDO()
	@retval	1	неизвестная ошибка
 **/

int _init (int n, int szPage) {
    struct LinkedList **end;
    struct LinkedList **begin;
    begin = end = NULL;
    struct linkedList *element;
    if(!(element = (struct linkedList *) calloc (1, szPage))) { return 1; }
    *begin = *end = element;
    for (int i = 0; i < n - 1; i++) {
        struct linkedList *element;
        if(!(element = (struct linkedList *) calloc (1, szPage))) {return 1;}
        element -> next = *end;
        (*end) -> prev = element;
        *end = element;
    }

    struct cache **endK;
    struct cache **beginK;
    beginK = endK = NULL;
    struct cache *elementK;
    if (!(elementK = (struct cache *) calloc (1, szPage))) { return 1; }
    *beginK = *endK = elementK;
    for (int i = 0; i < 5; i++) {
        struct linkedList *elementK;
        if (!(elementK = (struct cache *) calloc (1, szPage))) { return  1;}
        elementK -> next = *endK;
        (*endK) -> prev = elementK;
        *endK = elementK;
    }
    return 0;
}

/**
 	@func	_malloc
 	@brief	Выделяет блок памяти определенного размера

	@param	[out] ptr		адресс блока
	@param	[in]  szBlock	размер блока

	@return	код ошибки
	@retval	0	успешное выполнение
	@retval	-1	неверные параметры
	@retval	-2	нехватка памяти
	@retval	1	неизвестная ошибка
 **/
int _malloc (struct LinkedList* element, size_t szBlock){
    size_t
    if(element -> info != NULL){

    }
}