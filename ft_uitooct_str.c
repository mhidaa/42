/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitooct_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:57:35 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:08:15 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_uitooct_str2(char *oct_str, unsigned int ui, \
	size_t i, t_flag *flags)
{
	oct_str[i] = '\0';
	if (flags->n_zero)
		oct_str[i - 1] = '0';
	while (ui > 0)
	{
		oct_str[i - 1] = ui % 8 + '0';
		ui /= 8;
		i--;
	}
}

char	*ft_uitooct_str(unsigned int ui, t_flag *flags)
{
	char			*oct_str;
	unsigned int	tmp_ui;
	size_t			i;

	i = 0;
	tmp_ui = ui;
	if (ui == 0)
		i++;
	while (tmp_ui > 0)
	{
		tmp_ui /= 8;
		i++;
	}
	oct_str = (char *)malloc(sizeof(char) * (i + 1));
	if (!oct_str)
		return (NULL);
	ft_uitooct_str2(oct_str, ui, i, flags);
	return (oct_str);
}
