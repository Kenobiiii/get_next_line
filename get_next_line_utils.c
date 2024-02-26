/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:41:20 by paromero          #+#    #+#             */
/*   Updated: 2024/02/26 09:42:48 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s1;
	int		i;
	int		tmp;

	s1 = (char *)s;
	tmp = ft_strlen(s1);
	i = 0;
	while (i <= tmp)
	{
		if ((unsigned char)c == s1[i])
		{
			return (&s1[i]);
		}
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	tmp = malloc(len + 1);
	if (!tmp)
		return (NULL);
	while (i < len && s[i + start] != '\0')
	{
		tmp[i] = s[i + start];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		a;
	int		b;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	i = 0;
	final = malloc((a + b + 1));
	if (!final)
		return (NULL);
	while (a--)
	{
		final[i] = s1[i];
		i++;
	}
	a = i;
	i = 0;
	while (b--)
		final[a++] = s2[i++];
	final[a] = '\0';
	return (final);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)s1;
	result = (char *)malloc(ft_strlen(s1) + 1);
	if (result == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
