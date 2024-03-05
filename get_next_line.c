/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:40:22 by paromero          #+#    #+#             */
/*   Updated: 2024/02/26 12:26:16 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char		*str = NULL;
	char			*linea;

	if (fd <= 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = ft_read(fd, str);
	if (!str)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	linea = ft_line(str);
	str = ft_save(str);
	return (linea);
}
/*

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return (1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file\n");
        return (1);
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return (0);
}
*/
