/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:36:32 by pnguyen-          #+#    #+#             */
/*   Updated: 2024/01/31 02:26:48 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "get_next_line.h"
#include "../libft.h"

static char	gnl_absorb_buffer(t_line *line, char buffer[BUFFER_SIZE + 1]);
static void	*gnl_realloc(char *src, size_t len, size_t size);
static int	gnl_append_line(int fd, t_line *line, char buffer[BUFFER_SIZE + 1]);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes;
	t_line		line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	if (gnl_absorb_buffer(&line, buffer))
		return (line.content);
	bytes = gnl_append_line(fd, &line, buffer);
	if (bytes == -1 || line.len == 0)
	{
		free(line.content);
		return (NULL);
	}
	line.content = gnl_realloc(line.content, line.len, line.len + 1);
	return (line.content);
}

static int	gnl_append_line(int fd, t_line *line, char buffer[BUFFER_SIZE + 1])
{
	char	*save;
	ssize_t	bytes;

	save = NULL;
	while (save == NULL)
	{
		if (line->size < line->len + BUFFER_SIZE + 1)
		{
			line->size *= 2;
			line->content = gnl_realloc(line->content, line->len, line->size);
		}
		if (line->content == NULL)
			return (-1);
		bytes = read(fd, line->content + line->len, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		line->content[line->len + bytes] = '\0';
		save = ft_strchr(line->content + line->len, '\n');
		line->len += bytes;
	}
	if (save == NULL)
		return (bytes);
	line->len = (save - line->content) + 1;
	ft_strlcpy(buffer, save + 1, BUFFER_SIZE + 1);
	return (bytes);
}

static char	gnl_absorb_buffer(t_line *line, char buffer[BUFFER_SIZE + 1])
{
	char	*save;

	line->len = 0;
	line->size = BUFFER_SIZE + 1;
	line->content = malloc(line->size * sizeof(char));
	if (line->content == NULL)
		return (1);
	if (buffer[0] == '\0')
		return (0);
	save = buffer;
	while (*save != '\0')
		save++;
	line->len = save - buffer;
	save = ft_strchr(buffer, '\n');
	if (save == NULL)
	{
		ft_strlcpy(line->content, buffer, line->len + 1);
		buffer[0] = '\0';
		return (0);
	}
	line->len = save - buffer + 1;
	ft_strlcpy(line->content, buffer, line->len + 1);
	ft_strlcpy(buffer, save + 1, BUFFER_SIZE + 1);
	line->content = gnl_realloc(line->content, line->len, line->len + 1);
	return (1);
}

static void	*gnl_realloc(char *src, size_t len, size_t size)
{
	char	*new_str;

	new_str = malloc(size * sizeof(char));
	if (new_str != NULL)
		ft_strlcpy(new_str, src, len + 1);
	free(src);
	return (new_str);
}
