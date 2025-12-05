/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capeinad <capeinad@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 01:49:20 by capeinad          #+#    #+#             */
/*   Updated: 2025/12/05 01:50:28 by capeinad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *format, ...);
int	ft_putstr(char	*str);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_puthex(unsigned int nbr, char c);

#endif
