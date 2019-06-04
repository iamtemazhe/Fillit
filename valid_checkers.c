/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:41:17 by jwinthei          #+#    #+#             */
/*   Updated: 2018/12/20 18:11:43 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int			chr_valid_checker(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
		if (src[i] == CHRB)
			i++;
		else if (src[i] == CHRE)
			i++;
		else
			return (-1);
	return (0);
}

int			size_checker(size_t size)
{
	size_t	n;

	size++;
	if (size <= SIZEB / 2)
		return (SIZEB / 2);
	n = size;
	while (size * SIZEB <= n * n)
		n--;
	return (++n);
}

int			map_checker(const char *map, const char *tetr)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != CHRE && tetr[i] != CHRE)
			return (1);
		i++;
	}
	return (0);
}

int			tetr_checker(const char *tetr, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if ((k = ft_chrcnt(tetr, CHRB)) != SIZEB)
		return (-1);
	i = 0;
	j = 0;
	while (i < size * size)
	{
		if (tetr[i] == CHRB && k > 1)
		{
			if (i < (size * (size - 1)) && tetr[i + size] == CHRB)
				k--;
			if (j < (size - 1) && tetr[i + 1] == CHRB)
				k--;
		}
		if (++j == size)
			j = 0;
		i++;
	}
	return ((k != 1) ? -1 : 0);
}

int			tetrs_checker(char ***tetrs, char **map, size_t size)
{
	int	i;

	i = -1;
	while (tetrs[0][++i])
		if (tetr_checker(tetrs[0][i], SIZEB))
			return (-1);
	*tetrs = tetrs_rewriter(*tetrs);
	if (!(*map = ft_strfnew(size * size, CHRE)))
		return (-1);
	return (0);
}
