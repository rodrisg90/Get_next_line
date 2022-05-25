/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodsanch <rodsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:16:24 by rodsanch          #+#    #+#             */
/*   Updated: 2022/05/25 15:39:10 by rodsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_join_free(char *buf1, char *buf2)
{
	char	*aux;

	aux = ft_strjoin(buf1, buf2);
	free(buf1);
	return (aux);
}

char	*ft_read(int fd, char *save)
{
	char	*buf1;
	int		z;

	if (!save)
		save = (char *)ft_calloc(1, 1);
	buf1 = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	z = 1;
	while (z > 0)
	{
		z = read(fd, buf1, BUFFER_SIZE);
		if (z == -1)
		{
			free(buf1);
			return (NULL);
		}
		buf1[z] = 0;
		save = ft_join_free(save, buf1);
		if (ft_strchr(buf1, '\n'))
			break ;
	}
	free(buf1);
	return (save);
}

char	*ft_line(char *buf1)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf1[i])
		return (NULL);
	while (buf1[i] && buf1[i] != '\n')
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buf1[i] && buf1[i] != '\n')
	{
		line[i] = buf1[i];
		i++;
	}
	if (buf1[i] && buf1[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_save(char *buf1)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buf1[i] && buf1[i] != '\n')
		i++;
	if (!buf1[i])
	{
		free(buf1);
		return (NULL);
	}
	line = (char *)ft_calloc((ft_strlen(buf1) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buf1[i])
		line[j++] = buf1[i++];
	free(buf1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_line(str[fd]);
	str[fd] = ft_save(str[fd]);
	return (line);
}

/* int	main(void)
{
	int	file;
	int	file2;

	file = open("texto.txt", O_RDWR);
	file2 = open("texto2.txt", O_RDWR);
	printf("file: %s\n", get_next_line(file));
	printf("file: %s\n", get_next_line(file2));
	printf("file: %s\n", get_next_line(file));
	printf("file: %s\n", get_next_line(file2));
	printf("file: %s\n", get_next_line(file));
	printf("file: %s\n", get_next_line(file2));
}
 */