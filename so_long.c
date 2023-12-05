/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alirola- <alirola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:14:32 by alirola-          #+#    #+#             */
/*   Updated: 2023/12/05 16:15:46 by alirola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
/*int main(void)
{
	int fd;
	char *s;
	fd = open("./mapa", O_RDONLY);
	s = get_next_line(fd);
	//printf("%s", s);

	printf("%d", fd);
	return(0);
}*/

int	main(void)
{
	int		fichero;
	char	*line;

	fichero = open("mapa", O_RDONLY);
	line = get_next_line(fichero);
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line (fichero);
	}
	printf("\n");
	close(fichero);
	free(line);
}