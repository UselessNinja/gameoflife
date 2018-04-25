/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_memset
*/

#include "../../include/my.h"

void my_memset(char **str, int size)
{
	for (int i = 0; i <= size; i++)
		(*str)[i] = '\0';
}
