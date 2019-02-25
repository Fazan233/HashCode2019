//
// Created by Vladyslav USLYSTYI on 2019-02-24.
//

#include "libft.h"
#include "pizza.h"

void	parsing(t_pizza *pizza, int fd)
{
	char 	*line;
	char 	*tmp;
	int 	i;

	//first line
	get_next_line(fd, &line);
	tmp = line;
	pizza->row = ft_atoi(tmp);
	while (ft_isdigit(*tmp))
		tmp++;
	tmp++;
	pizza->col = ft_atoi(tmp);
	while (ft_isdigit(*tmp))
		tmp++;
	tmp++;
	pizza->low = ft_atoi(tmp);
	while (ft_isdigit(*tmp))
		tmp++;
	pizza->s_max = ft_atoi(tmp);

	//pizza map
	pizza->mas = (char**)malloc(sizeof(char*) * pizza->row);
	pizza->copy = (const char**)malloc(sizeof(char*) * pizza->row);
	free(line);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		pizza->copy[i] = (const char*)ft_strdup(line);
		pizza->mas[i] = ft_strdup(line);
		free(line);
		i++;
	}
}
