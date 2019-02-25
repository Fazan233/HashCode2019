#include <stdio.h>
#include <fcntl.h>
#include "pizza.h"

int count(t_stack *res)
{
	size_t i;

	i = 0;
	while (res)
	{
		res = res->next;
		i++;
	}
	return(i);
}

int main()
{
	t_pizza pizza;
	t_stack *stack;
	int 	fd;
	t_point point;

	int 	count_;

	point.x = 0;
	point.y = 0;

	fd = open("file", O_RDONLY);
	parsing(&pizza, fd);
//	print_mas(&pizza, (const char**)pizza.mas);
	pizza.res = NULL;
	recursion(point, &pizza, &stack);
	count_ = count(pizza.res);
	if (pizza.res != NULL)
	{
		ft_printf("total - %d\n", pizza.res->total);
		ft_printf("%llu\n", count_);
		while (pizza.res)
		{
			ft_printf("%d %d %d %d\n", pizza.res->a.y, pizza.res->a.x,
					  pizza.res->b.y, pizza.res->b.x);
			pizza.res = pizza.res->next;
		}
	}
	return 0;
}