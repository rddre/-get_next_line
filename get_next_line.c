/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 22:54:01 by asaracut          #+#    #+#             */
/*   Updated: 2024/11/24 07:07:07 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char	document[128];
	ssize_t	document_fin;
	char	*res;
	int		i;

	i = 0;
	document_fin = read(fd, document, 127);
	if (document_fin < 0)
		return ("erreur d'encodage");
	document[document_fin] = '\0';
	while (document[i] != '\n' && document[i] != '\0')
		i++;
	res = malloc((sizeof(char) * i) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (document[i] != '\n' && document[i] != '\0')
	{
		res[i] = document[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
int	main(void)
{
	int		fd;
	
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (printf("error ouverture\n"));

	printf("\n\n%s\n\n\n", get_next_line(fd));
	
	close(fd);
	return (0);
}*/