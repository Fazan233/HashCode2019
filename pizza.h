//
// Created by Vladyslav USLYSTYI on 2019-02-24.
//

#ifndef PIZZA_H
#define PIZZA_H

#include "libft.h"

typedef struct	s_pizza
{
	int		row;
	int		col;
	int		low;
	int		s_max;
	char 	**mas;
	const char 	**copy;
	struct s_stack *res;
}				t_pizza;

typedef struct		s_point
{
	short			x;
	short			y;
}					t_point;

typedef struct	s_stack
{
	int 			total;
	struct s_point	a;
	struct s_point	b;
	struct s_stack	*next;
}				t_stack;

void	parsing(t_pizza *pizza, int fd);
int		is_square_valid(t_point *a, t_point *b, int res);
int 	is_valid_ingrid(t_point *a, t_point *b, t_pizza *pizza);
void 	dots(t_point *a, t_point *b, t_pizza *pizza);
void 	restore(t_point *a, t_point *b, t_pizza *pizza);
t_stack	*create_stack(int total, t_point *start, t_point *end);
void	push_stack(t_stack **stack, t_stack *item);
void	pop_stack(t_stack **stack);
t_stack	*copy_stack(t_stack *stack);
void		recursion(t_point start, t_pizza *pizza, t_stack **stack);
void 	print_mas(t_pizza *pizza, const char **mas);

#endif
