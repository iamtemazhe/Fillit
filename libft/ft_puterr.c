/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:58:42 by jwinthei          #+#    #+#             */
/*   Updated: 2018/12/20 15:58:46 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_puterr(int retv, const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			ft_putchar(s[i++]);
		ft_putchar('\n');
	}
	return (retv);
}
