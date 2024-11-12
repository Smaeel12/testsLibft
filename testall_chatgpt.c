#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include "libft.h"

// Test ft_isalpha
void test_ft_isalpha() {
    assert(ft_isalpha('a') == 1);
    assert(ft_isalpha('Z') == 1);
    assert(ft_isalpha('1') == 0);
    assert(ft_isalpha('!') == 0);
    printf("ft_isalpha passed\n");
}

// Test ft_isdigit
void test_ft_isdigit() {
    assert(ft_isdigit('0') == 1);
    assert(ft_isdigit('9') == 1);
    assert(ft_isdigit('a') == 0);
    assert(ft_isdigit('@') == 0);
    printf("ft_isdigit passed\n");
}

// Test ft_isalnum
void test_ft_isalnum() {
    assert(ft_isalnum('a') == 1);
    assert(ft_isalnum('Z') == 1);
    assert(ft_isalnum('1') == 1);
    assert(ft_isalnum('!') == 0);
    printf("ft_isalnum passed\n");
}

// Test ft_isascii
void test_ft_isascii() {
    assert(ft_isascii('a') == 1);
    assert(ft_isascii(127) == 1); // Non-ASCII
    assert(ft_isascii(0) == 1); // ASCII control character
    printf("ft_isascii passed\n");
}

// Test ft_isprint
void test_ft_isprint() {
    assert(ft_isprint('a') == 1);
    assert(ft_isprint(32) == 1); // space is printable
    assert(ft_isprint(31) == 0); // non-printable
    printf("ft_isprint passed\n");
}

// Test ft_strlen
void test_ft_strlen() {
    assert(ft_strlen("Hello") == 5);
    assert(ft_strlen("") == 0);
    assert(ft_strlen("12345") == 5);
    printf("ft_strlen passed\n");
}

// Test ft_memset
void test_ft_memset() {
    char str[10] = "abcdefghi";
    ft_memset(str, 'X', 3);
    assert(str[0] == 'X');
    assert(str[1] == 'X');
    assert(str[2] == 'X');
    assert(str[3] == 'd');
    printf("ft_memset passed\n");
}

// Test ft_bzero
void test_ft_bzero() {
    char str[10] = "abcdefghi";
    ft_bzero(str, 5);
    assert(str[0] == '\0');
    assert(str[1] == '\0');
    assert(str[4] == '\0');
    printf("ft_bzero passed\n");
}

// Test ft_memcpy
void test_ft_memcpy() {
    char dst[10];
    char src[10] = "abcdefghi";
    ft_memcpy(dst, src, 5);
    assert(dst[0] == 'a');
    assert(dst[4] == 'e');
    printf("ft_memcpy passed\n");
}

// Test ft_memmove
void test_ft_memmove() {
    char str[10] = "abcdefghi";
    char str2[10] = "abcdefghi";
    memmove(str + 2, str, 5);
    ft_memmove(str2 + 2, str2, 5);
    assert(strcmp(str, str2) == 0);
    printf("ft_memmove passed\n");
}

// Test ft_strlcpy
void test_ft_strlcpy() {
    char dst[10];
    const char *src = "Hello";
    size_t len = ft_strlcpy(dst, src, 10);
    assert(len == 5);
    assert(dst[0] == 'H');
    assert(dst[4] == 'o');
    printf("ft_strlcpy passed\n");
}

// Test ft_strlcat
void test_ft_strlcat() {
    char dst[20] = "Hello";
    const char *src = "World";
    size_t len = ft_strlcat(dst, src, 20);
    assert(len == 10);
    assert(dst[5] == 'W');
    assert(dst[9] == 'd');
    printf("ft_strlcat passed\n");
}

// Test ft_toupper
void test_ft_toupper() {
    assert(ft_toupper('a') == 'A');
    assert(ft_toupper('Z') == 'Z');
    assert(ft_toupper('1') == '1');
    printf("ft_toupper passed\n");
}

// Test ft_tolower
void test_ft_tolower() {
    assert(ft_tolower('A') == 'a');
    assert(ft_tolower('z') == 'z');
    assert(ft_tolower('1') == '1');
    printf("ft_tolower passed\n");
}

// Test ft_strchr
void test_ft_strchr() {
    const char *s = "Hello, World!";
    assert(ft_strchr(s, 'o') == s + 4);
    assert(ft_strchr(s, 'W') == s + 7);
    assert(ft_strchr(s, 'z') == NULL);
    printf("ft_strchr passed\n");
}

// Test ft_strrchr
void test_ft_strrchr() {
    const char *s = "Hello, World!";
    assert(ft_strrchr(s, 'o') == s + 8);
    assert(ft_strrchr(s, 'W') == s + 7);
    assert(ft_strrchr(s, 'z') == NULL);
    printf("ft_strrchr passed\n");
}

