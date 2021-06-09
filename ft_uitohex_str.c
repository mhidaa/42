/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitohex_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:58:03 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:08:10 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_uitohex_str2(char *hex_str, unsigned int ui, \
	long long i, t_flag *flags)
{
	hex_str[i] = '\0';
	if (flags->n_zero)
		hex_str[i - 1] = '0';
	while (ui > 0)
	{
		if ((ui % 16) < 10)
			hex_str[i - 1] = ui % 16 + '0';
		else
			hex_str[i - 1] = ui % 16 + 87;
		ui /= 16;
		i--;
	}
}

char	*ft_uitohex_str(unsigned int ui, t_flag *flags)
{
	char			*hex_str;
	unsigned int	tmp_ui;
	long long		i;

	i = 0;
	tmp_ui = ui;
	if (ui == 0)
		i++;
	while (tmp_ui > 0)
	{
		tmp_ui /= 16;
		i++;
	}
	hex_str = (char *)malloc(sizeof(char) * (i + 1));
	if (!hex_str)
		return (NULL);
	ft_uitohex_str2(hex_str, ui, i, flags);
	if (flags->conv_specifier == 7)
		hex_str = ft_strtoupper(hex_str);
	return (hex_str);
}
