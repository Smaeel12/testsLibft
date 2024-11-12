#include "libft.h"
#include <stdio.h>

void	test_isalpha(void);
void	test_isdigit(void);
void	test_isalnum(void);
void	test_isascii(void);
void	test_isprint(void);
void	test_strlen(void);
void	test_memset(void);
void	test_bzero(void);
void	test_memcpy(void);
void	test_memmove(void);
void	test_strlcpy(void);
void	test_strlcat(void);
void	test_toupper(void);
void	test_tolower(void);
void	test_strchr(void);
void	test_strrchr(void);
void	test_strncmp(void);
void	test_memchr(void);
void	test_memcmp(void);
void	test_strnstr(void);
void	test_atoi(void);
void	test_calloc(void);
void	test_strdup(void);

int	main(void)
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_strlcpy();
	test_strlcat();
	test_toupper();
	test_tolower();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_memchr();
	test_memcmp();
	test_strnstr();
	test_atoi();
	test_calloc();
	test_strdup();
	return (0);
}

void	test_isalpha(void)
{
	printf("Testing isalpha:\n");
	printf("ft_isalpha('a'): %d, Expected: 1\n", ft_isalpha('a'));
	printf("ft_isalpha('Z'): %d, Expected: 1\n", ft_isalpha('Z'));
	printf("ft_isalpha('1'): %d, Expected: 0\n", ft_isalpha('1'));
	printf("ft_isalpha(' '): %d, Expected: 0\n", ft_isalpha(' '));
	printf("ft_isalpha('@'): %d, Expected: 0\n", ft_isalpha('@'));
}

void	test_isdigit(void)
{
	printf("Testing isdigit:\n");
	printf("ft_isdigit('0'): %d, Expected: 1\n", ft_isdigit('0'));
	printf("ft_isdigit('5'): %d, Expected: 1\n", ft_isdigit('5'));
	printf("ft_isdigit('a'): %d, Expected: 0\n", ft_isdigit('a'));
	printf("ft_isdigit(' '): %d, Expected: 0\n", ft_isdigit(' '));
}

void	test_isalnum(void)
{
	printf("Testing isalnum:\n");
	printf("ft_isalnum('a'): %d, Expected: 1\n", ft_isalnum('a'));
	printf("ft_isalnum('1'): %d, Expected: 1\n", ft_isalnum('1'));
	printf("ft_isalnum('@'): %d, Expected: 0\n", ft_isalnum('@'));
	printf("ft_isalnum(' '): %d, Expected: 0\n", ft_isalnum(' '));
}

void	test_isascii(void)
{
	printf("Testing isascii:\n");
	printf("ft_isascii('A'): %d, Expected: 1\n", ft_isascii('A'));
	printf("ft_isascii(128): %d, Expected: 0\n", ft_isascii(128));
	printf("ft_isascii(65): %d, Expected: 1\n", ft_isascii(65));
}

void	test_isprint(void)
{
	printf("Testing isprint:\n");
	printf("ft_isprint('A'): %d, Expected: 1\n", ft_isprint('A'));
	printf("ft_isprint(9): %d, Expected: 0\n", ft_isprint(9));
	printf("ft_isprint(' '): %d, Expected: 1\n", ft_isprint(' '));
}

void	test_strlen(void)
{
	printf("Testing strlen:\n");
	printf("ft_strlen('Hello'): %zu, Expected: 5\n", ft_strlen("Hello"));
	printf("ft_strlen(''): %zu, Expected: 0\n", ft_strlen(""));
}

void	test_memset(void)
{
	char	buffer[10];

	ft_memset(buffer, 'A', 5);
	buffer[5] = '\0';
	printf("Testing memset: %s, Expected: AAAAA\n", buffer);
}

void	test_bzero(void)
{
	char	buffer[10] = "Hello";

	ft_bzero(buffer + 3, 3);
	printf("Testing bzero: %s, Expected: Hel\n", buffer);
}

void	test_memcpy(void)
{
	char		dest[10];
	const char	*src = "Hello";

	ft_memcpy(dest, src, 5);
	dest[5] = '\0';
	printf("Testing memcpy: %s, Expected: Hello\n", dest);
}

void	test_memmove(void)
{
	char	str[] = "HelloWorld";

	ft_memmove(str + 5, str, 5);
	printf("Testing memmove: %s, Expected: HelloHello\n", str);
}

