/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot2exl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:45:23 by pbiederm          #+#    #+#             */
/*   Updated: 2022/06/10 14:05:15 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main()
{
	FILE *file_to_read = fopen("k3m.txt", "r");
	FILE *file_to_write = fopen("nk3m.txt", "w");
	char	c;

	if (file_to_read == NULL || file_to_write == NULL)
	{
		printf("no file to read");
		return (-1);
	}
	while ((c = fgetc(file_to_read)) != EOF)
	{
		if (c == '.')
		{
			c = '!';
		}
		fputc(c, file_to_write);
	}
	fclose(file_to_read);
	fclose(file_to_write);
}	
