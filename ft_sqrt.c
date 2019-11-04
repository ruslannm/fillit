/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:46:14 by rgero             #+#    #+#             */
/*   Updated: 2019/11/04 17:45:48 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int ret;
	int sqrt;

	ret = 1;
	sqrt = 0;
	while (ret <= nb / 2)
	{
		sqrt = ret * ret;
		if (sqrt == nb)
		{
			return (ret);
		}
		ret = ret + 1;
	}
	return (0);
}
