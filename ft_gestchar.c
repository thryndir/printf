/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:35:47 by lgalloux          #+#    #+#             */
/*   Updated: 2023/11/24 16:21:51 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_printstr("(null)");
		return (6);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	cpt_str;

	cpt_str = 0;
	while (*str != '\0')
	{
		str++;
		cpt_str++;
	}
	return (cpt_str);
}
