/*
** EPITECH PROJECT, 2018
** strdup
** File description:
** strdup
*/

#include "../../include/my.h"

char *my_strdup(char const *str)
{
	char *new;
	int i = 0;

	new = malloc(sizeof(char) * my_strlen((char *)str) + 1);
	my_memset(&new, my_strlen((char *)str));
	if (new == NULL)
		return (NULL);
	while (str[i] != '\0') {
		new[i] = str[i];
		i++;
		new[i] = '\0';
	}
	return (new);
}
