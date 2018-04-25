/*
** EPITECH PROJECT, 2018
** verif chars
** File description:
** verif chars
*/

#include "../include/gameoflife.h"

int verif_char(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != '\n' && str[i] != '.' && str[i] != 'X')
			return (0);
	}
	return (1);
}

int verif_map(char **map, int size)
{
	for (int i = 0; i < size; i++) {
		if (verif_char(map[i]) == 0)
			return (0);
	}
	return (1);
}
