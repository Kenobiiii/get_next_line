/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:40:22 by paromero          #+#    #+#             */
/*   Updated: 2024/02/01 11:25:27 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*ft_free_storage(char *storage)
{
	int	new_storage;
	
	new_storage = ft_strchr(storage, '\n');
}

char	*get_next_line(int fd)
{
	return (NULL);
}
