//
// Created by Vladyslav USLYSTYI on 2019-02-28.
//

#include <libft.h>
#include "slideshow.h"
#include "slide.h"

t_slide		*create_slide(char **tags, int a, int b, int count)
{
	t_slide		*slide;

	slide = (t_slide*)ft_memalloc(sizeof(t_slide));
	slide->tags = tags;
	slide->a = a;
	slide->b = b;
	slide->count_tags = count;
	slide->next = NULL;
	return (slide);
}

void		push_slide(t_slide **slide, t_slide *new_slide)
{
	if (*slide == NULL)
	{
		*slide = new_slide;
		new_slide->next = NULL;
	}
	else
	{
		new_slide->next = *slide;
		*slide = new_slide;
	}
}