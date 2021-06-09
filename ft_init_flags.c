/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:46:35 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 02:59:55 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flag *flags)
{
	flags->flag_zero = 0;
	flags->flag_minus = 0;
	flags->mfw = 0;
	flags->acc = 0;
	flags->acc_exists = 0;
	flags->conv_specifier = -1;
	flags->dot_exists = 0;
	flags->acc_is_zero = 0;
	flags->null = 0;
	flags->n_minus = 0;
	flags->n_zero = 0;
	flags->acc_star_minus = 0;
	flags->acc_star_exists = 0;
	flags->space_perc_to_next = 0;
	flags->error = 0;
}
