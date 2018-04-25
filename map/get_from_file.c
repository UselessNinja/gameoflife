/*
** EPITECH PROJECT, 2018
** CPE_duostumper_2_2017
** File description:
** get_from_file
*/

#include "../include/gameoflife.h"

int free_map(char **map, int lines)
{
	int i;

	for (i = 0; i < lines; i++)
		free(map[i]);
	free(map);
	return (0);
}

int fill_map(grid_t *g, char *buffer, int i, FILE *fd)
{
	size_t len = 0;
	int size;

	size = getline(&buffer, &len, fd);
	if (size == -1 || size != g->old_size) {
		free_map(g->map, i);
		free_map(g->old_map, i);
		free(buffer);
		return (84);
	}
	g->map[i] = strdup(buffer);
	g->old_map[i] = strdup(buffer);
	free(buffer);
	return (0);
}

void malloc_maps(grid_t *g)
{
	g->map = malloc(sizeof(char *) * g->size);
	g->old_map = malloc(sizeof(char *) * g->size);
}

int get_size(char *path, grid_t *g)
{
	size_t len = 0;
	struct stat sb;
	FILE *fd;
	char *buffer = NULL;

	if (stat(path, &sb) == -1)
		return (84);
	fd = fopen(path, "r");
	if (fd == NULL)
		return (84);
	g->old_size = getline(&buffer, &len, fd);
	if (g->old_size == -1) {
		fclose(fd);
		return (84);
	}
	g->size = (int)sb.st_size / g->old_size;
	printf("%i", g->size);
	free(buffer);
	fclose(fd);
	malloc_maps(g);
	return (0);
}

int map_from_file(grid_t *g, char *path)
{
	FILE *fd;
	char *buffer = NULL;
	int i;

	if (get_size(path, g) != 0)
		return (84);
	fd = fopen(path, "r");
	if (fd == NULL)
		return (84);
	for (i = 0; i < g->size; i++)
		if (fill_map(g, buffer, i, fd) != 0) {
			fclose(fd);
			return (84);
		}
	fclose(fd);
	return (0);
}
