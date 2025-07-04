#include <stdio.h>
#include <string.h>
#include "ex00/ft_strcmp.c"
#include "ex01/ft_strncmp.c"
#include "ex02/ft_strcat.c"
#include "ex03/ft_strncat.c"
#include "ex04/ft_strstr.c"
#include "ex05/ft_strlcat.c"

void print_arr(char *arr)
{
    int i = 0;
    while (arr[i])
    {
        printf("%c", arr[i]);
        i++;
    }
}

int	main(void)
{
	printf("testing ex00\n");
	printf("%d", ft_strcmp("cat", "cat"));
	printf("%d", ft_strcmp("Cat", "cat"));
	printf("%d", ft_strcmp("cat", "Cat"));
	printf("%d", ft_strcmp("C", "cat"));
	printf("%d", ft_strcmp("cat", "C"));
	printf("%d", ft_strcmp("", ""));
	printf("\n");
	printf("%d", strcmp("cat", "cat"));
	printf("%d", strcmp("Cat", "cat"));
	printf("%d", strcmp("cat", "Cat"));
	printf("%d", strcmp("C", "cat"));
	printf("%d", strcmp("cat", "C"));

	printf("\ntesting ex01\n");
	printf("%d", ft_strncmp("cat", "cat", 3));
	printf("%d", ft_strncmp("Cat", "cat", 3));
	printf("%d", ft_strncmp("cat", "Cat", 3));
	printf("%d", ft_strncmp("C", "cat", 3));
	printf("%d", ft_strncmp("cat", "C", 3));
	printf("%d", ft_strncmp("", "", 0));
	printf("%d", ft_strncmp("cat", "cAT", 1));
	printf("\n");
	printf("%d", strncmp("cat", "cat", 3));
	printf("%d", strncmp("Cat", "cat", 3));
	printf("%d", strncmp("cat", "Cat", 3));
	printf("%d", strncmp("C", "cat", 3));
	printf("%d", strncmp("cat", "C", 3));
	printf("%d", strncmp("", "", 0));
	printf("%d", strncmp("cat", "cAT", 1));

	printf("\ntesting ex02, should print 000 cat (nothing, not another 0) \n");
	char ex02dest1[] = {48, 48, 48, 0, 48, 48, 48};
	print_arr(ft_strcat(ex02dest1, "cat"));

	printf("\n");
	char ex02dest2[] = {48, 48, 48, 0, 48, 48, 48};
	print_arr(strcat(ex02dest2, "cat"));

	printf("\ntesting ex03, should print 000 cat (nothing, not another 0 or 'nip') \n");
	char ex03dest1[] = {48, 48, 48, 0, 48, 48, 48};
	print_arr(ft_strncat(ex03dest1, "catnip", 3));

	printf("\n");
	char ex03dest2[] = {48, 48, 48, 0, 48, 48, 48};
	print_arr(strncat(ex03dest2, "catnip", 3));

	printf("\ntesting ex04\n");
	char haystack1[] = "nicn..antnip1catcatnip2cat";
	char needle1[] = "nip";
	print_arr(ft_strstr(haystack1, needle1));
	
	printf("\n");
	print_arr(strstr(haystack1, needle1));
	
	char haystack2[] = "1catcatcatcat";
	char needle2[] = "catnip";
	// triggers segmentation fault.
//	print_arr(ft_strstr(haystack2, needle2));	
//	print_arr(strstr(haystack2, needle2));

	printf("\ntesting ex05\n");
	char ex05dest1[] = {48, 48, 48, 0, 48, 48, 48};
	int i = ft_strlcat(ex05dest1, "cat", 10);
	printf("%d, %s", i, ex05dest1);

	printf("\n");
//	char ex05dest2[] = {48, 48, 48, 0, 48, 48, 48};
//	print_arr(strlcat(ex02dest2, "cat", 4));

	return (0);
}
