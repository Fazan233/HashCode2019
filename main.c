#include <printf.h>
#include "slideshow.h"
#include "libft.h"
#include "slide.h"

void	parse(t_photo **lst, char *line, int step)
{
	int i;

	i = 2;
	(*lst)->orient = line[0];
	(*lst)->used = 0;
	(*lst)->id = step;
	(*lst)->count_tags = ft_atoi(&line[2]);
	while (ft_isdigit(line[i]))
		i++;
	(*lst)->tags = ft_strsplit(&line[i], ' ');
	(*lst)->next = (t_photo*)malloc(sizeof(t_photo));
	*lst = (*lst)->next;
	(*lst)->next = NULL;
}

void	free_struct(t_photo **lst)
{
	int     i;
	t_photo *ptr;

	while ((*lst)->next)
	{
		i = -1;
		ptr = *lst;
		while (++i < (*lst)->count_tags)
			free((*lst)->tags[i]);
		free((*lst)->tags);
		*lst = (*lst)->next;
		free(ptr);
	}
}


int main()
{
	int		fd;
	char	*line;
	int 	value;
	int		step;
	t_photo *lst;
	t_photo	*head;
	int 	count;

	step = 0;
	lst = (t_photo*)malloc(sizeof(t_photo));
	lst->next = NULL;
	head = lst;
	fd = open("b_lovely_landscapes.txt", O_RDONLY);
//	fd = open("d_pet_pictures.txt", O_RDONLY);
//	fd = open("a_example.txt", O_RDONLY);
	get_next_line(fd, &line);
	value = ft_atoi(line);
	free(line);
	while(get_next_line(fd, &line) > 0)
	{
		parse(&lst, line, step);
		free(line);
		step++;
	}

	t_slide *orig_h;
	t_slide *result;

	orig_h = NULL;
	result = NULL;

	get_list_slide(&orig_h, head);
	get_result_list(&result, orig_h);

	count = count_slides(result);
	printf("%d\n", count);
	while (result)
	{
		printf("%d", result->a);
		if (result->b != -1)
			printf(" %d", result->b);
		printf("\n");
		result = result->next;
	}


	free_struct(&lst);
	return (0);
}