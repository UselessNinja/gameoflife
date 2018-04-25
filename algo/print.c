/*
** EPITECH PROJECT, 2018
** print
** File description:
** print
*/

#include "../include/gameoflife.h"

void print_grid(grid_t *grid)
{
	for (int i = 0; i < grid->size; i++)
		printf("%s", grid->map[i]);
}
