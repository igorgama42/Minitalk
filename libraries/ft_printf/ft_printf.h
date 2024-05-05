/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <igama@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:03:49 by igama             #+#    #+#             */
/*   Updated: 2023/11/28 22:04:09 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void				ft_putchar(char c);
void				ft_putnbr(int n);
int					ft_digits(int n);
void				ft_putnbr_uns(unsigned int n);
int					ft_digits_uns(unsigned int n);
void				ft_putnbr_base(unsigned long int n);
unsigned long int	ft_digits_base(unsigned long int n);
int					ft_printf(const char *str, ...);
int					ft_putstr(char *c);
size_t				ft_strlen(const char *s);
void				ft_putx(unsigned long int n);
unsigned long int	ft_digits_x(unsigned long int n);
void				ft_put_cx(unsigned long int n);
unsigned long int	ft_digits_cx(unsigned long int n);

#endif
