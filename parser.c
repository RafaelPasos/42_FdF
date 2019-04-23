/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 23:21:34 by apasos-g          #+#    #+#             */
/*   Updated: 2019/04/23 00:16:45 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int get_dat_shit(int ***table, char ***strtable, int i, int width)
{
	int k;

	k = 0;
	while (k < width)
	{
		(*table)[i][k] = (int *)malloc(sizeof(int));
		(*table)[i][k] = ft_atoi((*strtable)[i]);
		k++;
	}
}

void parse(int ***table, int fd)
{
	char	**strtable;
	char	*line;
	int		realwidth;
	int		width;
	int		i;

	realwidth = 0;
	while (get_next_line(fd, &line))
	{
		width = 0;
		strtable = ft_strsplit(line, ' ');
		while (strtable[width])
			width++;
		if (width != realwidth)
			return (NULL);
		*table = (int **)malloc(sizeof((int *) * (width + 1)));
		i = 0;
		while (i < width)
		{
			get_dat_shit(table, &strtable, i, width);
			i++;
		}
		free(line);
	}
}
