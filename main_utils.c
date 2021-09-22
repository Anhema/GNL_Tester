/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:03:13 by aherrero          #+#    #+#             */
/*   Updated: 2021/09/02 18:10:05 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*black = "\033[0;30m";
char	*red = "\033[0;31m";
char	*green = "\033[0;32m";
char	*yellow = "\033[0;33m";
char	*blue = "\033[0;34m";
char	*purple = "\033[0;35m";
char	*cyan = "\033[0;36m";
char	*white = "\033[0;37m";
char	*normal = "\033[0m";

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

void	print_file_name(char **argv, int file,char *color)
{
	int		i;
	char	*str;

	i = -1;
	str = argv[file];
	while (str[++i])
		str[i] = ft_toupper(str[i]);
	print_color_str("\n-------", color);
	print_color_str(str, color);
	print_color_str("-------\n", color);
}

void print_color_str(char *str, char *color)
{
	printf("%s", color);
	printf("%s", str);
	printf("\033[0m");
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}

void delay(float number)
{
	int milliseconds = 1000000 * number;
	clock_t start_time = clock();
	while(clock() < start_time + milliseconds)
		;
}