// Test ft_strncmp
void test_ft_strncmp() {
    assert(ft_strncmp("Hello", "Hello", 5) == 0);
    assert(ft_strncmp("Hello", "Hellz", 5) < 0);
    assert(ft_strncmp("Hellz", "Hello", 5) > 0);
    printf("ft_strncmp passed\n");
}

// Test ft_memchr
void test_ft_memchr() {
    char s[] = "Hello, World!";
    assert(ft_memchr(s, 'o', 13) == s + 4);
    assert(ft_memchr(s, 'W', 13) == s + 7);
    assert(ft_memchr(s, 'z', 13) == NULL);
    printf("ft_memchr passed\n");
}

// Test ft_memcmp
void test_ft_memcmp() {
    char s1[] = "Hello";
    char s2[] = "Hellz";
    assert(ft_memcmp(s1, s2, 5) < 0);
    assert(ft_memcmp(s1, s1, 5) == 0);
    assert(ft_memcmp(s2, s1, 5) > 0);
    printf("ft_memcmp passed\n");
}

// Test ft_atoi
void test_ft_atoi() {
    assert(ft_atoi("12345") == 12345);
    assert(ft_atoi("-12345") == -12345);
    assert(ft_atoi("  +12345") == 12345);
    assert(ft_atoi("0") == 0);
    assert(ft_atoi("abc") == 0);
    printf("ft_atoi passed\n");
}

// Test ft_calloc
void test_ft_calloc() {
    int *arr = (int *)ft_calloc(5, sizeof(int));
    assert(arr != NULL);
    for (int i = 0; i < 5; i++) {
        assert(arr[i] == 0);
    }
    free(arr);
    printf("ft_calloc passed\n");
}

// Test ft_strdup
void test_ft_strdup() {
    const char *str = "Hello";
    char *dup = ft_strdup(str);
    assert(dup != NULL);
    assert(strcmp(dup, str) == 0);
    free(dup);
    printf("ft_strdup passed\n");
}

// Test ft_substr
void test_ft_substr() {
    char *substr = ft_substr("Hello, World!", 7, 5);
    assert(substr != NULL);
    assert(strcmp(substr, "World") == 0);
    free(substr);
    printf("ft_substr passed\n");
}

// Test ft_strjoin
void test_ft_strjoin() {
    char *joined = ft_strjoin("Hello", " World!");
    assert(joined != NULL);
    assert(strcmp(joined, "Hello World!") == 0);
    free(joined);
    printf("ft_strjoin passed\n");
}

// Test ft_strtrim
void test_ft_strtrim() {
    char *trimmed = ft_strtrim("!!Hello World!!", "!!");
    assert(trimmed != NULL);
    assert(strcmp(trimmed, "Hello World") == 0);
    free(trimmed);
    printf("ft_strtrim passed\n");
}

// Test ft_split
void test_ft_split() {
    char **split = ft_split("Hello World", ' ');
    assert(split != NULL);
    assert(strcmp(split[0], "Hello") == 0);
    assert(strcmp(split[1], "World") == 0);
    free(split[0]);
    free(split[1]);
    free(split);
    printf("ft_split passed\n");
}

// Test ft_itoa
void test_ft_itoa() {
    char *str = ft_itoa(12345);
    assert(str != NULL);
    assert(strcmp(str, "12345") == 0);
    free(str);
    printf("ft_itoa passed\n");
}

char test_map(unsigned int n, char c)  {
    (void) n;
    if (c <= 'z' && c >= 'a')
        return c -= 32;
    else
        return c += 32;
}

// Test ft_strmapi
void test_ft_strmapi() {
    char *result = ft_strmapi("abcd", test_map);
    assert(result != NULL);
    assert(strcmp(result, "ABCD") == 0);
    free(result);
    printf("ft_strmapi passed\n");
}

void test_iter(unsigned int n, char *s) {
    (void) n;

    while (*s) {
        if (*s <= 'z' && *s >= 'a'){
            *s -= 32;
            break;}
        else{
            *s += 32;
            break;}
        s++;
    }
}

// Test ft_striteri
void test_ft_striteri() {
    char str[] = "abcd";
    ft_striteri(str, test_iter);
    assert(strcmp(str, "ABCD") == 0);
    printf("ft_striteri passed\n");
}

// Test ft_putchar_fd
void test_ft_putchar_fd() {
    // This will print to the console, so just check if no crash occurs.
    write(1, "---- ", 5);
    ft_putchar_fd('A', 1);
    printf(" ---- ft_putchar_fd passed\n");
}

