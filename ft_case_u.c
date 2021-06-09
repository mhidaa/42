/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:51:07 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 02:59:30 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_free(char *ui_str, t_flag *flags)
{
	free(ui_str);
	flags->error = 1;
}

static void	ft_print_u(t_flag *flags, char *heap, \
	char *ui_str, long long width)
{
	long long	i;

	i = 0;
	if (flags->flag_minus)
		ft_print_u_with_minus(flags, heap, ui_str, width);
	if (flags->flag_zero && !(flags->flag_minus))
		ft_print_u_with_zero(flags, heap, ui_str, width);
	if (!(flags->flag_minus) && !(flags->flag_zero))
	{
		if (flags->acc_is_zero && flags->n_zero)
			while (i++ < width)
				write(1, " ", 1);
		else
			ft_putstr(heap);
	}
}

void	ft_case_u(t_flag *flags, va_list *ap, ssize_t *put_cnt)
{
	unsigned int	ui;
	char			*heap;
	char			*ui_str;
	long long		width;

	ui = (unsigned int)va_arg(*ap, unsigned int);
	ui_str = ft_uitoa(ui);
	if (ui_str == NULL)
		flags->error = 1;
	if (flags->error)
		return ;
	if (ui == 0)
		flags->n_zero = 1;
	width = 0;
	width = ft_set_width_for_di(flags, width, (long long)ft_strlen(ui_str));
	heap = (char *)malloc(sizeof(char) * (width + 1));
	if (!heap)
		ft_free(ui_str, flags);
	if (flags->error)
		return ;
	ft_set_heap_u(flags, width, heap, ui_str);
	ft_print_u(flags, heap, ui_str, width);
	*put_cnt += width;
	free(ui_str);
	free(heap);
}
