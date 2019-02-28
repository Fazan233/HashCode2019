//
// Created by Vladyslav USLYSTYI on 2019-02-28.
//

#ifndef UNTITLED2_SLIDE_H
#define UNTITLED2_SLIDE_H

#include "slideshow.h"

typedef struct		s_slide
{
	int				used;
	char 			**tags;
	int				a;
	int				b;
	int				count_tags;
	struct 	s_slide *next;
}					t_slide;

void		push_slide(t_slide **slide, t_slide *new_slide);
t_slide		*create_slide(char **tags, int a, int b, int count);
void 	get_list_slide(t_slide **slide, t_photo *begin);
void	 get_result_list(t_slide **result, t_slide *orig);
t_slide	*get_pair(t_slide *slide, t_slide *begin);
int 	count_compare_tags(t_slide *s1, t_slide *s2);
int 	count_slides(t_slide *begin);

#endif //UNTITLED2_SLIDE_H
