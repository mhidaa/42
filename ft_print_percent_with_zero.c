/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_with_zero.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:04:43 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:02:12 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_percent_with_zero(long long width)
{
	long long	i;

	i = 0;
	while (i++ < width - 1)
		write(1, "0", 1);
	write(1, "%", 1);
}
