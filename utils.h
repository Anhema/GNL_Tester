/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:02:06 by aherrero          #+#    #+#             */
/*   Updated: 2021/09/02 18:11:23 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <time.h>

extern char	*black;
extern char	*red;
extern char	*green;
extern char	*yellow;
extern char	*blue;
extern char	*purple;
extern char	*cyan;
extern char	*white;
extern char	*normal;

extern char *file_1[15];
extern char *file_2[30];
extern char *file_3[15];
extern char *file_4[575];
extern char *file_5[764];
extern char *file_6[20];
extern char *file_7[20];

void	ft_putstr(char *s);
int		ft_toupper(int c);
void	print_file_name(char **argv, int file, char *color);
void	print_color_str(char *str, char *color);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	delay(float number);
void	check_leaks();

#endif