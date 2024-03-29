/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:14:19 by wivieira          #+#    #+#             */
/*   Updated: 2023/10/25 18:08:16 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{	
	char	*str;

	str = (char *) s;
	while (n > 0)
	{	
		str[n - 1] = c;
		n--;
	}
	return (s);
}
