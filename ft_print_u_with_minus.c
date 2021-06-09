/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_with_minus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 00:44:43 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:02:43 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_u_with_minus(t_flag *flags, char *heap, \
	char *n_str, long long width)
{
	if (!(flags->acc_exists) && flags->mfw)
		ft_print_u_with_minus_case_a(flags, heap, n_str, width);
	if (flags->acc_exists && !(flags->mfw))
		ft_print_u_with_minus_case_b(flags, heap, n_str);
	if (flags->acc_exists && flags->mfw)
		ft_print_u_with_minus_case_c(flags, heap, n_str, width);
	if (!(flags->acc_exists) && !(flags->mfw))
		ft_putstr(n_str);
}
