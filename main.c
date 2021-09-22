/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:20:11 by aherrero          #+#    #+#             */
/*   Updated: 2021/09/02 18:16:31 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "utils.h"
#include "string.h"
#include "stdlib.h"
//#include path

char	*get_expected(int file, int i)
{
	if (file == 3)
		return (file_1[i]);
	if (file == 4)
		return (file_2[i]);
	if (file == 5)
		return (file_3[i]);
	if (file == 6)
		return (file_4[i]);
	if (file == 7)
		return (file_5[i]);
	if (file == 8)
		return (file_6[i]);
	if (file == 9)
		return (file_7[i]);
	return (NULL);
}

void	check(char *line, int file, int fd, int i)
{
	if ((file == 1 || file == 2) && !line)
	{
		print_color_str("OK ", green);
	}
	else
	{
		if (fd && line)
		{
			if (!ft_strncmp(line, get_expected(file, i), (int)ft_strlen(get_expected(file, i))))
				print_color_str("OK ", green);
			else
			{
				print_color_str("KO ", red);
				print_color_str("\nresult = ", yellow);
				printf("%s\n", line);
				print_color_str("expected = ", yellow);
				printf("%s\n", get_expected(file, i));
			}
		}
		else
		{
			if (fd)
				print_color_str("OK ", green);
			else
			{
				print_color_str("KO ", red);
				print_color_str("KO ", red);
				print_color_str("\nresult = ", yellow);
				printf("%s\n", line);
				print_color_str("expected = ", yellow);
				printf("%s\n", get_expected(file, i));
			}
		}	
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line;
	int		file;

	fd = 0;
	file = 1;
	line = NULL;
	if (argc < 2)
		return (0);
	print_color_str("\nBUFFER = ", cyan);
	printf("%d\n", BUFFER_SIZE);
	while (file < argc)
	{
		i = 0;
		print_file_name(argv, file, blue);
		fd = open(argv[file], O_RDONLY);
		line = get_next_line(fd);
		//printf("\n%s\n", file_exp[file - 1][i]);
		check(line, file, fd, i);
		//printf("Line %d = %s\n", i + 1, line);
		i++;
		while (line)
		{
			line = get_next_line(fd);
			if(file > 2 && line)
			{
				check(line, file, fd, i);
				//printf("Line %d = %s\n", i, line);
			}
			delay(0.2f);
			i++;
			free(line);
		}
		file++;
	}
	printf("\n");
	check_leaks();
	return (0);
}
