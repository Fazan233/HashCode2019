#ifndef HASHCODE_SLIDESHOW_H
#define HASHCODE_SLIDESHOW_H

#include "libft.h"
#include <fcntl.h>

typedef struct		s_photo
{
	int 			id;
	char			orient;
	int 			used;
	int 			count_tags;
	char			**tags;
	struct s_photo	*next;
}					t_photo;

//void	parse(t_photo **lst, char *line, int step);
//void	free_struct(t_photo **lst);
#endif
