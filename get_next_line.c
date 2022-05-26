/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodsanch <rodsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:30:45 by rodsanch          #+#    #+#             */
/*   Updated: 2022/05/26 16:58:21 by rodsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_save(str);
	return (line);
}

/* int	main(void)
{
	int	file;

	file = open("texto.txt", O_RDWR);
	char	*line = get_next_line(file);
	char	*line2 = get_next_line(file);
	char	*line3 = get_next_line(file);
	char	*line4 = get_next_line(file);

	printf("file: %s\n", line);
	printf("file: %s\n", line2);
	printf("file: %s\n", line3);
	printf("file: %s\n", line4);
	free(line);
	free(line2);
	free(line3);
	free(line4);
	close(file);
}
 */