/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:20:00 by jwinthei          #+#    #+#             */
/*   Updated: 2018/12/06 16:20:47 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrealloc(char *dst, const char *src, size_t n)
{
	char	*tmp;
	char	*sub;

	if (!src && dst)
		return (dst);
	if (!src && !dst)
		return (NULL);
	if (!(sub = ft_strsub(src, 0, n)))
		return (NULL);
	if (!dst)
		return (sub);
	if (!(tmp = ft_strdup(dst)))
		return (NULL);
	free(dst);
	if (!(dst = ft_strjoin(tmp, sub)))
		return (NULL);
	free(tmp);
	free(sub);
	return (dst);
}
