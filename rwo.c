/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rwo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:24:14 by pbiederm          #+#    #+#             */
/*   Updated: 2022/06/10 15:54:22 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int argc, char* argv[])
{
	int fd; 
	char buf[14];
	// write

	fd = open("k3mntxt", O_CREAT | O_WRONLY, 0600);
	if (fd == -1)
	{
		printf("File descriptor -1. Failed to create and open the file. \n");
		exit(1);
	}
	write (fd, "Hello World!\n", 13);
	// read
	fd=open("k3mntxt", O_RDONLY);

	if (fd == -1)
	{
		printf ("File descriptor -1. Failed to open and read the file. \n");
		exit(1);
	}	
	
	read (fd, buf, 13);
	buf[13]='\0';
	printf("buf: %s\n", buf);
	close (fd);
	return (0);
}