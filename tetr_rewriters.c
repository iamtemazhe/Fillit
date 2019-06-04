/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_rewriters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:40:56 by jwinthei          #+#    #+#             */
/*   Updated: 2018/12/20 17:14:28 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char			*ft_strscpy(char *dst, const char *src,\
							size_t start, size_t nsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = start;
	while (src[i] && dst[j])
	{
		dst[j] = src[i];
		if (!((i + 1) % SIZEB))
			j += nsize - SIZEB;
		j++;
		i++;
	}
	return (dst);
}

static void		ft_strswap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static char		**move_left(char **s)
{
	int	i;
	int	j;
	int	flaq;

	j = -1;
	while (s[++j])
	{
		flaq = 1;
		i = 0;
		while (s[j][i] && flaq)
		{
			if (s[j][0] == CHRE && s[j][4] == CHRE &&\
				s[j][8] == CHRE && s[j][12] == CHRE)
				while (s[j][i])
				{
					if (s[j][i] == CHRB)
						ft_strswap(&s[j][i], &s[j][i - 1]);
					i++;
				}
			else
				flaq = 0;
			i = 0;
		}
	}
	return (s);
}

static char		**move_top(char **s)
{
	int	i;
	int	j;
	int	flaq;

	j = -1;
	while (s[++j])
	{
		flaq = 1;
		i = 0;
		while (s[j][i] && flaq)
		{
			if (s[j][0] == CHRE && s[j][1] == CHRE &&\
				s[j][2] == CHRE && s[j][3] == CHRE)
				while (s[j][i])
				{
					if (s[j][i] == CHRB)
						ft_strswap(&s[j][i], &s[j][i - 4]);
					i++;
				}
			else
				flaq = 0;
			i = 0;
		}
	}
	return (s);
}

char			**tetrs_rewriter(char **tetrs)
{
	tetrs = move_top(tetrs);
	tetrs = move_left(tetrs);
	return (tetrs);
}
