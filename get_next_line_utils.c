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

char	*ft_strjoin(char const *s1, char const *s2)
{
    char	*final;
    int		a;
    int		b;
    int		i;

    if (!s2)
        return (NULL);
    a = s1 ? ft_strlen(s1) : 0;
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
