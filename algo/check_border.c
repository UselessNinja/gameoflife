/*
** EPITECH PROJECT, 2018
** check border
** File description:
** checkborder
*/

#include "../include/gameoflife.h"

int can_left(int x)
{
	if (x > 0)
		return (1);
	return (0);
}

int can_right(int x, int max_x)
{
	if (x < max_x)
		return (1);
	return (0);
}

int can_up(int y)
{
	if (y > 0)
		return (1);
	return (0);
}

int can_down(int y, int max_y)
{
	if ((y + 1) < max_y)
		return (1);
	return (0);
}
