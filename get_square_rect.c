//
// Created by Vladyslav USLYSTYI on 2019-02-24.
//

#include "pizza.h"

int		is_square_valid(t_point *a, t_point *b, int res)
{
	int x;
	int y;

	x = b->x - a->x + 1;
	y = b->y - a->y + 1;
	if (x * y == res)
		return (1);
	return (0);
}

int 	is_valid_ingrid(t_point *a, t_point *b, t_pizza *pizza)
{
	int count_t;
	int count_m;
	t_point	iter;

	count_m = 0;
	count_t = 0;
	iter.y = a->y;
	while (iter.y <= b->y)
	{
		iter.x = a->x;
		while (iter.x <= b->x)
		{
			if (pizza->mas[iter.y][iter.x] == 'T')
				count_t++;
			else if (pizza->mas[iter.y][iter.x] == 'M')
				count_m++;
			iter.x++;
		}
		iter.y++;
	}
	if (count_m >= pizza->low && count_t >= pizza->low)
		return (1);
	return (0);
}

void 	dots(t_point *a, t_point *b, t_pizza *pizza)
{
	t_point	iter;

	iter.y = a->y;
	while (iter.y <= b->y)
	{
		iter.x = a->x;
		while (iter.x <= b->x)
		{
			pizza->mas[iter.y][iter.x] = '.';
			iter.x++;
		}
		iter.y++;
	}
}

void 	restore(t_point *a, t_point *b, t_pizza *pizza)
{
	t_point	iter;

	iter.y = a->y;
	while (iter.y <= b->y)
	{
		iter.x = a->x;
		while (iter.x <= b->x)
		{
			pizza->mas[iter.y][iter.x] = pizza->copy[iter.y][iter.x];
			iter.x++;
		}
		iter.y++;
	}
}