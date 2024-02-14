/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:40:22 by paromero          #+#    #+#             */
/*   Updated: 2023/12/11 12:35:15 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	ft_free(char *buffer, char buf)
{
	char	*tmp;
	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	ft_next(char *buffer)
{
	
}

char	ft_line(char *buffer)
{}

char	ft_*read(int fd, char *ret)
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
