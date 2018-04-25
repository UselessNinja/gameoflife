/*
** EPITECH PROJECT, 2017
** mygetnumber
** File description:
** Converts a char or string into an int.
*/

#include "../../include/my.h"

int my_getnumber(char *str)
{
	int count = 0;
	int result = 0;

	if (str == NULL)
		return (0);
	if (str[0] == '-')
		count++;
	for (count = 0; str[count] != '\0'; count++) {
		if (str[count] < '0' || str[count] > '9')
			return (0);
		result += str[count] - 48;
		result *= 10;
	}
	result /= 10;
	if (str[0] == '-')
		result *= -1;
	return (result);
}

int my_getread(char *str)
{
	int count = 0;
	int result = 0;

	if (str[0] < '0' || str[0] > '9')
		return (-1);
	for (count = 0; str[count] != '\n'; count++) {
		if (str[count] < '0' || str[count] > '9')
			return (-1);
		result *= 10;
		result += str[count] - '0';
	}
	return (result);
}
