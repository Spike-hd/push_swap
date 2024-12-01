/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hduflos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:34:51 by hduflos           #+#    #+#             */
/*   Updated: 2024/11/26 12:16:04 by hduflos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*free_storage(char **storage)
{
	if (*storage)
	{
		free(*storage);
		*storage = NULL;
	}
	return (NULL);
}

char	*read_and_store(int fd, int *nb_read, char *storage, char *buffer)
{
	char	*new_storage;

	new_storage = NULL;
	*nb_read = read(fd, buffer, BUFFER_SIZE);
	if (*nb_read == -1)
		return (free_storage(&storage));
	if (*nb_read == 0)
		return (storage);
	buffer[*nb_read] = '\0';
	if (!storage)
		return (ft_strdup(buffer));
	new_storage = ft_strjoin(storage, buffer);
	free(storage);
	storage = NULL;
	return (new_storage);
}

char	*extract_line(char **storage, int nb_read)
{
	char	*line;
	char	*new_storage;
	int		i;

	if (!*storage || **storage == '\0')
		return (NULL);
	i = 0;
	while ((*storage)[i] && (*storage)[i] != '\n')
		i++;
	if ((*storage)[i] == '\n')
	{
		line = ft_substr(*storage, 0, i + 1);
		new_storage = ft_strdup(*storage + i + 1);
		free(*storage);
		*storage = new_storage;
		return (line);
	}
	if (nb_read == 0)
	{
		line = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*buffer;
	char		*line;
	int			nb_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (free_storage(&storage[fd]));
		storage[fd] = read_and_store(fd, &nb_read, storage[fd], buffer);
		free(buffer);
		if (!storage[fd] && nb_read != 0)
			return (NULL);
		line = extract_line(&storage[fd], nb_read);
		if (line)
			return (line);
		if (nb_read == 0)
			return (free_storage(&storage[fd]));
	}
}
