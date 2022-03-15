/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:01:58 by gmyriah           #+#    #+#             */
/*   Updated: 2022/03/15 10:02:00 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		if (*s1 == '\0')
			break ;
		s1++;
		s2++;
		n--;
	}
	return (0);
}

int	ft_strlen(const char *string)
{
	int	len;

	len = 0;
	while (*string)
	{
		len++;
		string++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		dest_len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	dest_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = malloc(sizeof(char) * dest_len);
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}

char	*str_n_copy(char *str, unsigned int n)
{
	unsigned int	i;
	char			*dest;

	dest = malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i < n)
	{
		dest[i] = *str++;
		i++;
	}
	dest[n] = '\0';
	return (dest);
}

char	**ft_split(char *string, char divider)
{
	char	**result;
	int		counter;
	int		i;
	int		j;

	counter = 0;
	j = 0;
	while (string[j])
	{
		if (string[j++] == divider)
			counter++;
	}
	result = malloc(sizeof(char *) * (counter + 2));
	result[counter + 1] = NULL;
	i = 0;
	while (i < counter + 1)
	{
		j = 0;
		while (string[j] && string[j] != divider)
			j++;
		result[i] = str_n_copy(string, j);
		string = string + j + 1;
		i++;
	}
	return (result);
}
