#include <stdlib.h>
#include <string.h>
#include "libft/incl/libft.h"

char	*ft_strjoin_three(char *first, char *second, char *third)
{
	char	*ret;
	size_t	len;
	size_t	i;

	len = ft_strlen(first) + ft_strlen(second) + ft_strlen(third);
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	len = 0;
	i = 0;
	while (first[i] != '\0')
		ret[len++] = first[i++];
	i = 0;
	while (second[i] != '\0')
		ret[len++] = second[i++];
	i = 0;
	while (third[i] != '\0')
		ret[len++] = third[i++];
	return (ret);
}
