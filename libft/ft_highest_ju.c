/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_highest_ju.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 22:13:50 by adaly             #+#    #+#             */
/*   Updated: 2017/09/15 16:59:37 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**finds the largest uintmax_t in an array of them and returns its index
*/

uintmax_t	ft_highest_ju(uintmax_t *array, uintmax_t array_size)
{
	uintmax_t	counter;
	uintmax_t	largest;

	largest = 0;
	counter = 0;
	while (array && counter < array_size)
	{
		largest = (array[counter] > largest) ? array[counter] : largest;
		++counter;
	}
	return (largest);
}

uintmax_t	ft_lowest_ju(uintmax_t *array, uintmax_t array_size)
{
	uintmax_t	counter;
	uintmax_t	smallest;

	smallest = 0;
	counter = 0;
	while (array && counter < array_size)
	{
		smallest = (array[counter] < smallest) ? array[counter] : smallest;
		if (!counter)
			smallest = array[counter];
		++counter;
	}
	return (smallest);
}

uintmax_t	ft_ihighest_ju(uintmax_t *array, uintmax_t array_size)
{
	uintmax_t	counter;
	uintmax_t	largest;

	largest = 0;
	counter = 0;
	while (array && counter < array_size)
	{
		largest = (array[counter] > array[largest]) ? counter : largest;
		++counter;
	}
	return (largest);
}

uintmax_t	ft_ilowest_ju(uintmax_t *array, uintmax_t array_size)
{
	uintmax_t	counter;
	uintmax_t	smallest;

	smallest = 0;
	counter = 0;
	while (array && counter < array_size)
	{
		smallest = (array[counter] < array[smallest]) ? counter : smallest;
		++counter;
	}
	return (smallest);
}
