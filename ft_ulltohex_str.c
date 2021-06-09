/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltohex_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:22:13 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:23:35 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_ulltohex_str3(char *hex_str, t_flag *flags)
{
	long long	j;

	j = 0;
	if ((flags->null && !(flags->dot_exists)) || \
		(flags->null && flags->acc_star_minus))
	{
		hex_str[j++] = '0';
		hex_str[j++] = 'x';
		hex_str[j++] = '0';
		hex_str[j] = '\0';
	}
	else
	{
		hex_str[j++] = '0';
		hex_str[j++] = 'x';
		if (flags->null && flags->acc_exists)
			while (j < flags->acc + 2)
				hex_str[j++] = '0';
		hex_str[j] = '\0';
	}
}

static void	ft_ulltohex_str2(char *hex_str, unsigned long long ull, \
	long long i, t_flag *flags)
{
	if (ull > 0)
	{
		hex_str[i] = '\0';
		while (ull > 0)
		{
			if ((ull % 16) < 10)
				hex_str[i - 1] = ull % 16 + '0';
			else
				hex_str[i - 1] = ull % 16 + 87;
			ull /= 16;
			i--;
		}
		hex_str[1] = 'x';
		hex_str[0] = '0';
	}
	else
		ft_ulltohex_str3(hex_str, flags);
}

char	*ft_ulltohex_str(unsigned long long ull, t_flag *flags)
{
	char				*hex_str;
	unsigned long long	tmp_ull;
	long long			i;

	i = 0;
	tmp_ull = ull;
	while (tmp_ull > 0)
	{
		tmp_ull /= 16;
		i++;
	}
	i += 2;
	if ((flags->null && flags->acc_star_minus) || \
		(flags->null && !(flags->dot_exists)))
		i++;
	if (flags->null && flags->dot_exists && !(flags->acc_exists))
		i = 2;
	hex_str = (char *)malloc(sizeof(char) * (i + 1));
	if (!hex_str)
		return (NULL);
	ft_ulltohex_str2(hex_str, ull, i, flags);
	return (hex_str);
}
