/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_putchar
*/

#include <unistd.h>
#include "../../include/my.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}
