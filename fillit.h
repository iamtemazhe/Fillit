/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:54:55 by jwinthei          #+#    #+#             */
/*   Updated: 2018/12/20 17:58:33 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# define CHRB '#'
# define CHRE '.'
# define SIZEB 4

int		chr_valid_checker(const char *src);
int		size_checker(size_t size);
int		map_checker(const char *map, const char *tetr);
int		tetr_checker(const char *map, size_t size);
int		tetrs_checker(char ***tetrs, char **map, size_t size);

char	*ft_strscpy(char *dst, const char *src,\
					size_t start, size_t nsize);

char	**tetrs_rewriter(char **tetrs);
#endif
