/*
** EPITECH PROJECT, 2018
** algo
** File description:
** algo
*/

#include "../include/gameoflife.h"

int get_nb_corners(char **map, pos_t *pos, pos_t *max)
{
	int nb = 0;

	if (can_left(pos->x) && can_up(pos->y)
	&& map[pos->y - 1][pos->x - 1] == 'X')
		nb++;
	if (can_right(pos->x, max->x) && can_up(pos->y)
	&& map[pos->y - 1][pos->x + 1] == 'X')
		nb++;
	if (can_left(pos->x) && can_down(pos->y, max->y)
	&& map[pos->y + 1][pos->x - 1] == 'X')
		nb++;
	if (can_right(pos->x, max->x) && can_down(pos->y, max->y)
	&& map[pos->y + 1][pos->x + 1] == 'X')
		nb++;
	return (nb);
}

int get_nb_neighb(char **map, pos_t *pos, pos_t *max)
{
	int nb = 0;

	if (can_left(pos->x) && map[pos->y][pos->x - 1] == 'X')
		nb++;
	if (can_right(pos->x, max->x) && map[pos->y][pos->x + 1] == 'X')
		nb++;
	if (can_up(pos->y) && map[pos->y - 1][pos->x] == 'X')
		nb++;
	if (can_down(pos->y, max->y) && map[pos->y + 1][pos->x] == 'X')
		nb++;
	nb += get_nb_corners(map, pos, max);
	return (nb);
}

void change_state(grid_t *grid, int nb_neighb, pos_t *pos)
{
	int x = pos->x;
	int y = pos->y;

	if (grid->map[y][x] == '.' && nb_neighb == 3)
		grid->old_map[y][x] = 'X';
	if (nb_neighb < 2)
		grid->old_map[y][x] = '.';
	if (nb_neighb > 3)
		grid->old_map[y][x] = '.';
}

int run_simulation(grid_t *grid)
{
	pos_t max = {0, grid->size};

	max.x = strlen(grid->map[0]);
	for (int i = 0; i < grid->nb_it; i++) {
		replace_old(grid);
		copy_map(grid, &max);
		replace_new_map(grid);
	}
	return (0);
}
