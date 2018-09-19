//
// Created by Alena Pashkevich on 12.09.2018.
//
#include <memory.h>
#include <bfd.h>
#include "stdlib.h"
#include "stdbool.h"

typedef char* VA;

struct Cell {
    char info;
    bool isFree;
    bool isStart;
    bool isEnd;
};

struct CellCache {
    int address;
    int time; //сюда нужно вписывать вот это штуку с времнной локальностью, что тип, что название меняю, ибо я писала от балды
    bool isModified;
};

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
    struct Cell memory[n];

    for(int i = 0; i < n*szPage; i++){
        memory[i].isFree = true;
        memory[i].isStart = false;
        memory[i].isStart = false;
    }
    for(int i = 0; i < n*szPage; i+= szPage){
        memory[i].isStart = true;
    }
    for(int i = szPage - 1; i < n*szPage; i+= szPage){
        memory[i].isEnd = true;
    }

    struct CellCache cache[4];

    for(int i = 0; i < 4; i++){
        cache[i].address = 0;
        cache[i].isModified = false;
        cache[i].time = 0;
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
	@retval	-1	неверные параметры   //хз
	@retval	-2	нехватка памяти
	@retval	1	неизвестная ошибка  // хз
 **/
int _malloc (VA* ptr, size_t szBlock) {
    int endOfBlock;
    int szPage = 10;
    int n = 10; // здесь нужно как-то передать нашу память или сделать её глобальной хз
    struct Cell memory[n];

    for (int i = 0; i < n*szPage; i++){
        if (memory[i].isFree){
            for (int j = 0; j < szBlock; j++){
                if (!memory[j].isFree){
                    i = j;
                    break;
                }
                if (j == (szBlock-1)){
                    endOfBlock = j;
                    for (int k = endOfBlock; k > endOfBlock - szBlock; k--){
                        memory[k].isFree = false;
                        if(k == endOfBlock - szBlock - 1){
                           //k - индекс с которого можно начинать записывать
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return -2;
}

/**
 	@func	_free
 	@brief	Удаление блока памяти

	@param	[in] ptr		адресс блока

	@return	код ошибки
	@retval	0	успешное выполнение
	@retval	-1	неверные параметры
	@retval	1	неизвестная ошибка
 **/
int _free (VA ptr);