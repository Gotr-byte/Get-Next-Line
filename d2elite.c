/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d2elite.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:21:40 by pbiederm          #+#    #+#             */
/*   Updated: 2022/06/16 18:57:36 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// the null termination at str join could be removed
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static size_t	ft_strlen(const char *s);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*get_next_line(int fd);
#define BUF_SIZE 4

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	n;

	s3 = (char *)(malloc(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(s3))
		return (NULL);
	i = 0;
	n = 0;
	while (i <= ft_strlen(s1))
	{
		s3[i] = s1[i];
		i++;
	}
	while (n < ft_strlen(s2))
	{
		s3[i] = s2[n];
		i++;
		n++;
	}
	return (s3);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


void	*ft_calloc(size_t count, size_t size)
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

void	ft_bzero(void *s, size_t n)
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

char	*get_next_line(int fd)
{
	static char	*buffy;
	int		bytes;
	char	*line;

	buffy = calloc(BUF_SIZE, sizeof(*buffy));
	// the following line needs some work
	line = calloc(BUF_SIZE, sizeof(*buffy));
	if(!buffy)
		return (NULL);
	if(!line)
		return (NULL);
	while ((bytes = read(fd, buffy, BUF_SIZE)) > 0)
	{	
		line = ft_strjoin(line, buffy);
		printf ("%s", buffy);
		if (ft_strrchr(buffy, '\n'))
			break ;
	}
	return(line);
}

int	main()
{
	int		fd_to_read = open("k3m.txt", O_RDONLY);
	int		fd_to_write = open("nk3m.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	char	*prt_line;
	
	if (fd_to_read == -1 || fd_to_write == -1)
	{
		printf ("No file to read or write to");
		return (-1);
	}
	prt_line = get_next_line(fd_to_read);
	prt_line = get_next_line(fd_to_read);
	prt_line = get_next_line(fd_to_read);
	prt_line = get_next_line(fd_to_read);
	prt_line = get_next_line(fd_to_read);
	prt_line = get_next_line(fd_to_read);
	prt_line = get_next_line(fd_to_read);
	prt_line = get_next_line(fd_to_read);
	prt_line = get_next_line(fd_to_read);
	prt_line = get_next_line(fd_to_read);
	prt_line = get_next_line(fd_to_read);
	prt_line = get_next_line(fd_to_read);
	prt_line = get_next_line(fd_to_read);
	prt_line = get_next_line(fd_to_read);
	prt_line = get_next_line(fd_to_read);
	
	// printf ("%s", prt_line);
	write (fd_to_write, prt_line, ft_strlen(prt_line));
	close(fd_to_read);
	close(fd_to_write);
}