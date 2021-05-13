#include "get_next_line.h"

size_t	ft_strlen(const char *str, char c)
{
	char	*copy_str;

	copy_str = (char *)str;
	while (*copy_str && *copy_str != c)
		copy_str++;
	return (copy_str - str);
}

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*dublicat_str;

	i = 0;
	size = ft_strlen(s1, 0);
	dublicat_str = (char *)malloc((size + 1) * sizeof(char));
	if (!dublicat_str)
		return (NULL);
	while (s1[i])
	{
		dublicat_str[i] = s1[i];
		i++;
	}
	dublicat_str[i] = '\0';
	return (dublicat_str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (c == 0)
		return (str + ft_strlen(str, 0));
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	j_str = (char *)malloc(sizeof(char) * (ft_strlen(s1, 0)
				+ ft_strlen(s2, 0) + 1));
	if (!j_str)
		return (NULL);
	while (s1[i])
		j_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		j_str[j++] = s2[i++];
	j_str[j] = '\0';
	return (j_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s, 0);
	if (!s || len <= 0 || start >= slen)
		return (ft_strdup(""));
	if (len > slen)
		len = slen;
	sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	while (s[start] && i < len)
	{
		sub_str[i] = s[start];
		i++;
		start++;
	}
	if (i == len)
		sub_str[i] = '\0';
	return (sub_str);
}
