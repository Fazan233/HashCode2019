//
// Created by Vladyslav USLYSTYI on 2019-02-24.
//

#include "pizza.h"

t_point 	skip_point(t_point start, t_pizza *pizza)
{
	if (pizza->mas[start.y][start.x] == '.')
	{
		if (start.x == pizza->col)
		{
			start.x = 0;
			start.y++;
		}
		while (start.y < pizza->row)
		{
			start.x = 0;
			while (start.x < pizza->col)
			{
				if (pizza->mas[start.y][start.x] != '.')
					return (start);
				start.x++;
			}
			start.y++;
		}
	}
	return (start);
}

void		recursion(t_point start, t_pizza *pizza, t_stack **stack)
{
	int		max;
	int		min;
	t_point	end;
	t_point tmp;

	max = pizza->s_max;
	min = pizza->low * 2;

//	while (pizza->mas[start.y][start.x] == '.' && start.y < pizza->row)
//	{
//		while (pizza->mas[start.y][start.x] == '.' && start.x < pizza->col)
//			start.x++;
//		if (pizza->mas[start.y][start.x] == '.' || start.x == pizza->col)
//		{
//			start.x = 0;
//			start.y++;
//		}
//	}
	start = skip_point(start, pizza);
	if (start.y == pizza->row)
		return ;

	if (start.x >= pizza->col)
	{
		start.x = 0;
		start.y++;
	}

	if (start.y >= pizza->row)
		return ;

	if (pizza->mas[start.y][start.x] != '.')
	{
		while (max >= min)
		{
			end.y = start.y;
			while (end.y - start.y < max && end.y < pizza->row)
			{
				end.x = start.x;
				while (end.x - start.x < max && end.x < pizza->col)
				{
					//if (!is_square_valid(&start, &end, max))
					//ft_printf("start: x%dy%d, end x%dy%d, max%d\n", start.x, start.y, end.x, end.y, max);
					if (is_square_valid(&start, &end, max))
					//if (ft_printf("start: x%dy%d, end x%dy%d, max%d, res%d\n", start.x, start.y, end.x, end.y, max, is_square_valid(&start, &end, max)) && is_square_valid(&start, &end, max))
					{
//						if (start.y == 64 && start.x == 222)
//							print_mas(pizza, (const char**)pizza->mas);
						if (is_valid_ingrid(&start, &end, pizza))
						{
							if (start.y == 64 && start.x == 222)
								print_mas(pizza, (const char**)pizza->mas);
//							if (start.y == 64 && start.x == 219)
//								print_mas(pizza, (const char**)pizza->mas);
							//ft_printf("start: x%dy%d, end x%dy%d, max%d\n", start.x, start.y, end.x, end.y, max);
							push_stack(stack, create_stack(max, &start, &end));
							dots(&start, &end, pizza);
							//print_mas(pizza, pizza->copy);
							tmp.x = end.x;
							tmp.y = start.y;
							//start.x++;
							recursion(tmp, pizza, stack);
							restore(&start, &end, pizza);
							pop_stack(stack);

						}
						//break ;
					}
					end.x++;
				}
				end.y++;
			}
			max--;
		}
		//ft_printf("start: x%dy%d, end x%dy%d, max%d\n", start.x, start.y, end.x, end.y, max);
		if (*stack == NULL)
		{
//			ft_printf("start: x%dy%d, end x%dy%d, max%d\n", start.x, start.y, end.x, end.y, max);
			return ;
		}
		if (pizza->res)
		{
			if ((*stack)->total > pizza->res->total)
			{
				ft_printf("%i\n", pizza->res->total);
				pizza->res = copy_stack(*stack);
			}
		}
		else
			pizza->res = copy_stack(*stack);
	}
}