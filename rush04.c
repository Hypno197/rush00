/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:54:12 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/22 16:57:04 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

char	check(int a, int b, int x, int y)
{
	if ((a == 0 && b == 0) || (a == x - 1 && b == y - 1 && x != 1 && y != 1))
		return ('A');
	else if ((a == 0 && b == y - 1) || (a == x - 1 && b == 0))
		return ('C');
	else if ((a == 0 && b < y - 1) || (b == 0 && a < x - 1))
		return ('B');
	else if ((a == x - 1 && b < y - 1) || (b == y - 1 && a < x - 1))
		return ('B');
	else
		return (' ');
}

void	rush(int x, int y)
{
	int		a;
	int		b;
	char	ch;

	a = 0;
	b = 0;
	if (x > 2147483645 || y > 2147483647 || x < 0 || y < 0)
	{
		write(1, "Valori non validi. Bella prova.", 32);
		return ;
	}
	while (a < x && b < y)
	{
		ch = check(a, b, x, y);
		ft_putchar(ch);
		if (a < x)
			a++;
		if (a == x && b != y)
		{
			b++;
			a = 0;
			ft_putchar('\n');
		}
	}
}
