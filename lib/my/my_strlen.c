/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_strlen
*/

#include "../../include/my.h"

int my_strlen(char const *str)
{
	int len = 0;

	if (str == NULL)
		return (0);
	for (; str[len] != '\0'; len++);
	return (len);
}
