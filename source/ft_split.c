#include "pipex.h"

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
