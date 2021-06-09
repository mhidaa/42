/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_xX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:51:28 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 02:59:44 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_free(char *hex_str, t_flag *flags)
{
	free(hex_str);
	flags->error = 1;
}

static void	ft_print_xX(t_flag *flags, char *heap, \
	char *hex_str, long long width)
{
	long long	i;

	i = 0;
	if (flags->flag_minus)
		ft_print_di_with_minus(flags, heap, hex_str, width);
	if (flags->flag_zero && !(flags->flag_minus))
		ft_print_di_with_zero(flags, heap, hex_str, width);
	if (!(flags->flag_minus) && !(flags->flag_zero))
	{
		if (flags->acc_is_zero && flags->n_zero)
			while (i++ < width)
				write(1, " ", 1);
		else
			ft_putstr(heap);
	}
}

void	ft_case_xX(t_flag *flags, va_list *ap, ssize_t *put_cnt)
{
	unsigned int	ui;
	char			*heap;
	char			*hex_str;
	long long		width;

	ui = (unsigned int)va_arg(*ap, unsigned int);
	if (ui == 0)
		flags->n_zero = 1;
	hex_str = ft_uitohex_str(ui, flags);
	if (hex_str == NULL)
		flags->error = 1;
	if (flags->error)
		return ;
	width = 0;
	width = ft_set_width_for_di(flags, width, (long long)ft_strlen(hex_str));
	heap = (char *)malloc(sizeof(char) * (width + 1));
	if (!heap)
		ft_free(hex_str, flags);
	if (flags->error)
		return ;
	ft_set_heap_xX(flags, width, heap, hex_str);
	ft_print_xX(flags, heap, hex_str, width);
	*put_cnt += width;
	free(hex_str);
	free(heap);
}
