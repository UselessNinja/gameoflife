/*
** EPITECH PROJECT, 2018
** algo
** File description:
** algo
*/

#include "../include/gameoflife.h"

void copy_map(grid_t *grid, pos_t *max)
{
	pos_t pos = {0, 0};
	int nb_neighb = 0;

	for (int i = 0; i < grid->size; i++) {
		for (int j = 0; grid->map[i][j] != '\0'
		&& grid->map[i][j] != '\n'; j++) {
			pos.x = j;
			pos.y = i;
			nb_neighb = get_nb_neighb(grid->map, &pos, max);
			change_state(grid, nb_neighb, &pos);
		}
	}
}

void replace_old(grid_t *grid)
{
	for (int i = 0; i < grid->size; i++) {
		free(grid->old_map[i]);
		grid->old_map[i] = strdup(grid->map[i]);
	}
}

void replace_new_map(grid_t *grid)
{
	for (int i = 0; i < grid->size; i++) {
		free(grid->map[i]);
		grid->map[i] = strdup(grid->old_map[i]);
	}
}
