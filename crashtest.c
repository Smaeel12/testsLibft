#include "libft.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/string.h>

void istests() {
    ft_isalpha(-100);
    ft_isalpha(0);
    ft_isalpha(255);

    ft_isalnum(-100);
    ft_isalnum(0);
    ft_isalnum(255);

    ft_isascii(-100);
    ft_isascii(0);
    ft_isascii(255);

    ft_isdigit(-100);
    ft_isdigit(0);
    ft_isdigit(255);

    ft_isprint(-100);
    ft_isprint(0);
    ft_isprint(255);

    ft_toupper(-100);
    ft_toupper(0);
    ft_toupper(255);

    ft_tolower(-100);
    ft_tolower(0);
    ft_tolower(255);
}


void strtests() {
    ft_strchr(NULL, 'x');
    ft_strchr("hello", 0);
    ft_strchr("hello", 'o');

    ft_strrchr(NULL, 'x');
    ft_strrchr("hello", 0);
    ft_strrchr("hello", 'o');

    ft_strncmp("hello", "hello", 0);
    ft_strncmp("hello", NULL, 10);
    ft_strncmp(NULL, "hello", 10);
    ft_strncmp(NULL, NULL, 10);
    ft_strncmp("hello", "world", 5);

    ft_strnstr("hello", "hello", 0);
    ft_strnstr("hello", NULL, 10);
    ft_strnstr(NULL, "hello", 10);
    ft_strnstr(NULL, NULL, 10);
    ft_strnstr("hello world", "world", 11);

    char *dup = ft_strdup(NULL);
    if (dup) {
        free(dup);
    }
    dup = ft_strdup("hello");
    if (dup) {
        free(dup);
    }

    ft_atoi("-----()()");
    ft_atoi("12345");
}


void memtests() {
    char dst[50];
    
    ft_memset(NULL, (int) 'c', 5);
    ft_memset(dst, 0, 5);
    ft_memset(dst, 10, 0);
    ft_memset(dst, 'a', 50);

    ft_memchr(NULL, (int) 'c', 5);
    ft_strrchr("hello", 'o');
    ft_memchr(dst, 0, 5);
    ft_memchr(dst, 10, 0);
    ft_memchr(dst, 'a', 50);

    ft_memcmp(NULL, NULL, 5);
    ft_memcmp(dst, NULL, 5);
    ft_memcmp(dst, NULL, 0);
    ft_memcmp(dst, dst, 50);

    ft_memmove(NULL, NULL, 5);
    ft_memmove(dst, NULL, 5);
    ft_memmove(dst, NULL, 0);
    ft_memmove(dst, dst, 50);

    ft_memcpy(NULL, NULL, 5);
    ft_memcpy(dst, NULL, 5);
    ft_memcpy(dst, NULL, 0);
    ft_memcpy(dst, dst, 50);

    ft_bzero(dst, 0);
    ft_bzero(NULL, 10);
    ft_bzero(dst, 50);

    void *r1 = ft_calloc(0, 10);
    free(r1);
    r1 = ft_calloc(10, 0);
    free(r1);
    r1 = ft_calloc(10, 10);
    free(r1);

}
char map(unsigned int n, char c) {
    return n + c;
}

void iter(unsigned int n , char *s) {
    *s = n + *s;
}


void testpart2() {
    
    char *substr = ft_substr(NULL, 0, 0);
    if (substr) {
        free(substr);
    }
    substr = ft_substr("hello", 0, 2);
    if (substr) {
        free(substr);
    }

    
    char *strjoin_result = ft_strjoin(NULL, NULL);
    if (strjoin_result) {
        free(strjoin_result);
    }
    strjoin_result = ft_strjoin("hello", "world");
    if (strjoin_result) {
        free(strjoin_result);
    }

    
    char *strtrim_result = ft_strtrim(NULL, NULL);
    if (strtrim_result) {
        free(strtrim_result);
    }
    strtrim_result = ft_strtrim("  hello  ", " ");
    if (strtrim_result) {
        free(strtrim_result);
    }

    
    char **split_result = ft_split(NULL, 0);
    if (split_result) {
        
        for (int i = 0; split_result[i] != NULL; i++) {
            free(split_result[i]);
        }
        free(split_result);
    }
    split_result = ft_split("hello world", ' ');
    if (split_result) {
        for (int i = 0; split_result[i] != NULL; i++) {
            free(split_result[i]);
        }
        free(split_result);
    }

    
    char *itoa_result = ft_itoa(-0);
    if (itoa_result) {
        free(itoa_result);
    }
    itoa_result = ft_itoa(12345);
    if (itoa_result) {
        free(itoa_result);
    }

    
    char *strmapi_result = ft_strmapi(NULL, map);
    if (strmapi_result) {
        free(strmapi_result);
    }
    strmapi_result = ft_strmapi("hello", NULL);
    if (strmapi_result) {
        free(strmapi_result);
    }

    
    ft_striteri(NULL, iter);
    ft_striteri("hello", NULL);

    
    ft_putchar_fd(0, 100);
    ft_putchar_fd('A', 1);

    
    ft_putstr_fd(0, 100);
    ft_putstr_fd("hello", 1);

    
    ft_putendl_fd(0, 100);
    ft_putendl_fd("hello", 1);

    
    ft_putnbr_fd(0, 100);
    ft_putnbr_fd(12345, 1);
}

void test_orginals() {
    char dst[50] = "hello";
    strlcat(dst, "hello", 0);
    strlcat(dst, NULL, 10);
    strlcat(NULL, "hello", 10);
    strlcat(NULL, NULL, 10);
    strlcat(dst, "world", 50);

    strlcpy("hello", "hello", 0);
    strlcpy("hello", NULL, 10);
    strlcpy(NULL, "hello", 10);
    strlcpy(NULL, NULL, 10);
    strlcpy(dst, "world", 50);
    printf("Original strnstr works\n");
}

void protected_part1() {
    ft_strlen(NULL);



    char dst[50] = "hello";
    ft_strlcat(dst, "hello", 0);
    ft_strlcat(dst, NULL, 10);
    ft_strlcat(NULL, "hello", 10);
    ft_strlcat(NULL, NULL, 10);
    ft_strlcat(dst, "world", 50);

    ft_strlcpy("hello", "hello", 0);
    ft_strlcpy("hello", NULL, 10);
    ft_strlcpy(NULL, "hello", 10);
    ft_strlcpy(NULL, NULL, 10);
    ft_strlcpy(dst, "world", 50);

}
int main() {
    test_orginals();
    // istests();
    // strtests();
    // memtests();
    // testpart2();
    
    // printf("Crash tests completed successfully.\n");
    // return 0;
}
