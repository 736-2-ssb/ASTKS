/*******************************************************************************
* Copyright (C) 2020 TUSUR, FB
* File              : 7361_ssb.c
* Compiler          : gcc
* Version           : 9.2.1
* Created File      : 25.02.2020
* Last modified     : 1.03.2020
*
* Support mail      : s.b_sharkova@mail.ru
*
* Description       : splitting of string 
*                   :
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SUB_STR_LEN = 6;

void split_str (char* scr_str, char** result_str)
{
	int ammountOfSubs = strlen(scr_str)/SUB_STR_LEN;//количество подстрок, на которые разбиваем
	for (int i = 0; i < ammountOfSubs; i++)
	{
		for(int j = 0; j < SUB_STR_LEN; j++)
		{
			result_str[i][j] = scr_str[i*SUB_STR_LEN + j];//переписываем исходную строку в подстроки
		}
		result_str[i][SUB_STR_LEN] = '\0';//добавляем в конец подстроки символ конца строки
	}
}

int main()
{
	char str[18] = "some_random_string"; //длина 18
	char *str_ptr;//указатель на строку
	str_ptr = &str[0];//передаем в указатель адрес первого символа строки (адрес всей строки и есть адрес первого символа)
	int strLength = strlen(str);//длина входной строки
	int ammountOfSubs = strLength/SUB_STR_LEN;//количество подстрок, на которые разбиваем
	char **result_str = (char**)malloc(sizeof(char*)*ammountOfSubs);//указатель на массив с указателями на подстроки
	for (int i = 0; i < ammountOfSubs; i++)
	{
		result_str[i] = (char*)malloc(sizeof(char) * SUB_STR_LEN + 1);//каждый элемент - указатель на строку размером с длину подстроки + 1 под символ конца строки
	}
	split_str(str, result_str);//делим исходную строку на подстроки
	for (int i = 0; i < ammountOfSubs; i++)//выводим подстроки
	{
		printf("%s", result_str[i]);
		printf("\n");
	}
	return 0;
}
