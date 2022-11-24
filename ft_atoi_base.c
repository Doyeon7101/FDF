/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:35:53 by dpark             #+#    #+#             */
/*   Updated: 2022/11/24 20:51:10 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	dublicate_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	invalid_base(char *base)
{
	int	i;

	if (dublicate_check(base) == 1)
		return (1);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	if (i <= 1)
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\n' \
		|| c == '\t' || c == '\v' \
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	return_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	number;
	int	negative;
	int	size;

	if (invalid_base(base))
		return (0);
	i = 0;
	while (is_space(str[i]))
		i++;
	i += 2;
	negative = 1;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			negative *= -1;
	size = 0;
	while (base[size])
		size++;
	number = 0;
	while (return_base(str[i], base) != -1)
		number = (number * size) + (return_base(str[i++], base) * negative);
	return (number);
}
