/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:08:37 by wivieira          #+#    #+#             */
/*   Updated: 2023/11/30 12:08:37 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	finallylist(t_list **list)
{
	t_list	*last_node;
	t_list	*newbufferbreakln;
	int		i;
	int		j;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	newbufferbreakln = malloc(sizeof(t_list));
	if (!buffer || !newbufferbreakln)
		return ;
	last_node = ft_lstlastg(*list);
	j = 0;
	i = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
			i++;
	while (last_node->content[i] && last_node->content[++i])
		buffer[j++] = last_node->content[i];
	buffer[j] = '\0';
	free_list(*list);
	newbufferbreakln->content = buffer;
	newbufferbreakln->next = NULL;
	*list = newbufferbreakln;
}

char	*outside_line(t_list *list)
{
	int		lenline;
	char	*str;

	if (!list)
		return (NULL);
	lenline = countnewline(list);
	str = malloc(lenline + 1);
	if (!str)
		return (NULL);
	copy_line(list, str);
	return (str);
}

void	ft_add(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlastg(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
	{
		*list = new_node;
	}
	else
	{
		last_node->next = new_node;
	}
	new_node->content = buffer;
	new_node->next = NULL;
}

void	ft_createnode(t_list **list, int fd)
{
	int		char_read;
	char	*buffer;

	char_read = 1;
	while (!new_line(*list) && char_read != 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		if ((!char_read && list == NULL) || char_read < 0)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		ft_add(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list[1024];	
	char			*line_actual;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, &line_actual, 0) < 0)
	{
		free_list(list[fd]);
		list[fd] = NULL;
		return (NULL);
	}
	line_actual = (NULL);
	ft_createnode(&list[fd], fd);
	if (!list[fd])
		return (NULL);
	line_actual = outside_line(list[fd]);
	finallylist(&list[fd]);
	if (line_actual[0] == '\0')
	{
		free_list(list[fd]);
		list[fd] = NULL;
		free(line_actual);
		return (NULL);
	}
	return (line_actual);
}