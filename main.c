/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:15:28 by pbiederm          #+#    #+#             */
/*   Updated: 2022/06/16 18:35:49 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int count;

int	increment()
{
	count = count + 1;
	return count;
}

int	main()
{
	int	value;

	value = increment ();
	value = increment ();
	value = increment ();

	printf("%d", value);
	return 0;
}