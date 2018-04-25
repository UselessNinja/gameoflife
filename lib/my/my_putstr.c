/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_putstr
*/

#include "../../include/my.h"

void my_putstr(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		my_putchar(str[i]);
}
