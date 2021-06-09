/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_with_minus_case_b.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 01:34:09 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:01:31 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_p_with_minus_case_b(t_flag *flags, char *heap, \
	char *n_str)
{
	if (flags->acc > (long long)ft_strlen(n_str))
		ft_putstr(heap);
	else
		ft_putstr(n_str);
}
