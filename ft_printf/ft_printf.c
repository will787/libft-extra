/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:55:00 by wivieira          #+#    #+#             */
/*   Updated: 2023/12/14 16:10:48 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_select_params(const char value, va_list args)
{	
	if (value == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (value == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (value == 'd' || value == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (value == 'u')
		return (ft_uputnbr(va_arg(args, int)));
	else if (value == 'x' || value == 'X')
		return (ft_puthex_def(value, va_arg(args, unsigned int)));
	else if (value == 'p')
		return (ft_putpointer(value, (long long)va_arg(args, unsigned long)));
	else if (value == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *value, ...)
{	
	va_list	args;
	int		i;
	int		lenght;

	if (!value)
		return (-1);
	va_start (args, value);
	lenght = 0;
	i = 0;
	while (value[i])
	{	
		if (value[i] == '%' && ft_strrchr("cspiduxX%", value[i + 1]))
		{
			lenght += ft_select_params(value[i + 1], args);
			i++;
		}
		else
			lenght += ft_putchar(value[i]);
		i++;
	}
	va_end(args);
	return (lenght);
}
// - char {OK}
// - string {OK}
// - inteiro {OK}
// - decimal - mesma coisa com inteiro {OK}
// - ponteiro {OK}
// - unsigned {OK}
// - x - minúsculo {OK} 
// - X - maiúsuclo {OK}
// - % porcentagem sinal {OK}
// va_arg retorna o argumento atual
// os outros não retorna valor nenhum