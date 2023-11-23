/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:33:42 by lgalloux          #+#    #+#             */
/*   Updated: 2023/11/22 17:32:22 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return(1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_printptr(char *ptr)
{
	int	i;

	i = 0;
	while (ptr)
	{
		write(1, &ptr, 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int nb)
{
	long	l_nb;
	int	len;
	int 	minus;

	l_nb = nb;
	len = 1;
	minus = 0;
	if (l_nb < 0)
	{
		l_nb = l_nb * -1;
		write(1, "-", 1);
		minus = 1;
		len++;
	}
	if (l_nb > 9)
	{
		len = ft_printnbr(l_nb / 10) + 1 + minus;
	}
	write(1, &(char){l_nb % 10 + '0'}, 1);
	return (len);
}

int	ft_which_type(char type, va_list l_arg)
{
	if (type == 'c')
		return (print_char(va_arg(l_arg, int)));
	else if (type == 's')
		return (ft_printstr(va_arg(l_arg, char *)));
	else if (type == 'p')
		return (ft_printptr(va_arg(l_arg, char *)));
	else if (type == 'd' || type == 'i')
		return (ft_printnbr(va_arg(l_arg, int)));
	// else if (type == 'u')
	// 	printf("%c", 'u');
	// else if (type == 'x')
	// 	printf("%c", 'x');
	// else if (type == 'X')
	// 	printf("%c", 'X');
	else if (type == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list l_arg;
	int	i;
	int	len;
	
	va_start(l_arg, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_which_type(format[i + 1], l_arg);
			i += 2;
		}
		else
		{
			write(1, &format[i++], 1);
			len++;
		}
	}
	return (len);
}

int	main(void)
{
	char *test = "le test habituel";
	printf(" -> %d\n",ft_printf("%d", test));
	printf("-----------------\n");
	printf(" -> %d",printf("%p", test));
}