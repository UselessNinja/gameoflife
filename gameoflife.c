/*
** EPITECH PROJECT, 2018
** gameoflife
** File description:
** gameoflife
*/

#include "./include/gameoflife.h"

int check_nb_it(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	if (strlen(str) > 10)
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	grid_t grid;

	if (argc != 3)
		return (84);
	if (!check_nb_it(argv[2]))
		return (84);
	grid.nb_it = atoi(argv[2]);
	if (map_from_file(&grid, argv[1]) != 0)
		return (84);
	if (!verif_map(grid.map, grid.size)) {
		free_map(grid.map, grid.size);
		free_map(grid.old_map, grid.size);
		return (84);
	}
	run_simulation(&grid);
	print_grid(&grid);
	free_map(grid.map, grid.size);
	free_map(grid.old_map, grid.size);
	return (0);
}
