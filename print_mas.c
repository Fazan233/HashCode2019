//
// Created by Vladyslav USLYSTYI on 2019-02-24.
//

#include "pizza.h"

void 	print_mas(t_pizza *pizza, const char **mas)
{
	int i;

	i = 0;
	while (i < pizza->row)
	{
		ft_putstr(mas[i]);
		ft_putchar('\n');
		i++;
	}
}