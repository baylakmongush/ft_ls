/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 22:26:50 by baylak            #+#    #+#             */
/*   Updated: 2020/08/29 22:37:04 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"


char			*ft_strjoinfree_s1(char *s1, char *s2)
{
	char		*ptr;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		exit(1);
	while (s1 && s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

char			*ft_strjoinfree_s2(char *s1, char *s2)
{
	char		*ptr;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		exit(1);
	while (s1 && s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	free(s2);
	return (ptr);
}

char			*ft_strjoinfree_both(char *s1, char *s2)
{
	char		*ptr;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		exit(1);
	while (s1 && s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	free(s1);
	free(s2);
	return (ptr);
}
