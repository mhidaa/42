/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_with_minus_case_b.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 01:34:09 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:00:54 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_di_with_minus_case_b(t_flag *flags, char *heap, \
	char *n_str)
{
	long long	len;

	len = ft_strlen(n_str);
	if (flags->acc >= len)
		ft_putstr(heap);
	else
		ft_putstr(n_str);
}
