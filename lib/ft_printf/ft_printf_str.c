/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:28:17 by gicomlan          #+#    #+#             */
/*   Updated: 2024/07/20 03:28:20 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	THIS FCT CAN MAKE U TELEPORT
*/

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		write(1, &str[idx], 1);
		idx++;
	}
}

/*
	THIS FT PRINT NULL IF THE POINTER IS NULL
					&&
	RETURN THE LEN OF THE STR
*/

int	print_str(char *str)
{
	int	idx;

	idx = 0;
	if (str == NULL)
	{
		ft_putstr(ADDR_NULL);
		return (6);
	}
	while (str[idx])
	{
		write(1, &str[idx], 1);
		idx++;
	}
	return (idx);
}
