/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 03:59:56 by vpluchar          #+#    #+#             */
/*   Updated: 2017/02/06 22:30:49 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_get_line(char **content, char **line, int res)
{
	char	*tmp;
	char	*off;

	tmp = *content;
	off = ft_strchr(tmp, '\n');
	if (off)
	{
		*line = ft_strsub(tmp, 0, off - tmp);
		*content = ft_strdup(off + 1);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(tmp);
		free(*content);
		*content = NULL;
	}
	if ((!*line) || (off && !*content))
		return (-1);
	if ((!res && *content) || (*line))
		return (1);
	return (res);
}

static int	gnl_get_content(int fd, char **content)
{
	char	*buf;
	char	*tmp;
	int		res;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	res = 1;
	while ((ft_strchr(*content, '\n') == NULL) && res > 0)
	{
		tmp = *content;
		res = read(fd, buf, BUFF_SIZE);
		if (res > 0)
		{
			buf[res] = '\0';
			if (!(*content = ft_strjoin(tmp, buf)))
			{
				*content = ft_strcat(tmp, buf);
				free(buf);
				return (-1);
			}
			free(tmp);
		}
	}
	free(buf);
	return (res);
}

int			get_next_line(int const fd, char **line)
{
	static char	*content[1024];
	int			res;

	if (!line || (read(fd, NULL, 0) == -1) || fd < 0)
		return (-1);
	if (content[fd] == NULL)
		if ((content[fd] = ft_strnew(BUFF_SIZE * 2)) == NULL)
			return (-1);
	res = 0;
	if (ft_strchr(content[fd], '\n') == NULL)
		res = gnl_get_content(fd, &content[fd]);
	if (res > 1)
		res = 1;
	if (res == 0 && *content[fd] == '\0')
	{
		*line = NULL;
		free(content[fd]);
		content[fd] = NULL;
	}
	else if (res > 0 || *content[fd] != '\0')
		res = gnl_get_line(&content[fd], line, res);
	return (res);
}
