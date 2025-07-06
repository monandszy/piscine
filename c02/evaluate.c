#include <stdio.h>
#include <string.h>
#include "ex00/ft_strcpy.c"
#include "ex01/ft_strncpy.c"
#include "ex02/ft_str_is_alpha.c"
#include "ex03/ft_str_is_numeric.c"
#include "ex04/ft_str_is_lowercase.c"
#include "ex05/ft_str_is_uppercase.c"
#include "ex06/ft_str_is_printable.c"
#include "ex07/ft_strupcase.c"
#include "ex08/ft_strlowcase.c"
#include "ex09/ft_strcapitalize.c"
#include "ex10/ft_strlcpy.c"
#include "ex11/ft_putstr_non_printable.c"
#include "ex12/ft_print_memory.c"

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
	printf("---testing ex00, catnip, catnip---\n");
	char ex00dest1[] = "1234567890";
	char ex00src1[] = "catnip";
	print_arr(ft_strcpy(ex00dest1, ex00src1));  
	printf("\n");

	char ex00dest2[] = "1234567890";
	char ex00src2[] = "catnip";
	print_arr(strcpy(ex00dest2, ex00src2));  

	printf("\n");
	char ex00dest3[] = "";
	char ex00src3[] = "";
	print_arr(strcpy(ex00dest3, ex00src3));

	printf("\n---testing ex01---\n");
	char ex01dest1[] = "1234567890";
	char ex01src1[] = "catnip";
	char ex01dest2[] = "1234567890";
	char ex01src2[] = "catnip";

	print_arr(ft_strncpy(ex01dest1, ex01src1, 9));  
	printf("\n");
	print_arr(strncpy(ex01dest2, ex01src2, 9));
	printf("\n");

	char ex01dest3[] = "1234567890";
	char ex01src3[] = "catnip";
	char ex01dest4[] = "1234567890";
	char ex01src4[] = "catnip";
	print_arr(ft_strncpy(ex01dest3, ex01src3, 3));  
	printf("\n");
	print_arr(strncpy(ex01dest4, ex01src4, 3));

	printf("\n");
	// prints nothing
	char ex01dest5[] = "cat";
	char ex01src5[] = "";
	print_arr(strcpy(ex01dest5, ex01src5));

	printf("\n---testing ex02, expected output, 1, 0 (1 true, 0 false)---\n");
	int i1 = ft_str_is_alpha("qwertyuiopasdfghjklzxcvbnmADWDWUNIFNAIOFNWICWNUVBWAUV");
	int i2 = ft_str_is_alpha("wadADWDz12Z44rwfaf43eaefr32rawf332WFAUFWAUFHI");
	int i3 = ft_str_is_alpha("");
	printf("%d, %d, %d", i1, i2, i3);

	printf("\n---testing ex03, expected output 1, 0 (1 true, 0 false)---\n");
	i1 = ft_str_is_numeric("1234567890");
	i2 = ft_str_is_numeric("1233wmnaiofnaiofn123124");
	i3 = ft_str_is_numeric("");
	printf("%d, %d, %d", i1, i2, i3);

    printf("\n---testing ex04, expected 1, 0 (1 true, 0 false)---\n");
	i1 = ft_str_is_lowercase("qwertyuiopasdfghjklzxcvbnm");
	i2 = ft_str_is_lowercase("wadAWDA1Z244rwfaf43eaefr32rawf332WFAUFWAUFHI");
	i3 = ft_str_is_lowercase("");
	printf("%d, %d, %d", i1, i2, i3);
	
	printf("\n---testing ex05, expected 1, 0 (1 true, 0 false)---\n");
	i1 = ft_str_is_uppercase("AQWERTYUIOOPPPAASDFGHJKLZXCVBNMMZ");
	i2 = ft_str_is_uppercase("AWDAfesfs1Z244rwfaf43eaefr32rawf332WFAUFWAUFHI");
	i3 = ft_str_is_uppercase("");
	printf("%d, %d, %d", i1, i2, i3);

	printf("\n---testing ex06, expected 1, 0 (1 true, 0 false)---\n");
	char non[] = {'d', '1', '!', 31, 12, 34, 12, 1};
	i1 = ft_str_is_printable("dwdadadafwdwadw21355555!!!@$$%^^&&*fafwaf22145y5hvvsvd.wd");
	i2 = ft_str_is_printable(non);
	i3 = ft_str_is_printable("");
	printf("%d, %d, %d", i1, i2, i3);

	char empty[] = "";

	printf("\n---testing ex07, all uppercase---\n");
	char ex07in[] = "abcddwadwADWADWAiD./.,/,,/,/,czzce";
	print_arr(ft_strupcase(ex07in));
	print_arr(ft_strupcase(empty));

	printf("\n---testing ex08, all lowercase---\n");
	char ex08in[] = "nfwonfwifnADIWDOADINfnwaoifAWIFNFWA;';[[";
	print_arr(ft_strlowcase(ex08in));
	print_arr(ft_strlowcase(empty));

	printf("\n---testing ex09, expected capitalized, but not after num---\n");
	char ex09in[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	print_arr(ft_strcapitalize(ex09in));
	print_arr(ft_strcapitalize(empty));

	printf("\n---testing ex10, expected, len of src (cat + \\0) as 6, catnip--\n");
	char ex10dest1[] = "1234567890";
	char ex10src1[] = "catnipin";
	unsigned int i = ft_strlcpy(ex10dest1, ex10src1, 7);
	printf("%d, %s", i, ex10dest1);

/*	char ex10dest2[] = "1234567890";
	char ex10src2[] = "catnipin";
	i = strlcpy(ex10dest2, ex10src2, 7);
	printf("%d, %s", i, ex10dest2); */


	printf("\n---testing ex11, expected \\01 to \\1f,  !\"#...i\n---");
	char inv[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,25 ,26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
	ft_putstr_non_printable(inv);

	printf("\n---testing ex12---\n");
	char c_mem[] = "1234567d\n\n\n\n\n\n\n\n\n\n1294295712502*(@*@#*!@@#890123456abcdefghijklmnouprstwxyzdkawiofjwiaunaunoiuguoigabghbagiuaefsefes32";
	ft_print_memory(c_mem, sizeof(c_mem));
	char c_mem2[] = "";
	ft_print_memory(c_mem2, sizeof(c_mem2));
}
