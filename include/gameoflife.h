/*
** EPITECH PROJECT, 2018
** lib
** File description:
** colle duo head
*/

#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pos {
	int x;
	int y;
} pos_t;

typedef struct grid {
	char **map;
	char **old_map;
	int old_size;
	int size;
	int nb_it;
} grid_t;

void print_grid(grid_t *grid);
int run_simulation(grid_t *grid);
int map_from_file(grid_t *g, char *path);
int can_left(int x);
int can_right(int x, int max_x);
int can_up(int y);
int can_down(int y, int max_y);
void copy_map(grid_t *grid, pos_t *max);
void replace_old(grid_t *grid);
void replace_new_map(grid_t *grid);
void change_state(grid_t *grid, int nb_neighb, pos_t *pos);
int get_nb_corners(char **map, pos_t *pos, pos_t *max);
int get_nb_neighb(char **map, pos_t *pos, pos_t *max);
int verif_map(char **map, int size);
int free_map(char **map, int lines);

#endif /* GAMEOFLIFE_H */
