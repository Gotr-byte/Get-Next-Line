/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lseek.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:43:00 by pbiederm          #+#    #+#             */
/*   Updated: 2022/06/13 12:57:50 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_putnbr (char c)
{
	write(1, &c, 1);
}

void ft_putstr (char *s)
{
	int	n;

	n = 0;
	while (s[n])
	{
		write(1, s[n], 1);
		n++;
	}
}

int	main ()
{
	int fd;
	int ret;
	char	buf[BUF_SIZE + 1];

	fd = open ("42", O_RDONLY);
	if (fd == -1)
	{
		printf ("Error while opening file");
		return (1);
	}
	while (ret = read(fd, buf, BUF_SIZE))
	{
		buf[ret] = '\0';
		ft_putnbr(ret);
		ft_putstr(buf);
	}
	ft_putnbr(ret);
	if (close(fd) == -1)
	{
		ft_putstr("Close error");
		return (-1);
	}
	return(0);
}