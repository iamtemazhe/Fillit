/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:36:55 by jwinthei          #+#    #+#             */
/*   Updated: 2018/12/20 18:11:17 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int		readncheck(int fd, char ***map)
{
	int		i;
	int		j;
	int		g;
	char	*line;

	i = 1;
	j = 0;
	while ((g = get_next_line(fd, &line)))
	{
		if (g == -1 || chr_valid_checker(line))
			return (ft_nstrerr(-1, map) + (g == 1 ? ft_strerr(0, &line) : 0));
		if (((i % (SIZEB + 1)) && ft_strlen(line) != SIZEB) ||\
			(!(i % (SIZEB + 1)) && ft_strcmp(line, "")))
			return (ft_nstrerr(-1, map) + ft_strerr(0, &line));
		if (!(map[0][j] = ft_strrealloc(map[0][j], line, ft_strlen(line))))
			return (ft_nstrerr(-1, map) + ft_strerr(0, &line));
		ft_strdel(&line);
		if (!(i++ % (SIZEB + 1)))
			if (++j > 25)
				return (ft_nstrerr(-1, map));
	}
	if ((i != 1 && !((i - 1) % (SIZEB + 1))) || (i == 1))
		return (ft_nstrerr(-1, map));
	return (j = size_checker(j));
}

static char		*tetr_mover(char *dst, const char *src,\
							size_t sdvig, size_t size)
{
	size_t	len;

	len = (size_t)(ft_strrchr(src, CHRB) - src);
	if (size < SIZEB && sdvig && sdvig < size * size)
	{
		if ((sdvig % size) && (src[2] == CHRB || src[6] == CHRB))
			return (dst);
		else if (sdvig == 2 && src[0] == CHRB && src[1] == CHRB &&\
								src[4] == CHRB && src[5] == CHRB)
			return (dst);
		else if (sdvig != 1 && src[1] == CHRB &&\
				(src[8] == CHRB || src[9] == CHRB))
			return (dst);
	}
	if (dst && *dst)
		ft_strdel(&dst);
	if ((sdvig + len + (len / SIZEB) * (size - SIZEB)) > ((size * size) - 1))
		return (NULL);
	if (!(dst = ft_strnew(size * size)))
		return (NULL);
	ft_memset(dst, CHRE, size * size);
	return (dst = ft_strscpy(dst, src, sdvig, size));
}

static char		*map_writer(char *map, const char *tetr, char chr)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (tetr[i] == CHRB)
			map[i] = chr;
		i++;
	}
	return (map);
}

static int		fillit(char *map, char **tetrs, size_t it, size_t size)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (!tetrs[it])
		return (0);
	while ((tmp = tetr_mover(tmp, tetrs[it], i++, size)))
	{
		if (!tetr_checker(tmp, size) && !map_checker(map, tmp))
		{
			map = map_writer(map, tmp, 'A' + it);
			if (!fillit(map, tetrs, it + 1, size))
				return (ft_strerr(0, &tmp));
			map = map_writer(map, tmp, CHRE);
		}
	}
	return (ft_strerr(1, &tmp));
}

int				main(int argc, char **argv)
{
	int		size;
	int		fd;
	char	*map;
	char	**tetrs;

	if (argc != 2)
		return (ft_puterr(0, "usage: ./fillit source_file"));
	if (((fd = open(argv[1], O_RDONLY)) == -1))
		return (ft_puterr(0, "error"));
	if (!(tetrs = ft_nstrnew(26)))
		return (ft_puterr(0, "error"));
	if ((size = readncheck(fd, &tetrs)) == -1)
		return (ft_puterr(0, "error"));
	if (tetrs_checker(&tetrs, &map, size))
		return (ft_puterr(0, "error") + ft_nstrerr(0, &tetrs));
	while (fillit(map, tetrs, 0, size))
	{
		size++;
		ft_strdel(&map);
		if (!(map = ft_strfnew(size * size, CHRE)))
			return (ft_puterr(0, "error") + ft_nstrerr(0, &tetrs));
	}
	ft_putnendl(map, size);
	close(fd);
	return (ft_nstrerr(0, &tetrs) + ft_strerr(0, &map));
}
