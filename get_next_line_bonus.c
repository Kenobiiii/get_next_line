/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:40:22 by paromero          #+#    #+#             */
/*   Updated: 2024/03/12 09:47:35 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		byt;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	byt = 1;
	while ((!ft_strchr(str, '\n')) && byt != 0)
	{
		byt = read(fd, buff, BUFFER_SIZE);
		if (byt == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byt] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*ft_line(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	temp = (char *)malloc((i + 2) * sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		temp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_save(char	*str)
{
	int		i;
	int		j;
	char	*save;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	save = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!save)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		save[j++] = str[i++];
	save[j] = '\0';
	free(str);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*linea;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	linea = ft_line(str[fd]);
	str[fd] = ft_save(str[fd]);
	return (linea);
}
/*
int main(int argc, char **argv)
{
    int fd;
    char *line;
    int i = 1;

    while (i < argc)
    {
        fd = open(argv[i], O_RDONLY);
        if (fd == -1)
        {
            printf("Error opening file %s\n", argv[i]);
            return (1);
        }

        line = get_next_line(fd);
        if (line != NULL)
        {
            printf("%s\n", line);
            free(line);
        }

        close(fd);
        i++;
    }

    return (0);
}
*/
