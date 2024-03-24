
#include "../libft.h"


// int ft_strlen(const char *str)
// {
// 	int i;
// 	i = 0;
// 	while (str[i])
// 	{
// 		i++;
// 	}
// 	return(i);
// }

static int	count_words(const char *str, char c)
{
	int i;
	int trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s || !(split = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

// static size_t	ft_countword(char const *s, char c)
// {
// 	size_t	count;

// 	if (!*s)
// 		return (0);
// 	count = 0;
// 	while (*s)
// 	{
// 		while (*s == c)
// 			s++;
// 		if (*s)
// 			count++;
// 		while (*s != c && *s)
// 			s++;
// 	}
// 	return (count);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**lst;
// 	size_t	word_len;
// 	int		i;

// 	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
// 	if (!s || !lst)
// 		return (0);
// 	i = 0;
// 	while (*s)
// 	{
// 		while (*s == c && *s)
// 			s++;
// 		if (*s)
// 		{
// 			if (!ft_strchr(s, c))
// 				word_len = ft_strlen(s);
// 			else
// 				word_len = ft_strchr(s, c) - s;
// 			lst[i++] = ft_substr(s, 0, word_len);
// 			s += word_len;
// 		}
// 	}
// 	lst[i] = NULL;
// 	return (lst);
// }