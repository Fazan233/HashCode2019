//
// Created by Vladyslav USLYSTYI on 2019-02-28.
//

#include <stdio.h>
#include "slide.h"
#include "slideshow.h"

int 	count_compare_tags(t_slide *s1, t_slide *s2)
{
	int count;
	char **t1;
	char **t2;

	count = 0;

	t1 = (s1->tags);
	while (*t1)
	{
		t2 = (s2->tags);
		while (*t2)
		{
			if (!strcmp(*t1, *t2))
			{
				count++;
				break ;
			}
			t2++;
		}
		t1++;
	}
	return (count);
}

t_slide	*get_pair(t_slide *slide, t_slide *begin)
{
	t_slide		*best;
	int 		optimal;
	int 		best_optimal;
	int 		current_len;

	int			val;

	int 		current_opt;

	best_optimal = 2000000000;
	optimal = slide->count_tags / 2;

	best = NULL;

	while(begin)
	{
		if (begin->used == 0)
		{
			current_opt = count_compare_tags(slide, begin);
			current_len = abs(slide->count_tags - begin->count_tags);
			val = abs((abs(current_opt - optimal)) - current_len);
			if (abs((abs(current_opt - optimal)) - current_len) < best_optimal)
			{
				best_optimal = val;
				best = begin;
				if (best_optimal < 4)
					break ;
			}
		}
		begin = begin->next;
	}
	if (!best)
		return (NULL);
	best->used = 1;
	return (best);
}


void 	get_list_slide(t_slide **slide, t_photo *begin)
{
	while (begin)
	{
		if (begin->orient == 'H')
			push_slide(slide, create_slide(begin->tags, begin->id, -1, begin->count_tags));
		begin = begin->next;
	}
}




void	 get_result_list(t_slide **result, t_slide *orig)
{
	t_slide	*pair;
	t_slide	*curr;

	curr = create_slide(orig->tags, orig->a, orig->b, orig->count_tags);
	push_slide(result, curr);
//	(*result)->next = NULL;
	orig->used = 1;

	while ((pair = get_pair(*result, orig)))
	{
//		printf("%d\n", pair->a);
//		printf("\n");
		curr = create_slide(pair->tags, pair->a, pair->b, pair->count_tags);
		pair->used = 1;
		curr->next = NULL;
		push_slide(result, curr);
	}
}

int 	count_slides(t_slide *begin)
{
	int i;

	i = 0;
	while (begin)
	{
		i++;
		begin = begin->next;
	}
	return (i);
}

