#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <assert.h> 

void	del(void *s)
{
	free(s);
}

void f(void *str) {
	char *s = (char *) str;

    while (*s) {
        if (*s <= 'z' && *s >= 'a'){
            *s -= 32;
		}
        else if (*s <= 'Z' && *s >= 'A') {
            *s += 32;
		}
        s++;
    }
}

void	*f2(void *s)
{
	void *tmp;
	tmp = ft_strdup(s); 
	assert(tmp); 
	ft_memset(tmp, 'c', strlen(tmp)); 
	assert(tmp);
	return tmp;
}

void print_list(t_list *lst) {
	if (!lst) {
		puts("Empty list");
		return;
	}
	while (lst) {
		printf("%s", (char *)lst->content);
		if (lst->next) {
			printf(" --> ");
		}
		lst = lst->next;
	}
	putchar('\n');
}

int main(void)
{
	
	t_list *node = ft_lstnew(ft_strdup("I was the head"));
	assert(node); 
	assert(strcmp((char *)node->content, "I was the head") == 0); 

	
	ft_lstadd_front(&node, ft_lstnew(ft_strdup("now I am!")));
	assert(strcmp((char *)node->content, "now I am!") == 0); 
	assert(strcmp((char *)node->next->content, "I was the head") == 0); 

	
	int size = ft_lstsize(node);
	assert(size == 2); 

	
	t_list *last = ft_lstlast(node);
	assert(strcmp((char *)last->content, "I was the head") == 0); 

	
	ft_lstadd_back(&node, ft_lstnew(ft_strdup("I always been the last")));
	t_list *test_last = ft_lstlast(node);
	assert(strcmp((char *)test_last->content, "I always been the last") == 0); 

	
	ft_lstiter(node, f);
	
	assert(strcmp((char *)node->content, "NOW i AM!") == 0); 
	assert(strcmp((char *)node->next->content, "i WAS THE HEAD") == 0); 
	assert(strcmp((char *)node->next->next->content, "i ALWAYS BEEN THE LAST") == 0); 

	
	t_list *new = ft_lstmap(node, f2, del);
	assert(new != node); 
	assert(strcmp((char *)new->content, "ccccccccc") == 0); 
	assert(strcmp((char *)new->next->content, "cccccccccccccc") == 0); 
	assert(strcmp((char *)new->next->next->content, "cccccccccccccccccccccc") == 0); 

	
	t_list *next = node->next;
	ft_lstdelone(node, del); 
	node = next;
	
	assert(strcmp((char *)node->content, "i WAS THE HEAD") == 0); 

	
	ft_lstclear(&node, del); 
	assert(node == NULL); 

	
	t_list *empty_list = NULL;
	ft_lstadd_front(&empty_list, ft_lstnew(ft_strdup("First element")));
	assert(empty_list); 
	assert(strcmp((char *)empty_list->content, "First element") == 0); 

	
	ft_lstadd_back(&empty_list, NULL); 
	assert(empty_list && empty_list->next == NULL); 

	
	t_list *failed_node = ft_lstnew(NULL);
	assert(failed_node->content == NULL); 

	
	t_list *empty_str_node = ft_lstnew(ft_strdup(""));
	assert(empty_str_node); 
	assert(strcmp((char *)empty_str_node->content, "") == 0); 

	
	ft_lstclear(&empty_list, del); 
	assert(empty_list == NULL); 
	print_list(empty_list);

	
	t_list *empty_list2 = NULL;
	assert(ft_lstsize(empty_list2) == 0); 

	
	t_list *last_of_empty = ft_lstlast(empty_list2);
	assert(last_of_empty == NULL); 

	
	ft_lstiter(empty_list2, f); 
	ft_lstmap(empty_list2, f2, del); 

	
	ft_lstclear(&empty_list2, del); 
	assert(empty_list2 == NULL); 

	
	t_list *long_str_node = ft_lstnew(ft_strdup("Hello\x01World"));
	assert(long_str_node); 
	assert(strcmp((char *)long_str_node->content, "Hello\x01World") == 0); 
	print_list(long_str_node);

	
	t_list *dup_list = ft_lstnew(ft_strdup("same value"));
	ft_lstadd_back(&dup_list, ft_lstnew(ft_strdup("same value")));
	ft_lstadd_back(&dup_list, ft_lstnew(ft_strdup("same value")));
	assert(ft_lstsize(dup_list) == 3); 
	print_list(dup_list);

	
	ft_lstclear(&dup_list, del);
	assert(dup_list == NULL); 

	
	t_list *null_node = NULL;
	ft_lstdelone(null_node, del); 

	puts("All tests passed successfully!");
	return 0;
}
