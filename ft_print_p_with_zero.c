/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_with_zero.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 00:44:40 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:28:02 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_p_with_zero(t_flag *flags, char *heap, \
	char *n_str, long long width)
{
	if (!(flags->acc_exists) && flags->mfw)
		ft_print_p_with_zero_case_a(flags, heap, n_str, width);
	if (flags->acc_exists && !(flags->mfw))
		ft_print_p_with_zero_case_b(flags, heap, n_str, width);
	if (flags->acc_exists && flags->mfw)
		ft_putstr(heap);
	if (!(flags->acc_exists) && !(flags->mfw))
		ft_putstr(n_str);
}