void	test_strlcpy(void)
{
	char	dest[10];
	size_t	len;

	len = ft_strlcpy(dest, "Hello", sizeof(dest));
	printf("Testing strlcpy: %s, Length: %zu , Expected: Hello, %i\n", dest,
		len, 5);
}

void	test_strlcat(void)
{
	char	dest[20] = "Hello";
	size_t	len;

	len = ft_strlcat(dest, " World", sizeof(dest));
	printf("Testing strlcat: %s, Length: %zu, Expected: Hello World, %i\n",
		dest, len, 11);
}

void	test_toupper(void)
{
	printf("Testing toupper:\n");
	printf("ft_toupper('a'): %c, Expected: A\n", ft_toupper('a'));
	printf("ft_toupper('A'): %c, Expected: A\n", ft_toupper('A'));
}

void	test_tolower(void)
{
	printf("Testing tolower:\n");
	printf("ft_tolower('A'): %c, Expected: a\n", ft_tolower('A'));
	printf("ft_tolower('a'): %c, Expected: a\n", ft_tolower('a'));
}

void	test_strchr(void)
{
	printf("Testing strchr:\n");
	printf("ft_strchr('Hello', 'e'): %s, Expected: ello\n", ft_strchr("Hello",
			'e'));
	printf("ft_strchr('Hello', 'x'): %s, Expected: (null)\n", ft_strchr("Hello",
			'x'));
}

void	test_strrchr(void)
{
	printf("Testing strrchr:\n");
	printf("ft_strrchr('Hello', 'l'): %s, Expected: lo\n", ft_strrchr("Hello",
			'l'));
	printf("ft_strrchr('Hello', 'x'): %s, Expected: (null)\n",
		ft_strrchr("Hello", 'x'));
}

void	test_strncmp(void)
{
	printf("Testing strncmp:\n");
	printf("ft_strncmp('abc', 'abc', 3): %d, Expected: 0\n", ft_strncmp("abc",
			"abc", 3));
	printf("ft_strncmp('abc', 'abd', 3): %d, Expected: < 0\n", ft_strncmp("abc",
			"abd", 3));
}

void	test_memchr(void)
{
	printf("Testing memchr:\n");
	printf("ft_memchr('Hello', 'e', 5): %s, Expected: ello\n",
		(char *)ft_memchr("Hello", 'e', 5));
	printf("ft_memchr('Hello', 'x', 5): %s, Expected: (null)\n",
		(char *)ft_memchr("Hello", 'x', 5));
}

void	test_memcmp(void)
{
	printf("Testing memcmp:\n");
	printf("ft_memcmp('abc', 'abc', 3): %d, Expected: 0\n", ft_memcmp("abc",
			"abc", 3));
	printf("ft_memcmp('abc', 'abd', 3): %d, Expected: < 0\n", ft_memcmp("abc",
			"abd", 3));
}

void	test_strnstr(void)
{
	printf("Testing strnstr:\n");
	printf("ft_strnstr('Hello World', 'World', 11): %s, Expected: World\n",
		ft_strnstr("Hello World", "World", 11));
	printf("ft_strnstr('Hello World', 'world', 11): %s, Expected: (null)\n",
		ft_strnstr("Hello World", "world", 11));
}

void	test_atoi(void)
{
	printf("Testing atoi:\n");
	printf("ft_atoi('123'): %d, Expected: 123\n", ft_atoi("123"));
	printf("ft_atoi('   -456'): %d, Expected: -456\n", ft_atoi("   -456"));
	printf("ft_atoi('12abc'): %d, Expected: 12\n", ft_atoi("12abc"));
	printf("ft_atoi('abc'): %d, Expected: 0\n", ft_atoi("abc"));
}

void	test_calloc(void)
{
	int	*arr;

	arr = (int *)ft_calloc(5, sizeof(int));
	printf("Testing calloc:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("arr[%d]: %d, Expected: 0\n", i, arr[i]);
	}
	free(arr); // Remember to free allocated memory
}

void	test_strdup(void)
{
	char	*str;

	str = ft_strdup("Hello");
	printf("Testing strdup: %s, Expected: Hello\n", str);
	free(str); // Remember to free allocated memory
}
