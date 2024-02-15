/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:40:22 by paromero          #+#    #+#             */
/*   Updated: 2024/02/15 10:21:26 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_free(char *buffer, char buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	ft_next(char *buffer)
{
	
}

char	ft_line(char *buffer)
{
	int		i;
	char	*temp;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	temp = ft_substr(buffer, 0, i);
	return (temp);
}

char	*ft_read(int fd, char *ret)
{
	char	buf;
	int		ret;

	ret = read(fd, &buf, 1);
	if (ret == -1)
		return (NULL);
	if (ret == 0)
		return (buffer);
	buffer = ft_free(buffer, buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	if (!fd)
		return (NULL);
}