// Test ft_putstr_fd
void test_ft_putstr_fd() {
    // This will print to the console, so just check if no crash occurs.
    ft_putstr_fd("---- Hello", 1);
    printf(" ---- ft_putstr_fd passed\n");
}

// Test ft_putendl_fd
void test_ft_putendl_fd() {
    // This will print to the console, so just check if no crash occurs.
    ft_putendl_fd("---- Hello", 1);
    printf(" ----- ft_putendl_fd passed\n");
}

// Test ft_putnbr_fd
void test_ft_putnbr_fd() {
    // This will print to the console, so just check if no crash occurs.
    write(1, "---- ", 5);
    ft_putnbr_fd(12345, 1);
    printf(" ---- ft_putnbr_fd passed\n");
}

// Test ft_lstnew
void test_ft_lstnew() {
    t_list *node = ft_lstnew("Hello");
    assert(node != NULL);
    assert(strcmp(node->content, "Hello") == 0);
    free(node);
    printf("ft_lstnew passed\n");
}

// Test ft_lstadd_front
void test_ft_lstadd_front() {
    t_list *head = NULL;
    t_list *node = ft_lstnew("World");
    ft_lstadd_front(&head, node);
    assert(strcmp(head->content, "World") == 0);
    printf("ft_lstadd_front passed\n");
}

// Test ft_lstsize
void test_ft_lstsize() {
    t_list *head = ft_lstnew("World");
    ft_lstadd_front(&head, ft_lstnew("Hello"));
    assert(ft_lstsize(head) == 2);
    printf("ft_lstsize passed\n");
}

// Test ft_lstlast
void test_ft_lstlast() {
    t_list *head = ft_lstnew("Hello");
    t_list *last = ft_lstlast(head);
    assert(strcmp(last->content, "Hello") == 0);
    printf("ft_lstlast passed\n");
}

// Test ft_lstadd_back
void test_ft_lstadd_back() {
    t_list *head = ft_lstnew("Hello");
    t_list *new = ft_lstnew("World");
    ft_lstadd_back(&head, new);
    assert(strcmp(head->next->content, "World") == 0);
    printf("ft_lstadd_back passed\n");
}

// Test ft_lstdelone
void test_ft_lstdelone() {
    t_list *head = ft_lstnew(ft_strdup("Hello"));
    assert(head != NULL);
    ft_lstdelone(head, free);
    printf("ft_lstdelone passed\n");
}

// Test ft_lstclear
void test_ft_lstclear() {
    t_list *head = ft_lstnew(ft_strdup("Hello"));
    ft_lstclear(&head, free);
    assert(head == NULL);
    printf("ft_lstclear passed\n");
}

void print_node(void *s) {
    puts(s);
}

// Test ft_lstiter
void test_ft_lstiter() {
    t_list *head = ft_lstnew("Hello");
    ft_lstiter(head, print_node);
    printf("ft_lstiter passed\n");
}

// Test ft_lstmap
void test_ft_lstmap() {
    t_list *head = ft_lstnew("Hello");
    t_list *mapped = ft_lstmap(head, (void *(*)(void *))ft_strdup, free);
    assert(mapped != NULL);
    assert(strcmp(mapped->content, "Hello") == 0);
    free(mapped->content);
    free(mapped);
    printf("ft_lstmap passed\n");
}

int main() {
    test_ft_isalpha();
    test_ft_isdigit();
    test_ft_isalnum();
    test_ft_isascii();
    test_ft_isprint();
    test_ft_strlen();
    test_ft_memset();
    test_ft_bzero();
    test_ft_memcpy();
    test_ft_memmove();
    test_ft_strlcpy();
    test_ft_strlcat();
    test_ft_toupper();
    test_ft_tolower();
    test_ft_strchr();
    test_ft_strrchr();
    test_ft_strncmp();
    test_ft_memchr();
    test_ft_memcmp();
    test_ft_atoi();
    test_ft_calloc();
    test_ft_strdup();
    test_ft_substr();
    test_ft_strjoin();
    test_ft_strtrim();
    test_ft_split();
    test_ft_itoa();
    test_ft_strmapi();
    test_ft_striteri();
    test_ft_putchar_fd();
    test_ft_putstr_fd();
    test_ft_putendl_fd();
    test_ft_putnbr_fd();
    test_ft_lstnew();
    test_ft_lstadd_front();
    test_ft_lstsize();
    test_ft_lstlast();
    test_ft_lstadd_back();
    test_ft_lstdelone();
    test_ft_lstclear();
    test_ft_lstiter();
    test_ft_lstmap();

    printf("\nAll tests passed!\n");
    return 0;
}
