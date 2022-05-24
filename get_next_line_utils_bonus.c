/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodsanch <rodsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:56:34 by rodsanch          #+#    #+#             */
/*   Updated: 2022/05/24 12:01:31 by rodsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*double_str;
	int		i;
	int		j;

	double_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1 == NULL || s2 == NULL || double_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		double_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		double_str[i] = s2[j];
		i++;
		j++;
	}
	double_str[i] = '\0';
	return (double_str);
}

char	*ft_strchr(char const *str, int c)
{
	while (*str != '\0' && (char)c != *str)
		str++;
	if ((char)c == *str)
		return ((char *)str);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	i;

	i = count * size;
	result = malloc(i);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, i);
	return (result);
}
