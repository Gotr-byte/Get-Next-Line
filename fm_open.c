/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fm_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:19:38 by pbiederm          #+#    #+#             */
/*   Updated: 2022/06/13 13:35:29 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static void ft_putchr (int c)
{
	write(1, &c, 1);
}

int	main ()
{
	int fd;
	
	// fd = open ("test.txt", O_RDONLY);
	fd = open ("42", O_WRONLY | O_CREAT);
	if (fd == -1)
	{
		printf ("Open failed\n");
	}
	write (1, &fd, sizeof(fd));
	return (0);	
}