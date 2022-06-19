/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:27:07 by pbiederm          #+#    #+#             */
/*   Updated: 2022/06/14 09:20:35 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// 123456\n
// ABCDEF\n

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s3;
	size_t			i[2];

	s3 = (char *)(malloc(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(s3))
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	while (i[0] < ft_strlen(s1))
	{
		s3[i[0]] = s1[i[0]];
		i[0]++;
	}
	while (i[1] < ft_strlen(s2))
	{
		s3[i[0]] = s2[i[1]];
		i[0]++;
		i[1]++;
	}
		s3[i[0]] = '\0';
	return (s3);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		subs = (char *)malloc((1) * sizeof(char));
		subs[0] = '\0';
		return (subs);
	}
	else if (len >= ft_strlen(s + start))
		subs = (char *)malloc(ft_strlen(s) - start + 1);
	else
		subs = (char *)malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while ((i < len) && (s[start + i] != '\0'))
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
// will point to newline so
char	*ft_strrchr(const char *s, int c)
{
	char	*h;
	char	*v;
	size_t	t;

	h = (char *)s;
	t = ft_strlen(s) + 1;
	while ((t-- + 1) > 0)
	{
		if (*(h + t) == (char)c)
		{
			v = (h + t);
			return (v);
		}
		if (t == 0)
			return (NULL);
	}
	return (NULL);
}

static void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*pt;

	pt = s;
	i = 0;
	while (i < n)
	{
			pt[i] = 0;
			i++;
	}
}

static void	*ft_calloc(size_t count, size_t size)
{
	char	*point_to_calloc;
	size_t	t;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	t = count * size;
	point_to_calloc = malloc(t);
	if (!point_to_calloc)
		return (NULL);
	ft_bzero(point_to_calloc, t);
	return (point_to_calloc);
}

char	*get_next_line(int fd)
{
	static char	*buffy;
	char		*line;
	char		*tmp_line;
	int			bytes;
	char		c;
	int			i;

	i = 0;
	if (fd == -1)
	{
		return (NULL);
	}
	while ((bytes = read(fd, buffy, 3)) > 0)
	{
		if (c == '\n')
		{
			break ;
		}
		line[i++] = c;
	}
	return (line);
}

int	main()
{
	int	fd_to_read = open("text.txt", O_RDONLY);

	printf ("%s", get_next_line(fd_to_read));
}