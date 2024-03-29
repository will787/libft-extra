/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:47:45 by wivieira          #+#    #+#             */
/*   Updated: 2023/10/25 17:26:27 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{	
	const unsigned char	*rst;
	unsigned char		cd;

	cd = c;
	rst = s;
	if (n == 0)
		return (NULL);
	while (n > 0)
	{
		if (*rst == cd)
			return ((void *) rst);
		rst++;
		n--;
	}
	return (NULL);
}